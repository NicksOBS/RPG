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
int main() {
    string nome;
    int escolha_classe;

    cout << "Digite seu nome, Fragmentado: ";
    cin >> nome;

    cout << "Bem-vindo(a) a Leyndell, " << nome << "!" << endl;
    cout << "Um lamento ecoa pelos Confins Interiores de Eldoria, uma terra há muito esquecida, dilacerada por calamidades e ecos de uma glória desvanecida." << endl;
    cout << "Outrora, grandes reinos ergueram-se sob a benção do Anel Primordial, mas sua fratura trouxe a Ruína, espalhando uma mancha que corrompe almas e terras." << endl;
    cout << "Você, um Fragmentado, despertou em meio às cinzas e sussurros de um tempo esquecido, com a memória fragmentada e um propósito incerto." << endl;
    cout << "O que resta da antiga chama da ambição bruxuleia em seu peito, impulsionando-o(a) a buscar o que foi perdido, ou a forjar um novo destino na escuridão!!" << endl << endl;

    Entidade* jogador = nullptr;

    try {
        cout << "A névoa do esquecimento se dissipa, revelando os caminhos que você pode trilhar. Qual a sua verdadeira natureza?" << endl;
        cout << "1. Mago: Aqueles que buscam o conhecimento proibido nas sombras, manipulando as energias arcanas esquecidas." << endl;
        cout << "2. Guerreiro: Um remanescente de ordens caídas, empunhando lâminas enferrujadas e a força bruta de um passado glorioso." << endl;
        cout << "Digite o número da sua escolha, Fragmentado: ";

        switch (escolha_classe) {
            case 1: {
                jogador = new Mago();
                cout << "Você escolheu o caminho do Mago!" << endl;
                cout << "Que as névoas do arcano o(a) guiem, " << nome << "." << endl;
                break;
            }
            case 2: {
                jogador = new Guerreiro();
                cout << "Você escolheu ser um guerreiro!" << endl;
                cout << "Que a sua lâmina nunca falhe, " << nome << "." << endl;
                break;
            }
            default:
                throw invalid_argument("Escolha inválida. Por favor, escolha 1 ou 2.");
        }
    } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
    }

    


    return 0;
}

