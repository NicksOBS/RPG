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
        std::cout << i << ". " << item.get_item_nome() << " (" << item.get_preco() << ")" << endl;
        i++;
    }
    std::cout << "7. Vender" << endl << "8. Sair" << endl;
}

void mostrar_status_jogador(Jogador& player){
    std::cout <<"\nNOME: " << player.get_jogador_nome() << "\nVIDA: " << player.get_jogador_classe()->get_vidaBase() << "/" << player.get_jogador_classe()->get_vidaMaxima() << endl << "DEFESA: " << player.get_jogador_classe()->get_defesaBase() << endl << "ATAQUE: " << player.get_jogador_classe()->get_ataqueBase() << endl << "DINHEIRO: " << player.get_jogador_dinheiro() << endl;
}

void mostrar_status_batalha(Jogador& player, Entidade& inimigo){ //recebe um jogador e um inimigo como parametro
    std::cout << "\tSEUS STATUS:" << "\t\t\tSTATUS DO INIMIGO:" << endl;
    std::cout <<"NOME: " << player.get_jogador_nome() << "\t\t\tNOME: " << inimigo.get_entidade_nome() << endl;
    std::cout <<"VIDA: " << player.get_jogador_classe()->get_vidaBase() << "/" << player.get_jogador_classe()->get_vidaMaxima() << "\t\t\tVIDA: " << inimigo.get_vidaBase() << "/" << inimigo.get_vidaMaxima() << endl;
    std::cout <<"DEFESA: " << player.get_jogador_classe()->get_defesaBase() << "\t\t\tDEFESA: " << inimigo.get_defesaBase() <<  endl;
    std::cout <<"ATAQUE: " << player.get_jogador_classe()->get_ataqueBase() << "\t\t\tATAQUE: " << inimigo.get_ataqueBase() << endl;
}


bool batalha(Jogador& player, Inimigo& inimigo) {
    bool p_turno = true, d_turno = false;
    int turno = 1;

    while (player.get_jogador_classe()->get_vidaBase() > 0 && inimigo.get_vidaBase() > 0) {
        std::cout << "\t\tTURNO: " << turno << endl;
        mostrar_status_batalha(player, inimigo);
        bool flag = true;
        if (p_turno) {
            do {
                std::cout << "\n>Qual sua proxima acao? " << endl << "1. Usar algum item de sua mochila\n" << "2. Atacar\n" << endl;
                int escolha;
                std::cin >> escolha;
                
                if (escolha == 1) {
                    int itemUsar;
                    player.mochila_mostrar();
                    std::cin >> itemUsar;
                    if (itemUsar > 0 && itemUsar <= player.get_jogador_mochila().get_inventario_lista().size()) {
                        //player.get_jogador_mochila().get_inventario_lista().at(itemUsar-1)->usar_pocao(player);
                    }
                } else if (escolha == 2) {
                    flag = false; // Encerra o do-while
                    std::cout << "\n>Voce ataca!\n";
                    int dano = player.get_jogador_classe()->Dano_ataque(inimigo);
                    inimigo.receber_dano(dano);
                    std::cout << "\n>Causou " << dano << " de dano.\n";
                    system("pause");
                } else {
                    std::cout << "Opcao invalida. Tente novamente.\n";
                }

            } while (flag);

            if (inimigo.get_vidaBase() <= 0) {
                std::cout << "\n Voce venceu a batalha!\n";
                return true;
            }

            p_turno = false;
            d_turno = true;
        }

        if (d_turno) {
            std::cout << "O inimigo ataca!\n";
            if (rand() % 101 >= 60) {
                player.get_jogador_classe()->receber_dano(inimigo.get_ataqueBase());
                std::cout << "\n>O " << inimigo.get_entidade_nome() << " se concentrou muito para o ataque e te acertou um golpe que ignorou toda sua defesa.\nVoce sofreu " << inimigo.get_ataqueBase() << " de dano.\n";
            } else {
                int dano = inimigo.Dano_ataque(*player.get_jogador_classe());
                player.get_jogador_classe()->receber_dano(dano);
                std::cout << "\n>Voce sofreu " << dano << " de dano.\n";
            }
            system("pause");

            if (player.get_jogador_classe()->get_vidaBase() <= 0) {
                std::cout << "\n >Voce foi derrotado...\n";
                return false;
            }

            p_turno = true;
            d_turno = false;
        }

        turno++;
        system("cls");
    }

    return false; // caso de erro de logica
}




