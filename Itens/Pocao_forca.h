#ifndef POCAO_FORCA_H
#define POCAO_FORCA_H
#include "Pocao.h"
#include "../Entidades/Jogador.h"
class Pocao_forca : public Pocao{
    public:
        Pocao_forca() : Pocao{"Pocao de forca", 20, 10}{}; //+20 de força, 10 moedas de preço
        string get_pocao_nome()override{ return item_nome;};
        int get_pocao_efeito()override{ return efeito;};
        int get_preco()override{return item_preco;};
        int usar_pocao(Jogador&)override;
};

#endif