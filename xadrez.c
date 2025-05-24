#include <stdio.h>

// Constantes definidas para número de casas
#define CASAS_TORRE 5
#define CASAS_RAINHA 8
#define CASAS_BISPO 5

// Prototipação das funções
void moverTorre(int passo);
void moverRainha(int passo);
void moverBispo(int linha, int coluna);
void moverCavalo();

int main() {
    int opcao;

    do {
        printf("\n=== MENU DE MOVIMENTAÇÃO ===\n");
        printf("1 - Movimentar Torre\n");
        printf("2 - Movimentar Bispo\n");
        printf("3 - Movimentar Rainha\n");
        printf("4 - Movimentar Cavalo\n");
        printf("5 - Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n*** Movimentar Torre ***\n");
                moverTorre(1);
                break;

            case 2:
                printf("\n*** Movimentar Bispo ***\n");
                moverBispo(1, 1);
                break;

            case 3:
                printf("\n*** Movimentar Rainha ***\n");
                moverRainha(1);
                break;

            case 4:
                printf("\n*** Movimentar Cavalo ***\n");
                moverCavalo();
                break;

            case 5:
                printf("\nSaindo do programa...\n");
                break;

            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}

// Recursividade para mover a Torre (direita)
void moverTorre(int passo) {
    if (passo > CASAS_TORRE) return;
    printf("Direita => (%d)\n", passo);
    moverTorre(passo + 1);
}

// Recursividade para mover a Rainha (direita)
void moverRainha(int passo) {
    if (passo > CASAS_RAINHA) return;
    printf("Direita => (%d)\n", passo);
    moverRainha(passo + 1);
}

// Recursividade + loops aninhados para o Bispo (cima + direita)
void moverBispo(int linha, int coluna) {
    if (linha > CASAS_BISPO || coluna > CASAS_BISPO) return;

    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 1; j++) {
            printf("Cima ^ / Direita => (%d, %d)\n", linha, coluna);
        }
    }
    moverBispo(linha + 1, coluna + 1);
}

// Cavalo com loops aninhados e controle com continue/break
void moverCavalo() {
    int movimentos = 3; // Número de movimentos em L

    for (int m = 0; m < movimentos; m++) {
        for (int cima = 1; cima <= 2; cima++) {
            if (cima == 2) {
                for (int direita = 1; direita <= 1; direita++) {
                    if (direita == 0) continue; // Apenas para exemplo de uso
                    printf("Movimento em L: %d para cima e %d para a direita\n", cima, direita);
                    break; // Sai do loop mais interno após 1 passo para direita
                }
            }
        }
    }
}