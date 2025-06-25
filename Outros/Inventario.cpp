#include "Inventario.h"
#include <iostream>
using namespace std;

bool Inventario::item_inserir(Item& item){
    if(inventario_cheio()) return false;
    else {
        mochila.push_back(&item);
        return true;
    }
}

bool Inventario::item_remover(Item& item){
    for (auto it = mochila.begin() ; it != mochila.end(); ++it){
        if((*it)->get_item_nome() == item.get_item_nome()){
            mochila.erase(it);
            return true;
        }
    }
    return false;
}

void Inventario::inventario_mostrar(){
    cout << "\tINVENTARIO:" << endl;
    if(inventario_vazio()){
        cout << "VAZIO" << endl;
        return;
    }
    int i = 1;
    for (vector<Item*>::iterator it = mochila.begin() ; it != mochila.end(); ++it){
        cout << i << " - " << (*it)->get_item_nome() << endl;
        i++;
    }
    if(inventario_cheio())
        cout << "(CHEIO)" << endl;  
}