/*#ifndef DUNGEON_DIFICIL_H
#define DUNGEON_DIFICIL_H
#include "Dungeon.h"

class DungeonDificil : public Dungeon{
    public:
        DungeonDificil(); 
        ~DungeonDificil(){ delete adversario; };
        float get_dungeon_recompensa();
        void dungeon_finalizar(){ idas--; multiplicador/=2;};
        Entidade* dungeon_get_inimigo(){ return adversario;};
        int dungeon_get_idas(){ return idas; };
        Inimigo* get_adversario(){return adversario;};
};
#endif*/

#ifndef DUNGEON_NORMAL_H
#define DUNGEON_NORMAL_H

#include "Dungeon.h"
#include "Sala.h"
#include "../Entidades/Esqueleto.h"
#include "../Entidades/Zumbi.h"
#include "../Entidades/Goblin.h"
#include "../Entidades/LordeDasSombras.h"

class DungeonDificil : public Dungeon {
private:
    Sala* salaAtual;
    Sala* salaInicial;

public:
    DungeonDificil() {
        tipo = DIFICIL; 
        recompensa = 60.0; //valores a serem estudados
        idas = 3; 
        multiplicador = 1.0;
        criar_salas();
    }

    ~DungeonDificil() {
        delete salaInicial;
    }

    void criar_salas() {
        Sala* inicio = new Sala("Portão da Perdição");
        Sala* sala1 = new Sala("Antiga Biblioteca Profanada");
        Sala* sala2 = new Sala("Corredor do Culto Sombrio");
        Sala* sala3 = new Sala("Câmara de Ossos Eternos");
        Sala* sala4 = new Sala("Sala da Escuridão Abissal");
        Sala* sala5 = new Sala("Ninho dos Hereges");
        Sala* salaChefe = new Sala("Altar do Fim dos Tempos");

        sala1->inimigo = new Esqueleto();
        sala2->inimigo = new Zumbi();
        sala3->inimigo = new Goblin();
        sala4->inimigo = new Esqueleto();
        sala5->inimigo = new Zumbi();
        salaChefe->inimigo = new LordeDasSombras();
        salaChefe->temChefe = true;

        inicio->caminhos = {sala1, sala2};
        sala1->caminhos = {sala3};
        sala2->caminhos = {sala4};
        sala3->caminhos = {sala5};
        sala4->caminhos = {sala5};
        sala5->caminhos = {salaChefe};

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
            cout << "Escolha inválida!\n";
        }
    }

    bool dungeon_concluida() const {
        return salaAtual->temChefe && salaAtual->inimigo == nullptr;
    }

    void resetar() {
        delete salaInicial;
        criar_salas();
    }
};

#endif
#ifndef DUNGEON_NORMAL_H
#define DUNGEON_NORMAL_H

#include "Dungeon.h"
#include "Sala.h"
#include "../Entidades/Esqueleto.h"
#include "../Entidades/Zumbi.h"
#include "../Entidades/Goblin.h"
#include "../Entidades/LordeDasSombras.h"

class DungeonDificil : public Dungeon {
private:
    Sala* salaAtual;
    Sala* salaInicial;

public:
    DungeonDificil() {
        criar_salas();
    }

    ~DungeonDificil() {
        delete salaInicial;
    }

    void criar_salas() {
        Sala* inicio = new Sala("Portão da Perdição");
        Sala* sala1 = new Sala("Antiga Biblioteca Profanada");
        Sala* sala2 = new Sala("Corredor do Culto Sombrio");
        Sala* sala3 = new Sala("Câmara de Ossos Eternos");
        Sala* sala4 = new Sala("Sala da Escuridão Abissal");
        Sala* sala5 = new Sala("Ninho dos Hereges");
        Sala* salaChefe = new Sala("Altar do Fim dos Tempos");

        sala1->inimigo = new Esqueleto();
        sala2->inimigo = new Zumbi();
        sala3->inimigo = new Goblin();
        sala4->inimigo = new Zumbi();
        sala5->inimigo = new Esqueleto();
        salaChefe->inimigo = new LordeDasSombras();
        salaChefe->temChefe = true;

        inicio->caminhos = {sala1, sala2};
        sala1->caminhos = {sala3};
        sala2->caminhos = {sala4};
        sala3->caminhos = {sala5};
        sala4->caminhos = {sala5};
        sala5->caminhos = {salaChefe};

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
            cout << "Escolha inválida!\n";
        }
    }

    bool dungeon_concluida() const {
        return salaAtual->temChefe && salaAtual->inimigo == nullptr;
    }

    void resetar() {
        delete salaInicial;
        criar_salas();
    }
};

#endif
