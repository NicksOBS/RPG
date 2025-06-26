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
#include "../Entidades/Zumbi.h"
#include "../Entidades/Goblin.h"
#include "../Entidades/LordeDasSombras.h"
#include "../Entidades/CavaleiroCorrompido.h"
#include "../Entidades/Inimigo.h"
#include "../Entidades/Entidade.h"
#include "../Entidades/ReiRato.h"



using namespace std;
int main() {
    string nome;
    int escolha_classe;

    cout << "=============== Tales from Eldoria ===============" << endl << endl;
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
                //Add Graveto do aprendiz ao inventario
                jogador->equipar_arma(new Graveto_do_aprendiz());
                break;
            }
            case 2: {
                jogador = new Guerreiro();
                cout << "Voce escolheu ser um guerreiro!" << endl;
                cout << "Que a sua lamina nunca falhe, " << nome << "." << endl;
                //Add Espada enferrujada ao inventario
                jogador->equipar_arma(new Espada_enferrujada());
                break;
            }
            default:
                throw invalid_argument("Escolha invalida. Por favor, escolha 1 ou 2.");
        }
    } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
    }

        cidade();

        cout << "Apos sua pequena jornada pelo centro da cidade, voce decide seguir seu caminho." << endl;
        cout << "Passando por uma rua paralela, voce comeca a ouvir estranhos sussuros vindos de um beco escuro." << endl;
        cout << "Voce decide investigar, e ao entrar no beco, encontra uma entrada subterranea." << endl;
        cout << "Bem vindo ao esgoto de Leyndell, " << nome << "." << endl;
        
        DungeonFacil dungeon;
        explorar_dungeon_facil(jogador, dungeon);

        cout << "Apos explorar o esgoto, voce recebe aplausos e parabenizacoes dos moradores da cidade por derrotar o rei rato." << endl;
        cout << "Quando voce estava prestes a sair da cidade, uma senhora misteriosa aparece e lhe faz uma suplica." << endl;
        cout << "Por favor, ajude-nos! Vi que voce e um grande aventureiro, nosso heroi da vila, meu filho...foi capturado pelo lorde das sombras maligno! Ele o levou para as catacumbas, e precisamos de alguem forte para resgata-lo!" << endl;
        cout << "Voce decide ajudar a senhora, e segue para as catacumbas." << endl;
        
        DungeonNormal dungeon2;
        explorar_dungeon_normal(jogador, dungeon2);

        cout << "Apos derrotar o cavaleiro corrompido em uma batalha voraz, voce consegue livrar cavaleiro heroi da vila da sua maldicao." << endl;
        cout << "\"Obrigado, por me tirar da influencia do Lorde das sombras, vejo que voce eh um aventureiro forte, eu nao posso derrotar o lorde das sombras, ja estou muito fraco, mas voce pode! Ele esta escondido em uma dungeon mais profunda, e se voce conseguir derrotar ele, podera salvar toda Eldoria!\"" << endl;
        cout << "Com um senso de justica que nunca havia sentido antes, voce decide seguir o conselho do cavaleiro heroi e ir atras do lorde das sombras." << endl;
        cout << "Voce segue para a dungeon mais profunda, onde o lorde das sombras esta escondido." << endl;
        
        DungeonDificil dungeon3;
        explorar_dungeon_dificil(jogador, dungeon3);

        cout << "O que? eu sendo derrotado por um mero mortal? Eu sou o lorde das sombras, o senhor de Eldoria!" << endl;
        cout << "Voce entao da o ataque derradeiro direto no coracao do lorde das sombras, e ele cai morto no chao." << endl;
        cout << "Uma sensacao de alivio e paz toma conta de voce, voce pensa na frase do Lorde das sombras, voce o Fragmentado, derrotou o Lorde das Sombras, gracas a sua dedicacao ao objetivo e gracas a sua coragem." << endl;
        cout << "Parabens heroi de Eldoria, voce salvou o mundo.";
        cout << "Fim do jogo!" << endl;



    /*Entidade *m = new Mago();
    //Entidade *g = new Guerreiro();
    Jogador p1{"Jogador 1", m};
    //Jogador p2{"Jogador 2", g}; 

    vector <Item> mercado = inicializa_mercado();
    p1.set_jogador_dinheiro(100);
    cidade(p1, mercado);


    DungeonFacil dungeon;
    explorar_dungeon_facil(p1, dungeon);

    DungeonNormal dungeon2;
    explorar_dungeon_normal(p1, dungeon2);

    DungeonDificil dungeon3;
    explorar_dungeon_dificil(p1, dungeon3);
    cout << "Obrigado por jogar!" << endl;
    */
    return 0;
}
