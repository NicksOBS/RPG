#ifndef GUERREIRO_H
#define GUERREIRO_H
#include "Entidade.h"
#include "../Armas/Arma.h"
#include "../Armas/Espada_enferrujada.h"
//funcoes comentadas na superclasse Entidade.h
class Guerreiro : public Entidade{
    public:
        Guerreiro();
        string get_entidade_nome()const{ return Entidade_nome; }
        int get_vidaBase()const{return vidaBase;}
        int get_defesaBase()const{return defesaBase;}
        int get_ataqueBase()const{return ataqueBase;}
        string get_armaEquipada_nome()const{return arma->get_nome_arma();}
        void equipar_arma(Arma* eqp)override{arma = eqp;}
        int ataque()const;
        int Dano_ataque(Entidade&)const;
        void receber_dano(int)override;
        void buffVida(int vida)override{ vidaBase += vida;};
        void debuffVida(int vida) override{ vidaBase -= vida;};
        void buffDano(int dano) override{ ataqueBase += dano;};
        void debuffDano(int dano) override{ ataqueBase -= dano;};
        void buffDefesa(int def) override{ defesaBase += def;};
        void debuffDefesa(int def) override{ defesaBase -=def;};
};

#endif