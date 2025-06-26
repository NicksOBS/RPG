#include "Mago.h"
#include <stdexcept>
#include <iostream>
using namespace std;

Mago::Mago(): Entidade{50, 19, 10}{ //vida, ataque, defesa
    Entidade_nome = "Mago";
    arma = new Graveto_do_aprendiz();
    entidade_tipo = MAGO;
}

float Mago::ataque()const{ //Mago pode dar entre 50 e 130% de seu dano base
    return ataqueBase *((50+(rand()%101))/100.0f);
}

int Mago::Dano_ataque(Entidade& vitima)const{
    try{
    int dano = ataque()+arma->get_dano() - vitima.get_defesaBase();
    if(dano < 0) throw out_of_range("ATAQUE BLOQUEADO\n");//pontos de defesa sao maiores que o dano sofrido
    return dano;
    }
    catch(out_of_range &exce){
        return 0;
    }
}

void Mago::receber_dano(int dano){
    try{
        if(dano >= vidaBase) throw out_of_range("");
        vidaBase -= dano;
    }
    catch(out_of_range &exce){
        vidaBase = 0;
    }
}