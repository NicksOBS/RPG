#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <vector>
#include "../Itens/Item.h"
#include <iostream>

using namespace std;

#define MAX 10 //espaço maximo da mochila/inventario

class Inventario{
    private:
        vector <Item*> mochila;

    public:
        Inventario(){ mochila.reserve(MAX); };
        ~Inventario() { for (auto item : mochila) delete item; };

        bool inventario_vazio()const{ return mochila.empty();};
        bool inventario_cheio()const{ return mochila.size() >= MAX; };
        int get_inventario_espaco()const{ return mochila.capacity() ;};
        bool item_inserir(Item&);
        bool item_remover(Item&);
        void inventario_mostrar();
        int obter_tamanho_inventario() const { return mochila.size(); } // Retorna o número de itens
        Item* obter_item(int indice) { // Permite acessar um item pelo seu índice
            if (indice >= 0 && indice < mochila.size()) {
                return mochila[indice];
            }
            return nullptr; 
        }

};

#endif