#include "Zumbi.h"
#include <stdexcept>

Zumbi::Zumbi() : Inimigo{15, 3, 5} { // Vida alta, defesa alta, ataque baixo
    Entidade_nome = "Zumbi";
    // arma = new ... (se quiser criar uma arma específica depois)
}

int Zumbi::ataque() const {
    return ataqueBase * ((3 + rand() % 9) / 10.0); // Entre 30% e 90%
}

int Zumbi::Dano_ataque(Entidade& vitima) const {
    try {
        int dano = ataque() + arma->get_dano() - vitima.get_defesaBase();
        if (dano < 0) throw std::out_of_range("Ataque bloqueado");
        return dano;
    } catch (...) {
        return 0;
    }
}

void Zumbi::receber_dano(int dano) {
    vidaBase = max(0, vidaBase - dano);
}

// Buffs e debuffs
void Zumbi::buffVida(int vida) { vidaBase += vida; }
void Zumbi::debuffVida(int vida) { vidaBase = max(0, vidaBase - vida); }
void Zumbi::buffDano(int dano) { ataqueBase += dano; }
void Zumbi::debuffDano(int dano) { ataqueBase = max(0, ataqueBase - dano); }
void Zumbi::buffDefesa(int def) { defesaBase += def; }
void Zumbi::debuffDefesa(int def) { defesaBase = max(0, defesaBase - def); }
