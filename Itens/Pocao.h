#ifndef POCAO_H
#define POCAO_H
#include "Item.h"
#include <string>
#include "..\Entidades\Jogador.h"
class Pocao : public Item{
    protected:
        int efeito;

    public:
        Pocao(string n, int eft, int prc):Item{n, prc}, efeito{eft}{}
        virtual string get_pocao_nome() = 0;
        virtual int get_pocao_efeito() = 0;
        virtual int get_preco(){ return item_preco;};
        virtual int usar_pocao(Jogador&) = 0;
};

#endif