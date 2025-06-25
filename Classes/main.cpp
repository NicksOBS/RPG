#include "../Armas/Graveto_do_aprendiz.h"
#include "../Entidades/Mago.h"
#include "../Armas/Espada_enferrujada.h"
#include <iostream>
#include "../Outros/Inventario.h"
#include "../Entidades/Jogador.h"
#include "../Armas/Arma.h"
#include "../Entidades/Guerreiro.h"
#include "../funcoes.h"
#include "../Entidades/Esqueleto.h"


using namespace std;
int main(){
    // cout << "Insira seu nome: ";
    // string nome;
    // cin >> nome;
    Entidade *m = new Mago();
    Entidade *g = new Guerreiro();
    Jogador p1{"Jogador 1", m};
    Jogador p2{"Jogador 2", g};
    // cout << "\nNome: " << p1.get_jogador_nome() << endl << "Classe: " << p1.get_jogador_classe_nome() << endl;
    // Graveto_do_aprendiz item1;
    // Espada_enferrujada item2;

    // if(p1.mochila_vazia()) cout << "MOCHILA VAZIA\n"; 
    // p1.mochila_inserir(item1);
    // p1.mochila_inserir(item2);
    // p1.mochila_mostrar();
    // p1.mochila_remover(item1);
    // p1.mochila_mostrar();
    // cout << "DANO: " << p1.get_jogador_classe()->ataque();//da pra atacar usando a funcao get_jogador_classe
    p1.set_jogador_dinheiro(100);
    eventoAleatorio(p1);
    mostrar_status_batalha(p1, *p2.get_jogador_classe());
}
