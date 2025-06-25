#ifndef GOBLIN_H
#define GOBLIN_H

#include "Inimigo.h"

class Goblin : public Inimigo {
public:
    Goblin();

    float ataque() const override;
    int Dano_ataque(Entidade& vitima) const override;
    void receber_dano(int dano) override;

    // Buffs
    void buffVida(int vida) override;
    void debuffVida(int vida) override;
    void buffDano(int dano) override;
    void debuffDano(int dano) override;
    void buffDefesa(int def) override;
    void debuffDefesa(int def) override;
};

#endif
