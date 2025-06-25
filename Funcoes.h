#ifndef FUNCOES_H
#define FUNCOES_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Armas/Arma.h"
#include "Entidades/Entidade.h"
#include "Locais/Dungeon.h"
#include "Entidades/Jogador.h"
#include <vector>
#include "Itens/Item.h"
#include "Itens/Pocao_defesa_grande.h"
#include "Itens/Pocao_defesa.h"
#include "Itens/Pocao.h"
#include "Itens/Pocao_forca.h"
#include "Itens/Pocao_forca_grande.h"
#include "Itens/Pocao_vida.h"
#include "Itens/Pocao_vida_grande.h"

using namespace std;

vector<Item> inicializa_mercado() {
    vector<Item> mercado;
    mercado.push_back(Pocao_defesa());
    mercado.push_back(Pocao_defesa_grande());
    mercado.push_back(Pocao_vida());
    mercado.push_back(Pocao_vida_grande());
    mercado.push_back(Pocao_forca());
    mercado.push_back(Pocao_forca_grande());
    return mercado;
}

void mostrar_itens_mercado(vector<Item>& mercado){
    int i = 1;
    for(auto item : mercado){
        cout << i << ". " << item.get_item_nome() << " (" << item.get_preco() << ")" << endl;
        i++;
    }
}

void mostrar_status_jogador(Jogador& player){
    cout <<"\nNOME: " << player.get_jogador_nome() << "\nVIDA: " << player.get_jogador_classe()->get_vidaBase() << "/" << player.get_jogador_classe()->get_vidaMaxima() << endl << "DEFESA: " << player.get_jogador_classe()->get_defesaBase() << endl << "ATAQUE: " << player.get_jogador_classe()->get_ataqueBase() << endl << "DINHEIRO: " << player.get_jogador_dinheiro() << endl;
}

void mostrar_status_batalha(Jogador& player, Entidade& inimigo){ //recebe um jogador e um inimigo como parametro
    cout << "\tSEUS STATUS:" << "\t\t\tSTATUS DO INIMIGO:" << endl;
    cout <<"NOME: " << player.get_jogador_nome() << "\t\t\tNOME: " << inimigo.get_entidade_nome() << endl;
    cout <<"VIDA: " << player.get_jogador_classe()->get_vidaBase() << "/" << player.get_jogador_classe()->get_vidaMaxima() << "\t\t\tVIDA: " << inimigo.get_vidaBase() << "/" << inimigo.get_vidaMaxima() << endl;
    cout <<"DEFESA: " << player.get_jogador_classe()->get_defesaBase() << "\t\t\tDEFESA: " << inimigo.get_defesaBase() <<  endl;
    cout <<"ATAQUE: " << player.get_jogador_classe()->get_ataqueBase() << "\t\t\tATAQUE: " << inimigo.get_ataqueBase() << endl;
}

/*void batalha(Jogador& player, Dungeon& dungeon){ 
    bool p_turno = true, d_turno = false; // o jogador comeca jogando 
    int turno = 1;
    while(player.get_jogador_classe()->get_vidaBase() > 0 && dungeon.get_adversario()->get_vidaBase() > 0){
        cout << "\t\tTURNO: " << turno;
        mostrar_status_batalha(player, *dungeon.get_adversario());

        if(p_turno){
            //o jogador faz as coisas dele aqui
            p_turno = false;
            d_turno = true;
        }
        if(d_turno){
            //o inimigo faz as coisas dele aqui
            p_turno = true;
            d_turno = false;
        }
        system("cls"); //LIMPA A TELA DEPOIS DE CADA TURNO
    }
}*/

bool batalha(Jogador& player, Inimigo& inimigo) {
    bool p_turno = true, d_turno = false;
    int turno = 1;

    while (player.get_jogador_classe()->get_vidaBase() > 0 && inimigo.get_vidaBase() > 0) {
        cout << "\t\tTURNO: " << turno << endl;
        mostrar_status_batalha(player, inimigo);

        if (p_turno) {
            cout << "Voce ataca!\n";
            int dano = player.get_jogador_classe()->Dano_ataque(inimigo);
            inimigo.receber_dano(dano);
            cout << "Causou " << dano << " de dano.\n";
            system("pause");

            if (inimigo.get_vidaBase() <= 0) {
                cout << "\n Voce venceu a batalha!\n";
                return true;
            }

            p_turno = false;
            d_turno = true;
        }

        if (d_turno) {
            cout << "O inimigo ataca!\n";
            int dano = inimigo.Dano_ataque(*player.get_jogador_classe());
            player.get_jogador_classe()->receber_dano(dano);
            cout << "Voce sofreu " << dano << " de dano.\n";
            system("pause");

            if (player.get_jogador_classe()->get_vidaBase() <= 0) {
                cout << "\n Voce foi derrotado...\n";
                return false;
            }

            p_turno = true;
            d_turno = false;
        }

        turno++;
        system("cls");
    }

    return false; // caso de erro de lógica
}



