#ifndef POCAO_VIDA_H
#define POCAO_VIDA_H
#include "Pocao.h"
#include "../Entidades/Jogador.h"
class Pocao_vida : public Pocao{
    public:
        Pocao_vida() : Pocao{"Pocao de vida", 20, 10}{}; //+20 de vida, 10 moedas de preço
        string get_pocao_nome()override{ return item_nome;};
        int get_pocao_efeito()override{ return efeito;};
        int get_preco()override{return item_preco;};
        int usar_pocao(Jogador&)override;
};

#endif