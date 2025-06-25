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

using namespace std;

vector<Item>& inicializa_mercado(){
    /*vector<Item> mercado;
    mercado.insert()
    mercado.insert()
    mercado.insert()*/
}

void mostrar_itens_mercado(vector<Item>& mercado){
    int i = 1;
    for(auto item : mercado){
        cout << i << ". " << item.get_item_nome() << endl;
        i++;
    }
}

void mostrar_status_entidade(Entidade& entidade){
    cout <<"NOME: " << entidade.get_entidade_nome() << "VIDA: " << entidade.get_vidaBase() << endl << "DEFESA: " << entidade.get_defesaBase() << endl << "ATAQUE: " << entidade.get_ataqueBase();
}

void mostrar_status_batalha(Jogador& player, Entidade& inimigo){ //recebe um jogador e um inimigo como parametro
    cout << "\tSEUS STATUS:" << "\t\t\tSTATUS DO INIMIGO:" << endl;
    cout <<"NOME: " << player.get_jogador_nome() << "\t\t\tNOME: " << inimigo.get_entidade_nome() << endl;
    cout <<"VIDA: " << player.get_jogador_classe()->get_vidaBase() << "\t\t\tVIDA: " << inimigo.get_vidaBase() << endl;
    cout <<"DEFESA: " << player.get_jogador_classe()->get_defesaBase() << "\t\t\tDEFESA: " << inimigo.get_defesaBase() <<  endl;
    cout <<"ATAQUE: " << player.get_jogador_classe()->get_ataqueBase() << "\t\t\tATAQUE: " << inimigo.get_ataqueBase() << endl;
}

/*void batalha(Jogador& player, Dungeon& dungeon){ 
    bool p_turno = true, d_turno = false; // o jogador começa jogando 
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

void batalha(Jogador& player, Dungeon& dungeon) {
    bool p_turno = true, d_turno = false;
    int turno = 1;

    while (player.get_jogador_classe()->get_vidaBase() > 0 &&
           dungeon.get_adversario()->get_vidaBase() > 0) 
    {
        cout << "\t\tTURNO: " << turno << endl;
        mostrar_status_batalha(player, *dungeon.get_adversario());

        if (p_turno) {
            cout << "Voce ataca!\n";
            int dano = player.get_jogador_classe()->Dano_ataque(*dungeon.get_adversario());
            dungeon.get_adversario()->debuffVida(dano);
            cout << "Causou " << dano << " de dano.\n";
            system("pause");
            p_turno = false;
            d_turno = true;
        }

        if (d_turno) {
            cout << "O inimigo ataca!\n";
            int dano = dungeon.get_adversario()->Dano_ataque(*player.get_jogador_classe());
            player.get_jogador_classe()->debuffVida(dano);
            cout << "Você sofreu " << dano << " de dano.\n";
            system("pause");
            p_turno = true;
            d_turno = false;
        }

        if (dungeon.get_adversario()->get_vidaBase() <= 0) {
            cout << "\n Voce venceu a batalha!\n";
            break;
        }

        if (player.get_jogador_classe()->get_vidaBase() <= 0) {
            cout << "\n Voce foi derrotado...\n";
            break;
        }

        turno++;
        system("cls");
    }
}

void explorar_dungeon(Jogador& player, DungeonFacil& dungeon) {
    while (!dungeon.dungeon_concluida()) {
        system("cls");
        cout << "\n=====================\n";
        dungeon.get_sala_atual()->mostrar_opcoes();

        if (dungeon.get_sala_atual()->inimigo != nullptr) {
            cout << "\nInimigo encontrado: " << dungeon.get_sala_atual()->inimigo->get_entidade_nome() << "\n";
            cout << "Iniciando batalha...\n";
            batalha(player, *dungeon.get_sala_atual()->inimigo);
            dungeon.get_sala_atual()->inimigo = nullptr;
        }

        if (dungeon.get_sala_atual()->temChefe) {
            cout << "\nVocê derrotou o chefe da dungeon! Parabéns!\n";
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
    cout << "Voce esta na cidade, aqui voce pode se recuperar de suas batalhas ou visitar nossos mercados, talvez encontre algo que te ajude nas suas proximas batalhas." << endl; //mensagem explicando oq pode fazer na cidade
    cout << "Onde voce deseja ir?" << endl << "1 - Mercado" << endl << "2 - Estalagem" << endl << "3 - Continuar" << endl;
    int escolha;
    int item;
    bool flag = true;
    bool flag2 = true;
    do{
        cin >> escolha;
        switch(escolha){
            case 1: //mercado 
                do{
                    cout << "Digite o numero correspondente do item que deseja comprar. Ou digite X para sair do mercado" << endl;  
                    mostrar_itens_mercado(mercado);
                    switch (item){
                        case 1:
                            if(player.get_jogador_dinheiro() >= mercado.at(0).get_preco() && !player.mochila_cheia()){
                                player.set_jogador_dinheiro(player.get_jogador_dinheiro() - mercado.at(0).get_preco());
                                player.mochila_inserir(mercado.at(0));
                                mercado.erase(mercado.begin());//talvez nao tirar os itens do mercado (mercado ter itens infinitos)
                            }
                            else{
                                cout << "Voce nao pode comprar esse item." << endl;
                            }
                            system("cls");
                            break;
                        
                        case 2:
                            if(player.get_jogador_dinheiro() >= mercado.at(1).get_preco() && !player.mochila_cheia()){
                                player.set_jogador_dinheiro(player.get_jogador_dinheiro() - mercado.at(1).get_preco());
                                player.mochila_inserir(mercado.at(1));
                                mercado.erase(mercado.begin()+1);
                            }
                            else{
                                cout << "Voce nao pode comprar esse item." << endl;
                            }
                            system("cls");
                            break;

                        case 3:
                            if(player.get_jogador_dinheiro() >= mercado.at(2).get_preco() && !player.mochila_cheia()){
                                player.set_jogador_dinheiro(player.get_jogador_dinheiro() - mercado.at(2).get_preco());
                                player.mochila_inserir(mercado.at(2));
                                mercado.erase(mercado.begin()+2);
                            }
                            else{
                                cout << "Voce nao pode comprar esse item." << endl;
                            }
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
                    break;    
                }else{
                    int valor = player.get_jogador_dinheiro();
                    player.set_jogador_dinheiro(valor - 10); //valor do custo da acao (a mudar)
                    player.get_jogador_classe()->buffVida(player.get_jogador_classe()->get_vidaMaxima() - player.get_jogador_classe()->get_vidaBase()); //cura a vida do jogador para a vida maxima da classe (faz uma subtração entre a vida maxima da classe e vida atual)
                    flag = true;
                    break;
                }
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
    if(rand()%101 > 5){ //20%
        cout << "Durante sua jornada, um grupo de assaltantes de aborda!!" << endl;//
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