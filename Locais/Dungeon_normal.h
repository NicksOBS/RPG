#ifndef DUNGEON_NORMAL_H
#define DUNGEON_NORMAL_H

#include "Dungeon.h"
#include "Sala.h"
#include "../Entidades/Esqueleto.h"
#include "../Entidades/Zumbi.h"
#include "../Entidades/CavaleiroCorrompido.h"
#include <vector>
using namespace std;

class DungeonNormal : public Dungeon {
private:
    Sala* salaAtual;
    Sala* salaInicial;
    vector<Sala*> salas; // Controle de salas para destruição segura

public:
    DungeonNormal() {
        tipo = NORMAL;
        recompensa = 40.0;
        idas = 2;
        multiplicador = 1.0;
        criar_salas();
    }

    ~DungeonNormal() {
        for (Sala* s : salas) {
            delete s;
        }
    }

    void criar_salas() {
        Sala* inicio = new Sala("Entrada da Catacumba"); salas.push_back(inicio);
        Sala* sala1 = new Sala("Corredor dos Lamentos"); salas.push_back(sala1);
        Sala* sala2 = new Sala("Sala das Sombras"); salas.push_back(sala2);
        Sala* sala3 = new Sala("Cripta Abandonada"); salas.push_back(sala3);
        Sala* salaChefe = new Sala("mausoleu do caido"); salas.push_back(salaChefe);

        sala1->inimigo = new Zumbi();
        sala2->inimigo = new Zumbi();
        sala3->inimigo = new Zumbi();
        salaChefe->inimigo = new CavaleiroCorrompido();

        salaChefe->temChefe = true;

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