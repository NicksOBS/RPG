#include "Goblin.h"
#include <stdexcept>
#include "../Armas/ArmaNULL.h"

Goblin::Goblin() : Inimigo{8, 6, 2} { // Vida baixa, ataque alto, defesa baixa
    Entidade_nome = "Goblin";
    arma = new ArmaNULL();
}

float Goblin::ataque() const {
    return ataqueBase * 1;//((5 + rand() % 11) / 10.0); // Entre 50% e 150%
}

int Goblin::Dano_ataque(Entidade& vitima) const {
    try {
        int dano = ataque() + arma->get_dano() - vitima.get_defesaBase();
        if (dano < 0) throw std::out_of_range("Ataque bloqueado");
        return dano;
    } catch (...) {
        return 0;
    }
}

void Goblin::receber_dano(int dano) {
    vidaBase = max(0, vidaBase - dano);
}

// Buffs e debuffs
void Goblin::buffVida(int vida) { vidaBase += vida; }
void Goblin::debuffVida(int vida) { vidaBase = max(0, vidaBase - vida); }
void Goblin::buffDano(int dano) { ataqueBase += dano; }
void Goblin::debuffDano(int dano) { ataqueBase = max(0, ataqueBase - dano); }
void Goblin::buffDefesa(int def) { defesaBase += def; }
void Goblin::debuffDefesa(int def) { defesaBase = max(0, defesaBase - def); }
