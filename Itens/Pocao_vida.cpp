#include "Pocao_vida.h"

void Pocao_vida::usar_pocao(Jogador& player){
    if((player.get_jogador_classe()->get_vidaBase()+get_pocao_efeito()) >= player.get_jogador_classe()->get_vidaMaxima())
        player.get_jogador_classe()->buffVida(player.get_jogador_classe()->get_vidaMaxima() - player.get_jogador_classe()->get_vidaBase());
    else 
        player.get_jogador_classe()->buffVida(get_pocao_efeito());
}