#include "CavaleiroCorrompido.h"
#include <stdexcept>

CavaleiroCorrompido::CavaleiroCorrompido() : Inimigo{35, 8, 6} {
    Entidade_nome = "Cavaleiro Corrompido";
}

float CavaleiroCorrompido::ataque() const {
    return ataqueBase * ((5 + rand() % 11) / 10.0); // 50% a 150%
}

int CavaleiroCorrompido::Dano_ataque(Entidade& vitima) const {
    try {
        int dano = ataque() - vitima.get_defesaBase();
        if (dano <= 0) throw std::out_of_range("Ataque bloqueado");
        return dano;
    } catch (...) {
        return 0;
    }
}

void CavaleiroCorrompido::receber_dano(int dano) {
    vidaBase = max(0, vidaBase - dano);
}

void CavaleiroCorrompido::buffVida(int vida) { vidaBase += vida; }
void CavaleiroCorrompido::debuffVida(int vida) { vidaBase = max(0, vidaBase - vida); }
void CavaleiroCorrompido::buffDano(int dano) { ataqueBase += dano; }
void CavaleiroCorrompido::debuffDano(int dano) { ataqueBase = max(0, ataqueBase - dano); }
void CavaleiroCorrompido::buffDefesa(int def) { defesaBase += def; }
void CavaleiroCorrompido::debuffDefesa(int def) { defesaBase = max(0, defesaBase - def); }
