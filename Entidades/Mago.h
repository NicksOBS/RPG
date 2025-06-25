#ifndef MAGO_H
#define MAGO_H
#include "../Armas/Arma.h"
#include "Entidade.h"
#include "../Armas/Graveto_do_aprendiz.h"
//funcoes comentadas na superclasse Entidade.h
using namespace std;

class Mago : public Entidade{
    public:
        Mago();
        string get_entidade_nome()const{ return Entidade_nome; }
        int get_vidaBase()const{return vidaBase;}
        int get_defesaBase()const{return defesaBase;}
        int get_ataqueBase()const{return ataqueBase;}
        int get_vidaMaxima()const{return vidaMaxima;}
        string get_armaEquipada_nome()const{return arma->get_nome_arma();}
        void equipar_arma(Arma* eqp)override{arma = eqp;}
        float ataque()const;
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