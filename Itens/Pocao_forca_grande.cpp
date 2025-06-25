#include "Pocao_forca_grande.h"

int Pocao_forca_grande::usar_pocao(Jogador& player){
    int antesdoEfeito = player.get_jogador_classe()->get_ataqueBase();
    player.get_jogador_classe()->buffDano(get_pocao_efeito());
    return antesdoEfeito;
}