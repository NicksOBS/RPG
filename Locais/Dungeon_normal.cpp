#include "Dungeon_normal.h"

DungeonNormal::DungeonNormal(){
    tipo = NORMAL; 
    recompensa = 40.0; //valores a serem estudados
    idas = 3; 
    multiplicador = 1.0;
    //adversario = new{}; pensar em um inimigo
} 

float DungeonNormal::get_dungeon_recompensa(){
    return recompensa*multiplicador;
}
