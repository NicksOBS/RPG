#include "Esqueleto.h"
#include <stdexcept>
#include "Esqueleto.h"
#include "../Armas/Espada_enferrujada.h"
#include <stdexcept>
Esqueleto::Esqueleto(): Inimigo{10, 4, 2}{//Iniciado como valores de teste (vida, ataque, defesa)
    Entidade_nome = "Esqueleto";
    arma = new Espada_enferrujada();
}

float Esqueleto::ataque()const{
    return ataqueBase * ((2+rand()%11)/10); //BALANCEAR
}

int Esqueleto::Dano_ataque(Entidade& vitima)const{
    try{
    int dano = ataque()+arma->get_dano() - vitima.get_defesaBase();
    if(dano < 0) throw out_of_range("ATAQUE BLOQUEADO\n");//pontos de defesa sao maiores que o dano sofrido
    return dano;
    }
    catch(out_of_range &exce){
        return 0;
    }
}

void Esqueleto::receber_dano(int dano){
    try{
        if(dano >= vidaBase) throw out_of_range("");
        vidaBase -= dano;
    }
    catch(out_of_range &exce){
        vidaBase = 0;
    }
}