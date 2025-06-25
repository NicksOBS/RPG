#ifndef POCAO_DEFESA_GRANDE_H
#define POCAO_DEFESA_GRANDE_H
#include "Pocao.h"
#include "../Entidades/Jogador.h"
class Pocao_defesa_grande : public Pocao{
    public:
        Pocao_defesa_grande() : Pocao{"Pocao de defesa grande", 50, 30}{}; //+50 de defesa, 30 moedas de preço
        string get_pocao_nome()override{ return item_nome;};
        int get_pocao_efeito()override{ return efeito;};
        int get_preco()override{return item_preco;};
        int usar_pocao(Jogador&)override;
};

#endif