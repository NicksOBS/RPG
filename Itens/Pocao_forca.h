#ifndef POCAO_FORCA_H
#define POCAO_FORCA_H
#include "Pocao.h"
#include "../Entidades/Jogador.h"
class Pocao_forca : public Pocao{
    public:
        Pocao_forca() : Pocao{"Pocao de forca", 20, 10}{}; //+20 de força, 10 moedas de preço
        string get_pocao_nome()const{ return item_nome;};
        int get_pocao_efeito()const{ return efeito;};
        int get_pocao_preco()const{return item_preco;};
        void usar_pocao(Jogador& player){player.get_jogador_classe()->buffDano(get_pocao_efeito());};
};

#endif POCAO_FORCA_H