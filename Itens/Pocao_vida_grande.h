#ifndef POCAO_VIDA_GRANDE_H
#define POCAO_VIDA_GRANDE_H
#include "Pocao.h"
#include "../Entidades/Jogador.h"
class Pocao_vida_grande : public Pocao{
    public:
        Pocao_vida_grande() : Pocao{"Pocao de vida grande", 40, 60}{}; //+40 de vida, 60 moedas de preço
        string get_pocao_nome()override{ return item_nome;};
        int get_pocao_efeito()override{ return efeito;};
        int get_preco()override{return item_preco;};
        int usar_pocao(Jogador&)override;
};

#endif