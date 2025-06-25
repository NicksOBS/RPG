#include "Pocao_defesa.h"

int Pocao_defesa::usar_pocao(Jogador& player){
    int antesdoEfeito = player.get_jogador_classe()->get_defesaBase();
    player.get_jogador_classe()->buffDefesa(get_pocao_efeito());
    return antesdoEfeito;
}