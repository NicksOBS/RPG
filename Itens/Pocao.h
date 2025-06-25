#ifndef POCAO_H
#define POCAO_H
#include "Item.h"
#include <string>
class Pocao : public Item{
    protected:
        int efeito;

    public:
        Pocao(string n, int eft, int prc):Item{n, prc}, efeito{eft}{}
        virtual string get_pocao_nome()const = 0;
        virtual int get_pocao_efeito()const = 0;
        virtual int get_pocao_preco()const = 0;
        virtual void usar_pocao() = 0;
};

#endif