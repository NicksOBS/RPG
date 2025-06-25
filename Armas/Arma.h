#ifndef ARMA_H
#define ARMA_H
#include <string>
#include "../Itens/Item.h"

enum EntidadePermitida{MAGO, GUERREIRO, NADA};

class Arma : public Item{
    protected:
        int Arma_dano;
        EntidadePermitida EntiPerm;
    public: 
        Arma(string n, int d, int prc) : Item{n, prc}, Arma_dano{d}{}
        virtual int get_dano()const = 0;
        virtual int get_preco()const = 0;
        string get_nome_arma()const{return get_item_nome();}
};

#endif          