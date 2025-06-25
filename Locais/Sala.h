#ifndef SALA_H
#define SALA_H

#include <string>
#include <vector>
#include "../Entidades/Inimigo.h"

using namespace std;

class Sala {
public:
    string descricao;
    vector<Sala*> caminhos;   // Conexões (esquerda, direita, meio, etc.)
    Inimigo* inimigo = nullptr;
    bool temTesouro = false;
    bool temChefe = false;

    Sala(string desc) : descricao(desc) {}

    ~Sala() {
        delete inimigo;
        for (auto& caminho : caminhos) {
            delete caminho;
        }
    }

    void mostrar_opcoes() const {
        cout << descricao << "\n";
        for (size_t i = 0; i < caminhos.size(); i++) {
            cout << i + 1 << ". Ir para " << caminhos[i]->descricao << "\n";
        }
    }
};

#endif
