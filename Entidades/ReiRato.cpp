#include "ReiRato.h"
#include <stdexcept>

ReiRato::ReiRato() : Inimigo{20, 5, 4} {
    Entidade_nome = "Rei Rato";
}

int ReiRato::ataque() const {
    return ataqueBase * ((4 + rand() % 9) / 10.0); // 40% a 120%
}

int ReiRato::Dano_ataque(Entidade& vitima) const {
    try {
        int dano = ataque() - vitima.get_defesaBase();
        if (dano < 0) throw std::out_of_range("Ataque bloqueado");
        return dano;
    } catch (...) {
        return 0;
    }
}

void ReiRato::receber_dano(int dano) {
    vidaBase = max(0, vidaBase - dano);
}

void ReiRato::buffVida(int vida) { vidaBase += vida; }
void ReiRato::debuffVida(int vida) { vidaBase = max(0, vidaBase - vida); }
void ReiRato::buffDano(int dano) { ataqueBase += dano; }
void ReiRato::debuffDano(int dano) { ataqueBase = max(0, ataqueBase - dano); }
void ReiRato::buffDefesa(int def) { defesaBase += def; }
void ReiRato::debuffDefesa(int def) { defesaBase = max(0, defesaBase - def); }
