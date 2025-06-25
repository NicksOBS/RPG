#include "Dungeon_facil.h"

DungeonFacil::DungeonFacil(){
    tipo = FACIL; 
    recompensa = 20.0; //valores a serem estudados
    idas = 3; 
    multiplicador = 1.0;
    //adversario = new{}; pensar em um inimigo
} 

float DungeonFacil::get_dungeon_recompensa(){
    return recompensa*multiplicador;
}
