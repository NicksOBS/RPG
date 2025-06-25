#ifndef JOGADOR_H
#define JOGADOR_H
#include "../Armas/Arma.h"
#include <string.h>
#include <iostream>
#include "../Outros/Inventario.h"
#include "Entidade.h"
#include "../Itens/Item.h"

using namespace std;

class Jogador{
    private:
        string jogador_nome;
        Entidade *classe = nullptr;
        Inventario mochila;
        int dinheiro;

    public:
        friend class Inventario;
        Jogador(string n, Entidade* cl) : jogador_nome{n}, classe{cl}, dinheiro{0}{}
        ~Jogador(){ delete classe;}

        string get_jogador_nome()const{ return jogador_nome; }
        Entidade* get_jogador_classe()const{ return classe; }
        string get_jogador_classe_nome()const{ return classe->get_entidade_nome(); }
        int get_jogador_dinheiro()const{ return dinheiro; }
        void set_jogador_dinheiro(int valor){ dinheiro += valor; }
        bool mochila_vazia()const{ return mochila.inventario_vazio();}
        bool mochila_remover(Item& item){ mochila.item_remover(item); }
        bool mochila_inserir(Item& item){ return mochila.item_inserir(item); }
        bool mochila_cheia()const{ return mochila.inventario_cheio();}
        void mochila_mostrar(){ mochila.inventario_mostrar(); }
};

#endif