void explorar_dungeon(Jogador& player, DungeonFacil& dungeon) {
    while (!dungeon.dungeon_concluida()) {
        cout << "\n=====================\n";
        dungeon.get_sala_atual()->mostrar_opcoes();

        if (dungeon.get_sala_atual()->inimigo != nullptr) {
            cout << "\nInimigo encontrado: " << dungeon.get_sala_atual()->inimigo->get_entidade_nome() << "\n";
            cout << "Iniciando batalha...\n";
            bool venceu = batalha(player, *dungeon.get_sala_atual()->inimigo);

            if (venceu) {
                dungeon.get_sala_atual()->inimigo = nullptr;
            } else {
                cout << "\n A aventura termina aqui...\n";
                return; // Sai da exploração
            }
        }

        if (dungeon.get_sala_atual()->temChefe && dungeon.get_sala_atual()->inimigo == nullptr) {
            cout << "\n Voce derrotou o chefe da dungeon! Parabens!\n";
            break;
        }

        cout << "\nEscolha seu caminho:\n";
        int opcao;
        cin >> opcao;
        dungeon.mover_para_sala(opcao);
    }
}




void inicio(){
    cout << "";
}

void cidade(Jogador& player, vector<Item> mercado){
    int item;
    bool flag = true;
    bool flag2 = true;
    do{
    cout << "Seus status: ";
    mostrar_status_jogador(player);
    player.mochila_mostrar();
    cout << "\n\n";
    cout << "Voce esta na cidade, aqui voce pode se recuperar de suas batalhas ou visitar nossos mercados, talvez encontre algo que te ajude nas suas proximas batalhas." << endl; //mensagem explicando oq pode fazer na cidade
    cout << "Onde voce deseja ir?" << endl << "1 - Mercado" << endl << "2 - Estalagem (Aqui voce vai poder descansar e curar toda a sua vida por 30 moedas)" << endl << "3 - Continuar" << endl;

    int escolha;
        cin >> escolha;
        switch(escolha){
            case 1: //mercado 
                do{
                    cout << "Digite o numero correspondente do item que deseja comprar. Ou digite X para sair do mercado" << endl;  
                    mostrar_itens_mercado(mercado);
                    cin >> item;
                    switch (item){
                        case 1:
                            if(player.get_jogador_dinheiro() >= mercado.at(0).get_preco() && !player.mochila_cheia()){
                                player.set_jogador_dinheiro(player.get_jogador_dinheiro() - mercado.at(0).get_preco());
                                player.mochila_inserir(mercado.at(0));
                                cout << "Voce comprou " << mercado.at(0).get_item_nome() << endl;
                            }
                            else{
                                cout << "Voce nao pode comprar esse item." << endl;
                            }
                            system("pause");
                            system("cls");
                            break;
                        
                        case 2:
                            if(player.get_jogador_dinheiro() >= mercado.at(1).get_preco() && !player.mochila_cheia()){
                                player.set_jogador_dinheiro(player.get_jogador_dinheiro() - mercado.at(1).get_preco());
                                player.mochila_inserir(mercado.at(1));
                                cout << "Voce comprou " << mercado.at(1).get_item_nome() << endl;
                            }
                            else{
                                cout << "Voce nao pode comprar esse item." << endl;
                            }
                            system("pause");
                            system("cls");
                            break;

                        case 3:
                            if(player.get_jogador_dinheiro() >= mercado.at(2).get_preco() && !player.mochila_cheia()){
                                player.set_jogador_dinheiro(player.get_jogador_dinheiro() - mercado.at(2).get_preco());
                                player.mochila_inserir(mercado.at(2));
                                cout << "Voce comprou " << mercado.at(2).get_item_nome() << endl;
                            }
                            else{
                                cout << "Voce nao pode comprar esse item." << endl;
                            }
                            system("pause");
                            system("cls");
                            break;

                        default:
                            break;
                    }
                }while(flag2);
                break;
            case 2: //curar a vida
                if(player.get_jogador_dinheiro() < 10){//valor do custo da acao (a mudar)
                    cout << "Voce nao tem dinhiro suficiente" << endl;
                    flag = true;   
                }else{
                    int valor = player.get_jogador_dinheiro();
                    player.set_jogador_dinheiro(valor - 10); //valor do custo da acao (a mudar)
                    player.get_jogador_classe()->buffVida(player.get_jogador_classe()->get_vidaMaxima() - player.get_jogador_classe()->get_vidaBase()); //cura a vida do jogador para a vida maxima da classe (faz uma subtracão entre a vida maxima da classe e vida atual)
                    flag = true;
                }
                break;
            case 3:
                cout << "Continuando sua jornada..." << endl;
                system("pause");
                system("cls");
                flag = false;
                break;
            default:
                cout << "Escolha uma opcao valilda" << endl;
                flag = true;
                break;
        }
    }while(flag);
}

void eventoAleatorio(Jogador& player){
    srand(time(NULL));
    if(rand()%101 > 80){ //20%
        cout << "Durante sua jornada, um grupo de assaltantes te aborda!!" << endl;//
        if(player.get_jogador_dinheiro() < 80){
            cout << "Por sorte, voce consegue esconder as poucas moedas que ainda te restam. Eles te deixam ir embora sem levar nada." << endl;//
            return;
        }
        else{
            int valor = player.get_jogador_dinheiro()*0.25;
            player.set_jogador_dinheiro(player.get_jogador_dinheiro()*0.75);
            cout << "Voce tenta resistir, mas percebe que estao em uma grande vantagem numerica e opta por deixar levar o que querem." << endl;
            system("pause");
            cout << "Os bandidos levam " << valor << " de suas moedas." << endl;
            return;
        }
    }
    else
        return;
}
#endif