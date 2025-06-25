#ifndef POCAO_DEFESA_H
#define POCAO_DEFESA_H
#include "Pocao.h"
#include "../Entidades/Jogador.h"
class Pocao_defesa : public Pocao{
    public:
        Pocao_defesa() : Pocao{"Pocao de defesa", 20, 10}{}; //+20 de defesa, 10 moedas de preço
        string get_pocao_nome()override{ return item_nome;}
        int get_pocao_efeito()override{ return efeito;};
        int get_preco()override{return item_preco;};
        int usar_pocao(Jogador&)override;
};

#endif