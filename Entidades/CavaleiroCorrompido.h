#ifndef CAVALEIROCORROMPIDO_H
#define CAVALEIROCORROMPIDO_H

#include "Inimigo.h"

class CavaleiroCorrompido : public Inimigo {
public:
    CavaleiroCorrompido();

    int ataque() const override;
    int Dano_ataque(Entidade& vitima) const override;
    void receber_dano(int dano) override;

    void buffVida(int vida) override;
    void debuffVida(int vida) override;
    void buffDano(int dano) override;
    void debuffDano(int dano) override;
    void buffDefesa(int def) override;
    void debuffDefesa(int def) override;
};

#endif
