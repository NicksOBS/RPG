#ifndef POCAO_FORCA_GRANDE_H
#define POCAO_FORCA_GRANDE_H
#include "Pocao.h"
#include "../Entidades/Jogador.h"
class Pocao_forca_grande : public Pocao{
    public:
        Pocao_forca_grande() : Pocao{"Pocao de forca grande", 50, 40}{}; //+50 de força, 40 moedas de preço
        string get_pocao_nome()override{ return item_nome;};
        int get_pocao_efeito()override{ return efeito;};
        int get_preco()override{return item_preco;};
        int usar_pocao(Jogador&)override;
};

#endif