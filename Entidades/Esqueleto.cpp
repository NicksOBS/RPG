#include "Esqueleto.h"
#include <stdexcept>
#include "Esqueleto.h"
#include "../Armas/ArmaNULL.h"
#include <stdexcept>
Esqueleto::Esqueleto(): Inimigo{10, 4, 2}{//Iniciado como valores de teste (vida, ataque, defesa)
    Entidade_nome = "Esqueleto";
    arma = new ArmaNULL();
}

float Esqueleto::ataque()const{
    return ataqueBase * ((60+rand()%101)/100.f); //BALANCEAR
}

int Esqueleto::Dano_ataque(Entidade& vitima)const{
    try{
    int dano = ataque()+arma->get_dano() - vitima.get_defesaBase();
    if(dano <= 0) throw out_of_range("ATAQUE BLOQUEADO\n");//pontos de defesa sao maiores que o dano sofrido
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