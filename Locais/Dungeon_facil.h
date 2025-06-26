#ifndef DUNGEON_FACIL_H
#define DUNGEON_FACIL_H

#include "Dungeon.h"
#include "Sala.h"
#include "../Entidades/Goblin.h"
#include "../Entidades/ReiRato.h"
#include <vector>
using namespace std;

class DungeonFacil : public Dungeon {
private:
    Sala* salaAtual;
    Sala* salaInicial;
    vector<Sala*> salas; // Controle de salas para destruição segura

public:
    DungeonFacil() {
        tipo = FACIL; 
        recompensa = 20.0; //valores a serem estudados
        idas = 3; 
        multiplicador = 1.0;
        criar_salas();
    }

    ~DungeonFacil() {
        for (Sala* s : salas) {
            delete s;
        }
    }

    void criar_salas() {
        // Criando salas
        Sala* inicio = new Sala("Entrada do Esgoto"); salas.push_back(inicio);
        Sala* sala1 = new Sala("Corredor Escuro"); salas.push_back(sala1);
        Sala* sala2 = new Sala("Sala com Cheiro de Mofo"); salas.push_back(sala2);
        Sala* sala3 = new Sala("Sala Iluminada por tochas"); salas.push_back(sala3);
        Sala* salaChefe = new Sala("Camara do Chefe"); salas.push_back(salaChefe);

        // Atribuindo inimigos
        sala1->inimigo = new Goblin();
        sala2->inimigo = new Goblin();
        sala3->inimigo = new Goblin();
        salaChefe->inimigo = new ReiRato();

        salaChefe->temChefe = true;

        // Conectando salas
        inicio->caminhos = {sala1, sala2};
        sala1->caminhos = {sala3};
        sala2->caminhos = {sala3};
        sala3->caminhos = {salaChefe};

        salaInicial = inicio;
        salaAtual = inicio;
    }

    Sala* get_sala_atual() const {
        return salaAtual;
    }

    void mover_para_sala(int escolha) {
        if (escolha >= 1 && escolha <= salaAtual->caminhos.size()) {
            salaAtual = salaAtual->caminhos[escolha - 1];
        } else {
            cout << "Escolha invalida!\n";
        }
    }

    bool dungeon_concluida() const {
        return salaAtual->temChefe && salaAtual->inimigo == nullptr;
    }

    void resetar() {
        for (Sala* s : salas) {
            delete s;
        }
        salas.clear();
        criar_salas();
    }

    // Implementações obrigatórias da classe Dungeon
    float get_dungeon_recompensa() const override {
        return recompensa * multiplicador;
    }

    void dungeon_finalizar() override {
        idas--;
        multiplicador /= 2;
    }

    Entidade* dungeon_get_inimigo() const override {
        return salaAtual->inimigo;
    }

    int dungeon_get_idas() const override {
        return idas;
    }

    Inimigo* get_adversario() const override {
        return salaAtual->inimigo;
    }
};

#endif