bool explorar_dungeon_facil(Jogador& player, DungeonFacil& dungeon) {
    while (!dungeon.dungeon_concluida()) {
        std::cout << "\n============================================================================\n";
        dungeon.get_sala_atual()->mostrar_opcoes();

        if (dungeon.get_sala_atual()->inimigo != nullptr) {
            std::cout << "\nInimigo encontrado: " << dungeon.get_sala_atual()->inimigo->get_entidade_nome() << "\n";
            std::cout << "Iniciando batalha...\n";
            bool venceu = batalha(player, *dungeon.get_sala_atual()->inimigo);

            if (venceu) {
                dungeon.get_sala_atual()->inimigo = nullptr;
            } else {
                std::cout << "\n A aventura termina aqui...\n";
                return false; // Sai da exploração
            }
        }

        if (dungeon.get_sala_atual()->temChefe && dungeon.get_sala_atual()->inimigo == nullptr) {
            std::cout << "\n >Voce derrotou o chefe da dungeon! Parabens!\n";
            player.set_jogador_dinheiro(40);
            cout << ">Voce ganhou 40 de vida!\n\n";
            return true;
            break;
        }

        if (dungeon.get_sala_atual()->caminhos.size() == 1) {
    dungeon.mover_para_sala(1); // caminho único
    cout << "\nSeguindo automaticamente para a proxima sala...\n";
    system("pause");
} else if (dungeon.get_sala_atual()->caminhos.size() > 1) {
    int opcao;
    cin >> opcao;
    dungeon.mover_para_sala(opcao);
}


    }
}

bool explorar_dungeon_normal(Jogador& player, DungeonNormal& dungeon) {
    while (!dungeon.dungeon_concluida()) {
        std::cout << "\n============================================================================\n";
        dungeon.get_sala_atual()->mostrar_opcoes();

        if (dungeon.get_sala_atual()->inimigo != nullptr) {
            std::cout << "\nInimigo encontrado: " << dungeon.get_sala_atual()->inimigo->get_entidade_nome() << "\n";
            std::cout << "Iniciando batalha...\n";
            bool venceu = batalha(player, *dungeon.get_sala_atual()->inimigo);

            if (venceu) {
                dungeon.get_sala_atual()->inimigo = nullptr;
            } else {
                std::cout << "\n A aventura termina aqui...\n";
                return false; // Sai da exploração
            }
        }

        if (dungeon.get_sala_atual()->temChefe && dungeon.get_sala_atual()->inimigo == nullptr) {
            std::cout << "\n >Voce derrotou o chefe da dungeon! Parabens!\n";
            player.set_jogador_dinheiro(40);
            cout << ">Voce ganhou 40 de vida!\n\n";
            return true;
            break;
        }

        if (dungeon.get_sala_atual()->caminhos.size() == 1) {
    dungeon.mover_para_sala(1); // caminho único
    cout << "\nSeguindo automaticamente para a proxima sala...\n";
    system("pause");
} else if (dungeon.get_sala_atual()->caminhos.size() > 1) {
    int opcao;
    cin >> opcao;
    dungeon.mover_para_sala(opcao);
}


    }
}

