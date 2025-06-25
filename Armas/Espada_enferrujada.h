#ifndef ESPADA_ENFERRUJADA_H
#define ESPADA_ENFERRUJADA_H
#include "../Itens/Item.h"

class Espada_enferrujada : public Arma{
    public:
        Espada_enferrujada() : Arma{"Espada Enferrujada", 8, 4}{EntiPerm = GUERREIRO;} //dano a ser estudado (8 de dano e 4 dinheiros)
        int get_dano( )const {return Arma_dano;};
        int get_preco() const {return item_preco;};
        string get_arma_nome() const {return get_item_nome();}
};
#endif