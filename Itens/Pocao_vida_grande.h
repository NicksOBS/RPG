#ifndef POCAO_VIDA_GRANDE_H
#define POCAO_VIDA_GRANDE_H
#include "Pocao.h"
#include "../Entidades/Jogador.h"
class Pocao_vida_grande : public Pocao{
    public:
        Pocao_vida_grande() : Pocao{"Pocao de vida", 40, 60}{}; //+40 de vida, 60 moedas de preço
        string get_pocao_nome()const{ return item_nome;};
        int get_pocao_efeito()const{ return efeito;};
        int get_pocao_preco()const{return item_preco;};
        void usar_pocao(Jogador&);
};

#endif POCAO_VIDA_GRANDE_H