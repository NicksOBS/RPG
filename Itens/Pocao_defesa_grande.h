#ifndef POCAO_DEFESA_GRANDE_H
#define POCAO_DEFESA_GRANDE_H
#include "Pocao.h"
#include "../Entidades/Jogador.h"
class Pocao_defesa_grande : public Pocao{
    public:
        Pocao_defesa_grande() : Pocao{"Pocao de defesa grande", 50, 30}{}; //+50 de defesa, 30 moedas de preço
        string get_pocao_nome()const{ return item_nome;};
        int get_pocao_efeito()const{ return efeito;};
        int get_pocao_preco()const{return item_preco;};
        void usar_pocao(Jogador& player){player.get_jogador_classe()->buffDefesa(get_pocao_efeito());};
};

#endif POCAO_DEFESA_GRANDE_H