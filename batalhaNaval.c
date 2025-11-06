#include <stdio.h>
#include <ctype.h>

#define TAM 10

int main() {
    int tabuleiro[TAM][TAM] = {0};
    int i, j;
    char linhaChar;
    int coluna;
    int linha;
    int tiros = 0;

    // NAVIO HORIZONTAL (C5, C6, C7)
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;
    tabuleiro[2][6] = 3;

    // NAVIO VERTICAL (F8, G8, H8)
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    printf("BATALHA NAVAL 10x10\n");
    printf("Digite jogadas no formato: A1, C5, J10...\n\n");

    while (1) {
        printf("Sua jogada: ");
        scanf(" %c%d", &linhaChar, &coluna);

        linhaChar = toupper(linhaChar);

        if (linhaChar < 'A' || linhaChar > 'J' || coluna < 1 || coluna > 10) {
            printf("Jogada invalida! Use algo como C5.\n");
            continue;
        }

        linha = linhaChar - 'A';
        coluna = coluna - 1;

        if (tabuleiro[linha][coluna] == 3) {
            printf("ACERTOU o navio em %c%d!\n", linhaChar, coluna + 1);
            tabuleiro[linha][coluna] = 9; // marca acerto
        } else {
            printf("ÁGUA em %c%d!\n", linhaChar, coluna + 1);
        }

        // Mostrando o tabuleiro do jogador
        printf("\nTABULEIRO:\n");
        printf("    A B C D E F G H I J\n");
        for (i = 0; i < TAM; i++) {
            printf("%c   ", 'A' + i);
            for (j = 0; j < TAM; j++) {
                if (tabuleiro[i][j] == 9)
                    printf("X ");
                else
                    printf("0 ");
            }
            printf("\n");
        }

        tiros++;

        if (tiros >= 20) {
            printf("\nFim do jogo!\n");
            break;
        }

        printf("\n");
    }

    return 0;
}
