#ifndef ARMANULL_H
#define ARMANULL_H
#include "../Itens/Item.h"
#include "Arma.h"

class ArmaNULL : public Arma{
    public:
        ArmaNULL() : Arma{"ArmaNULL", 0, 0}{EntiPerm = NADA;} //dano a ser estudado (8 de dano e 4 dinheiros)
        int get_dano( )const {return Arma_dano;};
        int get_preco() const {return item_preco;};
        string get_arma_nome() const {return get_item_nome();}
};
#endif