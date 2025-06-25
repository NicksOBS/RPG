/*#ifndef DUNGEON_NORMAL_H
#define DUNGEON_NORMAL_H
#include "Dungeon.h"

class DungeonNormal : public Dungeon{
    public:
        DungeonNormal(); 
        ~DungeonNormal(){ delete adversario; };
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
#include "../Entidades/CavaleiroCorrompido.h"


class DungeonNormal : public Dungeon {
private:
    Sala* salaAtual;
    Sala* salaInicial;

public:
    DungeonNormal() {
        tipo = NORMAL; 
        recompensa = 40.0; //valores a serem estudados
        idas = 3; 
        multiplicador = 1.0;
        criar_salas();
    }

    ~DungeonNormal() {
        delete salaInicial;
    }

    void criar_salas() {
        Sala* inicio = new Sala("Entrada das Catacumbas");
        Sala* sala1 = new Sala("Galeria de Ossos");
        Sala* sala2 = new Sala("Caminho Enlameado");
        Sala* sala3 = new Sala("Santuário Abandonado");
        Sala* sala4 = new Sala("Salão das Almas Perdidas");
        Sala* salaChefe = new Sala("Trono Esquecido");

        sala1->inimigo = new Zumbi();
        sala2->inimigo = new Esqueleto();
        sala3->inimigo = new Esqueleto();
        sala4->inimigo = new Zumbi();
        salaChefe->inimigo = new CavaleiroCorrompido(); //Chefe 2
        salaChefe->temChefe = true;

        inicio->caminhos = {sala1, sala2};
        sala1->caminhos = {sala3};
        sala2->caminhos = {sala4};
        sala3->caminhos = {salaChefe};
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
