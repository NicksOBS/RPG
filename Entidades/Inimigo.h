/*#ifndef INIMIGO_H
#define INIMIGO_H
#include "Entidade.h"

using namespace std;

class Inimigo : public Entidade{
    public:
        Inimigo(int v, int atq, int def) : Entidade{v, atq, def}{srand(time(NULL));}
        virtual ~Inimigo(){}
        string get_entidade_nome()const{ return Entidade_nome; }
        int get_vidaBase()const{return vidaBase;}
        int get_defesaBase()const{return defesaBase;}
        int get_ataqueBase()const{return ataqueBase;}
        string get_armaEquipada_nome()const{return arma->get_nome_arma();}
        int ataque()const;
        int Dano_ataque(Entidade&)const;
};

#endif*/

#ifndef INIMIGO_H
#define INIMIGO_H

#include "Entidade.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Inimigo : public Entidade {
public:
    Inimigo(int v, int atq, int def) : Entidade{v, atq, def} {
        Entidade_nome = "Inimigo";
        srand(time(NULL));
    }

    virtual ~Inimigo() = default;

    // Implementação dos métodos obrigatórios
    float ataque() const override;
    int Dano_ataque(Entidade&) const override;
    void receber_dano(int dano) override;
    void buffVida(int vida) override;
    void debuffVida(int vida) override;
    void buffDano(int dano) override;
    void debuffDano(int dano) override;
    void buffDefesa(int def) override;
    void debuffDefesa(int def) override;
};

#endif
