#include "Inimigo.h"
#include <stdexcept>

float Inimigo::ataque() const {
    return ataqueBase * ((20 + rand() % 101) / 100.0f); // entre 20% e 100% do ataqueBase
}

int Inimigo::Dano_ataque(Entidade& vitima) const {
    try {
        int dano = ataque() + arma->get_dano() - vitima.get_defesaBase();
        if (dano <= 0) throw std::out_of_range("Ataque bloqueado");
        return dano;
    } catch (...) {
        return 0;
    }
}

void Inimigo::receber_dano(int dano) {
    vidaBase -= dano;
    if (vidaBase < 0) vidaBase = 0;
}

void Inimigo::buffVida(int vida) {
    vidaBase += vida;
}

void Inimigo::debuffVida(int vida) {
    vidaBase -= vida;
    if (vidaBase < 0) vidaBase = 0;
}

void Inimigo::buffDano(int dano) {
    ataqueBase += dano;
}

void Inimigo::debuffDano(int dano) {
    ataqueBase -= dano;
    if (ataqueBase < 0) ataqueBase = 0;
}

void Inimigo::buffDefesa(int def) {
    defesaBase += def;
}

void Inimigo::debuffDefesa(int def) {
    defesaBase -= def;
    if (defesaBase < 0) defesaBase = 0;
}