bool explorar_dungeon_dificil(Jogador& player, DungeonDificil& dungeon) {
    while (!dungeon.dungeon_concluida()) {
        std::cout << "\n============================================================================\n";
        dungeon.get_sala_atual()->mostrar_opcoes();

        if (dungeon.get_sala_atual()->inimigo != nullptr) {
            std::cout << "\nInimigo encontrado: " << dungeon.get_sala_atual()->inimigo->get_entidade_nome() << "\n";
            std::cout << "Iniciando batalha...\n";
            bool venceu = batalha(player, *dungeon.get_sala_atual()->inimigo);

            if (venceu) {
                dungeon.get_sala_atual()->inimigo = nullptr;
            } else {
                std::cout << "\n A aventura termina aqui...\n";
                return false; // Sai da exploração
            }
        }

        if (dungeon.get_sala_atual()->temChefe && dungeon.get_sala_atual()->inimigo == nullptr) {
            std::cout << "\n >Voce derrotou o chefe da dungeon! Parabens!\n";
            player.set_jogador_dinheiro(40);
            cout << ">Voce ganhou 40 de vida!\n\n";
            return true;
            break;
        }

        if (dungeon.get_sala_atual()->caminhos.size() == 1) {
    dungeon.mover_para_sala(1); // caminho único
    cout << "\nSeguindo automaticamente para a proxima sala...\n";
    system("pause");
} else if (dungeon.get_sala_atual()->caminhos.size() > 1) {
    int opcao;
    cin >> opcao;
    dungeon.mover_para_sala(opcao);
}


    }
}

