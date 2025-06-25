#ifndef POCAO_VIDA_H
#define POCAO_VIDA_H
#include "Pocao.h"
#include "../Entidades/Jogador.h"
class Pocao_vida : public Pocao{
    public:
        Pocao_vida() : Pocao{"Pocao de vida", 20, 10}{}; //+20 de vida, 10 moedas de preço
        string get_pocao_nome()const{ return item_nome;};
        int get_pocao_efeito()const{ return efeito;};
        int get_pocao_preco()const{return item_preco;};
        void usar_pocao(Jogador&);
};

#endif POCAO_VIDA_H