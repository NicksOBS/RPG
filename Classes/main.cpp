#include "../Armas/Graveto_do_aprendiz.h"
#include "../Entidades/Mago.h"
#include "../Armas/Espada_enferrujada.h"
#include <iostream>
#include "../Outros/Inventario.h"
#include "../Entidades/Jogador.h"
#include "../Armas/Arma.h"
#include "../Locais/Dungeon.h"
#include "../Locais/Dungeon_facil.h"
#include "../Locais/Dungeon_normal.h"
#include "../Locais/Dungeon_dificil.h"
#include "../Entidades/Guerreiro.h"
#include "../Funcoes.h"
#include "../Entidades/Esqueleto.h"

using namespace std;
int main() {
    /*string nome;
    int escolha_classe;

    cout << "Digite seu nome, Fragmentado: ";
    cin >> nome;


    cout << "Bem-vindo(a) a Leyndell, " << nome << "!" << endl;
    cout << "Um lamento ecoa pelos Confins Interiores de Eldoria, uma terra ha muito esquecida, dilacerada por calamidades e ecos de uma gloria desvanecida." << endl;
    cout << "Outrora, grandes reinos ergueram-se sob a bencao do Anel Primordial, mas sua fratura trouxe a Ruina, espalhando uma mancha que corrompe almas e terras." << endl;
    cout << "Voce, um Fragmentado, despertou em meio as cinzas e sussurros de um tempo esquecido, com a memoria fragmentada e um proposito incerto." << endl;
    cout << "O que resta da antiga chama da ambicao bruxuleia em seu peito, impulsionando-o(a) a buscar o que foi perdido, ou a forjar um novo destino na escuridao!!" << endl << endl;

    Entidade* jogador = nullptr;

    try {
        cout << "A nevoa do esquecimento se dissipa, revelando os caminhos que voce pode trilhar. Qual a sua verdadeira natureza?" << endl;
        cout << "1. Mago: Aqueles que buscam o conhecimento proibido nas sombras, manipulando as energias arcanas esquecidas." << endl;
        cout << "2. Guerreiro: Um remanescente de ordens caidas, empunhando laminas enferrujadas e a forca bruta de um passado glorioso." << endl;
        cout << "Digite o numero da sua escolha, Fragmentado: ";

        switch (escolha_classe) {
            case 1: {
                jogador = new Mago();
                cout << "Voce escolheu o caminho do Mago!" << endl;
                cout << "Que as nevoas do arcano o(a) guiem, " << nome << "." << endl;
                break;
            }
            case 2: {
                    jogador = new Guerreiro();
                    cout << "Voce escolheu ser um guerreiro!" << endl;
                    cout << "Que a sua lamina nunca falhe, " << nome << "." << endl;
                    break;
                }
                default:
                    throw invalid_argument("Escolha invalida. Por favor, escolha 1 ou 2.");
            }
        } catch (const exception& e) {
            cerr << "Erro: " << e.what() << endl;
        }

        cidade();

        cout << ""
        while (!dungeon.dungeon_concluida()) {
            Sala* sala = dungeon.get_sala_atual();
            cout << "\nVoce esta em: " << sala->descricao << endl;

            if (sala->inimigo != nullptr) {
                cout << "Um inimigo aparece: " << sala->inimigo->getNome() << "!" << endl;
                
                sala->inimigo->receberDano(jogador->ataque());
                if (sala->inimigo->getVida() <= 0) {
                    cout << "Voce derrotou o inimigo!" << endl;
                    delete sala->inimigo;
                    sala->inimigo = nullptr;
                }
            }

            if (!sala->caminhos.empty()) {
                cout << "Escolha para onde ir:" << endl;
                for (size_t i = 0; i < sala->caminhos.size(); ++i) {
                    cout << i + 1 << ". " << sala->caminhos[i]->descricao << endl;
                }
                int escolha;
                cin >> escolha;
                dungeon.mover_para_sala(escolha);
            } else {
                cout << "Nao ha mais caminhos disponiveis." << endl;
                break;
            }
        }

        cout << "Parabens! Voce concluiu a primeira dungeon!" << endl;
        
        eventoaleatorio();

        cidade();




        return 0;*/

    Entidade *m = new Mago();
    //Entidade *g = new Guerreiro();
    Jogador p1{"Jogador 1", m};
    //Jogador p2{"Jogador 2", g}; 

    //cout << " batalha "<< endl;
    //cout << "Jogador 1 vs Esqueleto" << endl;
    //cout << endl;

    //Inimigo* esqueleto_inimigo = new Esqueleto();

    //batalha(p1, *esqueleto_inimigo);

    vector <Item> mercado = inicializa_mercado();
    p1.set_jogador_dinheiro(100);
    cidade(p1, mercado);

    //Dungeon* dungeon = new DungeonFacil();
    //explorar_dungeon(p1, *dungeon);
    //delete dungeon;

    //DungeonFacil dungeon;
    //explorar_dungeon(p1, dungeon);


}

