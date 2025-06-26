#include "Guerreiro.h"
#include <stdexcept>

using namespace std;

Guerreiro::Guerreiro(): Entidade{60, 16, 10}{ //60 de vida, 16 de atq e 4SS5 de def
    Entidade_nome = "Guerreiro";
    arma = new Espada_enferrujada();
    entidade_tipo = GUERREIRO;
}

float Guerreiro::ataque()const{
    return ataqueBase * ((20+rand()%101)/100.0f); //Guerreiro pode dar entre 20 e 110% de seu dano base
}

int Guerreiro::Dano_ataque(Entidade& vitima)const{
    try{
    int dano = ataque()+arma->get_dano() - vitima.get_defesaBase();
    if(dano <= 0) throw out_of_range("ATAQUE BLOQUEADO\n"); //pontos de defesa sao maiores que o dano sofrido
    return dano;
    }
    catch(out_of_range &exce){
        return 0;
    }
}

void Guerreiro::receber_dano(int dano){
    try{
        if(dano >= vidaBase) throw out_of_range("");
        vidaBase -= dano;
    }
    catch(out_of_range &exce){
        vidaBase = 0;
    }
}