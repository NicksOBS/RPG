/*#ifndef DUNGEON_FACIL_H
#define DUNGEON_FACIL_H
#include "Dungeon.h"

class DungeonFacil : public Dungeon{
    public:
        DungeonFacil();  
        ~DungeonFacil(){ delete adversario; };
        float get_dungeon_recompensa();
        void dungeon_finalizar(){ idas--; multiplicador/=2;};
        Entidade* dungeon_get_inimigo(){ return adversario;};
        int dungeon_get_idas(){ return idas; }
        Inimigo* get_adversario(){return adversario;};
};
#endif*/

#ifndef DUNGEON_FACIL_H
#define DUNGEON_FACIL_H

#include "Dungeon.h"
#include "Sala.h"
#include "../Entidades/Goblin.h"
#include "../Entidades/ReiRato.h"

class DungeonFacil : public Dungeon {
private:
    Sala* salaAtual;
    Sala* salaInicial;

public:
    DungeonFacil() {
        tipo = FACIL; 
        recompensa = 20.0; //valores a serem estudados
        idas = 3; 
        multiplicador = 1.0;
        criar_salas();
    }

    ~DungeonFacil() {
        delete salaInicial;
    }

    void criar_salas() {
        // Criando salas
        Sala* inicio = new Sala("Entrada do Esgoto");
        Sala* sala1 = new Sala("Corredor Escuro");
        Sala* sala2 = new Sala("Sala com Cheiro de Mofo");
        Sala* sala3 = new Sala("Sala Iluminada por tochas");
        Sala* salaChefe = new Sala("Câmara do Chefe");

        // Atribuindo inimigos
        sala1->inimigo = new Goblin();
        sala2->inimigo = new Goblin();
        sala3->inimigo = new Goblin();
        salaChefe->inimigo = new ReiRato(); // PrimeiroBoss

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