void cidade(Jogador& player, vector<Item>& mercado){
    int item;
    bool flag = true;
    bool flag2 = true;
    do{
    std::cout << "Seus status: ";
    mostrar_status_jogador(player);
    player.mochila_mostrar();
    std::cout << "\n\n";
    std::cout << ">Voce esta na cidade, aqui voce pode se recuperar de suas batalhas ou visitar nossos mercados, talvez encontre algo que te ajude nas suas proximas batalhas." << endl; //mensagem explicando oq pode fazer na cidade
    std::cout << "\nOnde voce deseja ir?" << endl << "1 - Mercado" << endl << "2 - Estalagem (Aqui voce vai poder descansar e curar toda a sua vida por 30 moedas)" << endl << "3 - Continuar" << endl;

    int escolha;
        cin >> escolha;
        switch(escolha){
            case 1: //mercado 
                do{
                    std::cout << "Seus status: ";
                    mostrar_status_jogador(player);
                    player.mochila_mostrar();
                    std::cout << "Digite o numero correspondente do item que deseja comprar, 7 para vender algum item, ou digite 8 para sair do mercado" << endl;  
                    mostrar_itens_mercado(mercado);
                    cin >> item;
                    switch(item){
                        case 1:
                            if(player.get_jogador_dinheiro() >= mercado.at(0).get_preco() && !player.mochila_cheia()){
                                player.set_jogador_dinheiro(-mercado.at(0).get_preco());
                                player.mochila_inserir(mercado.at(0));
                                std::cout << "Voce comprou " << mercado.at(0).get_item_nome() << endl;
                            }
                            else{
                                std::cout << "Voce nao pode comprar esse item." << endl;
                            }
                            system("pause");
                            system("cls");
                            break;
                        
                        case 2:
                            if(player.get_jogador_dinheiro() >= mercado.at(1).get_preco() && !player.mochila_cheia()){
                                player.set_jogador_dinheiro(-mercado.at(1).get_preco());
                                player.mochila_inserir(mercado.at(1));
                                std::cout << "Voce comprou " << mercado.at(1).get_item_nome() << endl;
                            }
                            else{
                                std::cout << "Voce nao pode comprar esse item." << endl;
                            }
                            system("pause");
                            system("cls");
                            break;

                        case 3:
                            if(player.get_jogador_dinheiro() >= mercado.at(2).get_preco() && !player.mochila_cheia()){
                                player.set_jogador_dinheiro(- mercado.at(2).get_preco());
                                player.mochila_inserir(mercado.at(2));
                                std::cout << "Voce comprou " << mercado.at(2).get_item_nome() << endl;
                            }
                            else{
                                std::cout << "Voce nao pode comprar esse item." << endl;
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            if(player.get_jogador_dinheiro() >= mercado.at(3).get_preco() && !player.mochila_cheia()){
                                player.set_jogador_dinheiro(- mercado.at(3).get_preco());
                                player.mochila_inserir(mercado.at(3));
                                std::cout << "Voce comprou " << mercado.at(3).get_item_nome() << endl;
                            }
                            else{
                                std::cout << "Voce nao pode comprar esse item." << endl;
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            if(player.get_jogador_dinheiro() >= mercado.at(4).get_preco() && !player.mochila_cheia()){
                                player.set_jogador_dinheiro(-mercado.at(4).get_preco());
                                player.mochila_inserir(mercado.at(4));
                                std::cout << "Voce comprou " << mercado.at(4).get_item_nome() << endl;
                            }
                            else{
                                std::cout << "Voce nao pode comprar esse item." << endl;
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 6:
                            if(player.get_jogador_dinheiro() >= mercado.at(5).get_preco() && !player.mochila_cheia()){
                                player.set_jogador_dinheiro(-mercado.at(5).get_preco());
                                player.mochila_inserir(mercado.at(5));
                                std::cout << "Voce comprou " << mercado.at(5).get_item_nome() << endl;
                            }
                            else{
                                std::cout << "Voce nao pode comprar esse item." << endl;
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 7:{
                            player.mochila_mostrar();
                            bool flag3 = true;
                            if(player.mochila_vazia()){
                                std::cout << "Voce nao tem nada para vender" << endl;
                                flag3 = false;
                                break;
                            }
                            int escolha;
                            do{
                                std::cout << "Qual item deseja vender?" << endl;
                                cin >> escolha;
                                    if(escolha >= 1 && escolha <= player.get_jogador_mochila().get_inventario_lista().size()){
                                        std::cout << "Voce vendeu " << player.get_jogador_mochila().get_inventario_lista().at(escolha-1)->get_item_nome() << endl;
                                        player.set_jogador_dinheiro(player.get_jogador_mochila().get_inventario_lista().at(escolha-1)->get_preco());
                                        player.mochila_remover(*player.get_jogador_mochila().get_inventario_lista().at(escolha-1));
                                        player.mochila_mostrar();
                                        std::cout << "Dinheiro: " << player.get_jogador_dinheiro();
                                        flag3 = false;
                                    }else{
                                        std::cout << "Insira o numero de algum item do seu inventario" << endl;
                                        flag3 = true;
                                    }
                            }while(flag3);
                            break;
                        }
                        case 8:
                            std::cout << "Saindo do mercado..." << endl;
                            system("pause");
                            system("cls");
                            flag2 = false;
                            break;
                        default:
                            std::cout << "Digite uma opcao valida! " << endl;
                            system("pause");
                            system("cls");
                            break;
                    }
                }while(flag2);
                break;
            case 2: //curar a vida
                if(player.get_jogador_dinheiro() < 10){//valor do custo da acao (a mudar)
                    std::cout << "Voce nao tem dinhiro suficiente" << endl;
                    flag = true;   
                }else{
                    player.set_jogador_dinheiro(- 10); //valor do custo da acao (a mudar)
                    player.get_jogador_classe()->buffVida(player.get_jogador_classe()->get_vidaMaxima() - player.get_jogador_classe()->get_vidaBase()); //cura a vida do jogador para a vida maxima da classe (faz uma subtracão entre a vida maxima da classe e vida atual)
                    flag = true;
                    std::cout << "Agora voce esta completamente revigorado e pronto para sua proxima batalha!" << endl;
                    system("pause");
                }
                break;
            case 3:
                std::cout << "Continuando sua jornada..." << endl;
                system("pause");
                system("cls");
                flag = false;
                break;
            default:
                std::cout << "Escolha uma opcao valilda" << endl;
                flag = true;
                break;
        }
    }while(flag);
}

void eventoAleatorio(Jogador& player){
    srand(time(NULL));
    if(rand()%101 > 70){ //20%
        std::cout << "Durante sua jornada, um grupo de assaltantes te aborda!!" << endl;//
        if(player.get_jogador_dinheiro() < 5){
            std::cout << "Por sorte, voce consegue esconder as poucas moedas que ainda te restam. Eles te deixam ir embora sem levar nada." << endl;//
            return;
        }
        else{
            int valor = player.get_jogador_dinheiro()*0.25;
            player.set_jogador_dinheiro(player.get_jogador_dinheiro()*0.75);
            std::cout << "Voce tenta resistir, mas percebe que estao em uma grande vantagem numerica e opta por deixar levar o que querem." << endl;
            system("pause");
            std::cout << "Os bandidos levam " << valor << " de suas moedas." << endl;
            return;
        }
    }
    else
        return;
}
#endif