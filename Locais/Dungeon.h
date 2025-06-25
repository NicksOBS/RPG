#ifndef DUNGEON_H
#define DUNGEON_H
#include "../Entidades/Inimigo.h"
enum DungeonTipo { FACIL, NORMAL, DIFICIL };

class Dungeon{
    protected:
        int idas;
        float multiplicador;
        float recompensa;
        DungeonTipo tipo;
        Inimigo *adversario;

    public:
        Dungeon(){};
        virtual ~Dungeon(){delete adversario;};
        virtual float get_dungeon_recompensa()const = 0;
        virtual void dungeon_finalizar() = 0;
        virtual Entidade* dungeon_get_inimigo()const = 0;
        virtual int dungeon_get_idas()const = 0;
        virtual Inimigo* get_adversario()const = 0;
};

#endif