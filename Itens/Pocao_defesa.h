#ifndef POCAO_DEFESA_H
#define POCAO_DEFESA_H
#include "Pocao.h"
#include "../Entidades/Jogador.h"
class Pocao_defesa : public Pocao{
    public:
        Pocao_defesa() : Pocao{"Pocao de defesa", 20, 10}{}; //+20 de defesa, 10 moedas de preço
        string get_pocao_nome()const{ return item_nome;};
        int get_pocao_efeito()const{ return efeito;};
        int get_pocao_preco()const{return item_preco;};
        void usar_pocao(Jogador& player){player.get_jogador_classe()->buffDefesa(get_pocao_efeito());};
};

#endif POCAO_DEFESA_H