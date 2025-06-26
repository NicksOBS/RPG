#ifndef DUNGEON_DIFICIL_H
#define DUNGEON_DIFICIL_H

#include "Dungeon.h"
#include "Sala.h"
#include "../Entidades/Esqueleto.h"
#include "../Entidades/Zumbi.h"
#include "../Entidades/Goblin.h"
#include "../Entidades/LordeDasSombras.h"
#include <vector>
using namespace std;

class DungeonDificil : public Dungeon {
private:
    Sala* salaAtual;
    Sala* salaInicial;
    vector<Sala*> salas;

public:
    DungeonDificil() {
        tipo = DIFICIL;
        recompensa = 100.0;
        idas = 1;
        multiplicador = 1.5;
        criar_salas();
    }

    ~DungeonDificil() {
        for (Sala* s : salas) {
            delete s;
        }
    }

    void criar_salas() {
        Sala* inicio = new Sala("Entrada da Fortaleza Sombria"); salas.push_back(inicio);
        Sala* sala1 = new Sala("Corredor da Perdição"); salas.push_back(sala1);
        Sala* sala2 = new Sala("Galeria dos Lamentos"); salas.push_back(sala2);
        Sala* sala3 = new Sala("Sala dos Ecos Eternos"); salas.push_back(sala3);
        Sala* sala4 = new Sala("Vestíbulo da Morte"); salas.push_back(sala4);
        Sala* salaChefe = new Sala("Trono do Lorde das Sombras"); salas.push_back(salaChefe);

        sala1->inimigo = new Esqueleto();
        sala2->inimigo = new Zumbi();
        sala3->inimigo = new Goblin();
        sala4->inimigo = new Zumbi();
        salaChefe->inimigo = new LordeDasSombras();
        salaChefe->temChefe = true;

        inicio->caminhos = {sala1};
        sala1->caminhos = {sala2};
        sala2->caminhos = {sala3};
        sala3->caminhos = {sala4};
        sala4->caminhos = {salaChefe};

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

