#ifndef GRAVETO_DO_APRENDIZ_H
#define GRAVETO_DO_APRENDIZ_H
#include "../Itens/Item.h"
#include "../Armas/Arma.h"

class Graveto_do_aprendiz : public Arma{
    public:
        Graveto_do_aprendiz(): Arma{"Graveto do Aprendiz", 3, 3} {EntiPerm = MAGO;}
        int get_dano( )const {return Arma_dano;};
        int get_preco() const {return item_preco;};
        string get_arma_nome()const{return get_item_nome();}
};

#endif