#ifndef ZUMBI_H
#define ZUMBI_H

#include "Inimigo.h"

class Zumbi : public Inimigo {
public:
    Zumbi();

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
