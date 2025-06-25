#ifndef FUNCOES_H
#define FUNCOES_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Armas/Arma.h"
#include "Entidades/Entidade.h"
#include "Locais/Dungeon.h"
#include "Entidades/Jogador.h"

using namespace std;

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

void batalha(Jogador& player, Dungeon& dungeon){ 
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
}

void inicio(){
    cout << "";
}

void cidade(Jogador& player){
    cout << "Voce esta na cidade, aqui voce pode se recuperar de suas batalhas ou visitar nossos mercados, talvez encontre algo que te ajude nas suas proximas batalhas." << endl; //mensagem explicando oq pode fazer na cidade
    cout << "Onde voce deseja ir?" << endl << "1 - Mercado" << endl << "2 - Estalagem" << endl << "3 - Continuar" << endl;
    int escolha;
    bool flag = true;
    do{
        cin >> escolha;
        switch(escolha){
            case 1: //mercado 
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
        }
    }while(flag);
}
#endif