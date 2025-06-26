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
    Entidade* mago = new Mago();
    Entidade* guerreiro = new Guerreiro();
    Jogador jogador{"", mago};
    vector <Item> mercado = inicializa_mercado();

    std::cout << "==================== Tales from Eldoria ====================" << endl << endl;
    std::cout << "Digite seu nome, Fragmentado: ";
    cin >> nome;
    jogador.set_jogador_nome(nome);

    std::cout << ">Bem-vindo(a) a Leyndell, " << nome << "!" << endl;
    system("pause");
    std::cout << ">Um lamento ecoa pelos Confins Interiores de Eldoria, uma terra ha muito esquecida, dilacerada por calamidades e ecos de uma gloria desvanecida." << endl;
    std::cout << "Outrora, grandes reinos ergueram-se sob a bencao do Anel Primordial, mas sua fratura trouxe a Ruina, espalhando uma mancha que corrompe almas e terras." << endl;
    std::cout << "Voce, um Fragmentado, despertou em meio as cinzas e sussurros de um tempo esquecido, com a memoria fragmentada e um proposito incerto." << endl;
    std::cout << "O que resta da antiga chama da ambicao bruxuleia em seu peito, impulsionando-o(a) a buscar o que foi perdido, ou a forjar um novo destino na escuridao!!" << endl << endl;
    system("pause");


    try {
        std::cout << ">A nevoa do esquecimento se dissipa, revelando os caminhos que voce pode trilhar. Qual a sua verdadeira natureza?" << endl;
        std::cout << "1. Mago: Aqueles que buscam o conhecimento proibido nas sombras, manipulando as energias arcanas esquecidas." << endl;
        std::cout << "2. Guerreiro: Um remanescente de ordens caidas, empunhando laminas enferrujadas e a forca bruta de um passado glorioso." << endl << endl;
        std::cout << "Digite o numero da sua escolha, Fragmentado: ";
        cin >> escolha_classe;


        switch (escolha_classe) {
            case 1: {
                jogador.set_jogador_classe(*mago);
                std::cout << "-Voce escolheu o caminho do Mago!" << endl;
                std::cout << " Que as nevoas do arcano o(a) guiem, " << nome << "." << endl << endl;
                break;
            }
            case 2: {       
                jogador.set_jogador_classe(*guerreiro);      
                std::cout << "-Voce escolheu ser um guerreiro!" << endl;
                std::cout << " Que a sua lamina nunca falhe,  " << nome << "." << endl << endl;
                break;
            }
            default:
                throw invalid_argument("Escolha invalida. Por favor, escolha 1 ou 2.");
        }
    } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
    }

        cidade(jogador,mercado);
        eventoAleatorio(jogador);

        std::cout << "\n\n>Apos sua pequena jornada pelo centro da cidade, voce decide seguir seu caminho." << endl;
        std::cout << "Passando por uma rua paralela, voce comeca a ouvir estranhos sussuros vindos de um beco escuro." << endl;
        std::cout << "Voce decide investigar, e ao entrar no beco, encontra uma entrada subterranea." << endl;
        std::cout << "Bem vindo ao esgoto de Leyndell, " << nome << "." << endl;
        system("pause");
        
        bool passou;

        DungeonFacil dungeon;
        if(explorar_dungeon_facil(jogador, dungeon)){

            std::cout << ">Apos explorar o esgoto, voce recebe aplausos e parabenizacoes dos moradores da cidade por derrotar o rei rato." << endl;
            std::cout << "Quando voce estava prestes a sair da cidade, uma senhora misteriosa aparece e lhe faz uma suplica." << endl;
            std::cout << "Por favor, ajude-nos! Vi que voce e um grande aventureiro, nosso heroi da vila, meu filho...foi capturado pelo lorde das sombras maligno! Ele o levou para as catacumbas, e precisamos de alguem forte para resgata-lo!" << endl;
            std::cout << "Voce decide retornar rapidamente para a cidade, para em seguida, ajudar a sonhera." << endl;
            system("pause");
            cidade(jogador, mercado);
            DungeonNormal dungeon2;
            passou = explorar_dungeon_normal(jogador, dungeon2);
        }
        if(passou){
            std::cout << ">Ao derrotar o cavaleiro corrompido em uma batalha voraz, voce consegue livrar cavaleiro heroi da vila da sua maldicao." << endl;
            std::cout << "Obrigado, por me tirar da influencia do Lorde das sombras, vejo que voce eh um aventureiro forte, eu nao posso derrotar o lorde das sombras, ja estou muito fraco, mas voce pode! Ele esta escondido em uma dungeon mais profunda, e se voce conseguir derrotar ele, podera salvar toda Eldoria!" << endl;
            std::cout << "Com um senso de justica que nunca havia sentido antes, voce decide seguir o conselho do cavaleiro heroi e ir atras do lorde das sombras." << endl;
            std::cout << "Antes de seguinte para a dungeon mais profunda, onde o lorde das sombras esta escondido, voce resolve retornar para a cidade, a fim de recuperar suas forcas." << endl;
            system("pause");
            cidade(jogador, mercado);
            eventoAleatorio(jogador);
            DungeonDificil dungeon3;
            passou = explorar_dungeon_dificil(jogador, dungeon3);
        }

        if(passou){
            std::cout << " \"O que? eu sendo derrotado por um mero mortal? Eu sou o lorde das sombras, o senhor de Eldoria!\" " << endl;
            std::cout << ">Voce entao da o ataque derradeiro direto no coracao do lorde das sombras, e ele cai morto no chao." << endl;
            std::cout << "Uma sensacao de alivio e paz toma conta de voce, voce pensa na frase do Lorde das sombras, voce o Fragmentado, derrotou o Lorde das Sombras, gracas a sua dedicacao ao objetivo e gracas a sua coragem." << endl;
            std::cout << "\n>Parabens heroi de Eldoria, voce salvou o mundo.";
            system("pause");
            std::cout << "\n>Fim do jogo!" << endl;
        }
    return 0;
}