#include "LordeDasSombras.h"
#include <stdexcept>
#include "../Armas/ArmaNULL.h"
LordeDasSombras::LordeDasSombras() : Inimigo{30, 10, 8} {
    Entidade_nome = "Lorde das Sombras";
    arma = new ArmaNULL();
}

float LordeDasSombras::ataque() const {
    return ataqueBase * ((70 + rand() % 101) / 100.0f); // 70% a 170%
}

int LordeDasSombras::Dano_ataque(Entidade& vitima) const {
    try {
        int dano = ataque() - vitima.get_defesaBase();
        if (dano <= 0) throw std::out_of_range("Ataque bloqueado");
        return dano;
    } catch (...) {
        return 0;
    }
}

void LordeDasSombras::receber_dano(int dano) {
    vidaBase = max(0, vidaBase - dano);
}

void LordeDasSombras::buffVida(int vida) { vidaBase += vida; }
void LordeDasSombras::debuffVida(int vida) { vidaBase = max(0, vidaBase - vida); }
void LordeDasSombras::buffDano(int dano) { ataqueBase += dano; }
void LordeDasSombras::debuffDano(int dano) { ataqueBase = max(0, ataqueBase - dano); }
void LordeDasSombras::buffDefesa(int def) { defesaBase += def; }
void LordeDasSombras::debuffDefesa(int def) { defesaBase = max(0, defesaBase - def); }
