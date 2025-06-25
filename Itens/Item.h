#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;
class Item{
    protected:
        string item_nome;
        int item_preco;
    public:
        Item(string n, int p) : item_nome{n}, item_preco{p}{}
        ~Item(){}
        virtual int get_preco() const{return item_preco;};
        virtual string get_item_nome()const{return item_nome;}
};

#endif