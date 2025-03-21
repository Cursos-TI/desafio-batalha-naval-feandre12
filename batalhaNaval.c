#include <stdio.h>

int main() {
    // Tabuleiro de Batalha Naval (10x10)
    // 0 = água
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Vetores que representam os navios (3 posições no tabuleiro)
    // Os navios serão representados pelo número 3 no tabuleiro, enquanto 0 é água
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // Coordenadas iniciais (ajuste se quiser mudar a posição dos navios)
    int linha_horizontal = 2; // 2 = Linha 3
    int coluna_horizontal = 5; // 5 = Coluna F

    int linha_vertical = 5; // 5 = Linha 6
    int coluna_vertical = 7; // 7 = Coluna H

    // Verifica se os navios estão dentro dos limites do tabuleiro
    if (coluna_horizontal + 3 <= 10 && linha_vertical + 3 <= 10)
    {
        // Posiciona o navio horizontal no tabuleiro
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
        }

        // Posiciona o navio vertical no tabuleiro
        for (int i = 0; i < 3; i++)
        {
            tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
        }

        // Exibir o cabeçalho e as letras das colunas do tabuleiro
        printf("Tabuleiro de Batalha Naval\n");
        printf("    A B C D E F G H I J\n"); // Espaço para alinhar com o tabuleiro

        // Exibir o número das linhas do tabuleiro
        for (int i = 0; i < 10; i++)
        {
            printf("%2d  ", i + 1); // Número da linha (1 a 10), alinhado
            for (int j = 0; j < 10; j++)
            {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n"); // Quebra de linha
        }
    }
    else
    {
        printf("Coordenadas inválidas para posicionamento dos navios.\n"); // Mensagem de erro caso os navios ultrapassem os limites do tabuleiro
    }

    return 0;
}