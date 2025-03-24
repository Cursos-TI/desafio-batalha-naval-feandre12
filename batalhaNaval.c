#include <stdio.h>

// Definir o tamanho do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main()
{
    // Tabuleiro de Batalha Naval (10x10)
    // 0 = água
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Vetores que representam os navios (3 posições no tabuleiro)
    // Os navios serão representados pelo número 3 no tabuleiro, enquanto 0 é água
    int navio_horizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_vertical[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_diagonal1[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_diagonal2[TAMANHO_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais (ajuste se quiser mudar a posição dos navios)
    int linha_horizontal = 4; // 4 = Linha 5
    int coluna_horizontal = 2; // 2 = Coluna C

    int linha_vertical = 4; // 4 = Linha 5
    int coluna_vertical = 6; // 6 = Coluna G

    // Coordenadas iniciais dos navios na digonal principal e secundária
    int linha_diagonal1 = 0; // Começa na diagonal da Linha 1 e Coluna A
    int linha_diagonal2 = 0; // Começa na diagonal da Linha 1 e Coluna J

    int verificarVertical = 1;
    int verificarDiagonal1 = 1;
    int verificarDiagonal2 = 1;

    // Verifica se os navios estão dentro dos limites do tabuleiro
    if ((coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) && (linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) &&
        (linha_diagonal1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) && (linha_diagonal2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO))
        {
            // Posiciona o navio horizontal no tabuleiro
            for (int i = 0; i < TAMANHO_NAVIO; i++)
            {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
            }

            // Verifica se há espaço livre para o navio vertical
            for (int i = 0; i < TAMANHO_NAVIO; i++)
            {
                if (tabuleiro[linha_vertical + i][coluna_vertical] != 0)
                {
                    verificarVertical = 0;
                    break;
                }
            }

            if (verificarVertical)
            {
                // Posiciona o navio vertical no tabuleiro
                for (int i = 0; i < TAMANHO_NAVIO; i++)
                {
                    tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
                }

                // Verifica e posiciona o navio na diagonal 1
                for (int i = 0; i < TAMANHO_NAVIO; i++)
                {
                    if (tabuleiro[linha_diagonal1 + i][linha_diagonal1 + i] != 0)
                    {
                        verificarDiagonal1 = 0;
                        break;
                    }
                }

            if (verificarDiagonal1)
            {
                for (int i = 0; i < TAMANHO_NAVIO; i++)
                {
                    tabuleiro[linha_diagonal1 + i][linha_diagonal1 + i] = navio_diagonal1[i];
                }
            }
            else
            {
                printf("Sobreposição ao posicionar o navio na diagonal primária.\n"); // Mensagem de erro caso os navios da diagonal se sobrepõem
            }

            // Verifica e posiciona o navio na diagonal 2
            for (int i = 0; i < TAMANHO_NAVIO; i++)
            {
                int linha = linha_diagonal2 + i;
                int coluna = TAMANHO_TABULEIRO - 1 - (linha_diagonal2 + i);
                if (tabuleiro[linha][coluna] != 0)
                {
                    verificarDiagonal2 = 0;
                    break;
                }
            }

            if (verificarDiagonal2)
            {
                for (int i = 0; i < TAMANHO_NAVIO; i++)
                {
                    int linha = linha_diagonal2 + i;
                    int coluna = TAMANHO_TABULEIRO - 1 - (linha_diagonal2 + i);
                    tabuleiro[linha][coluna] = navio_diagonal2[i];
                }
            }
            else
            {
                printf("Sobreposição ao posicionar o navio na diagonal secundária.\n"); // Mensagem de erro caso os navios da diagonal se sobrepõem
            }

            // Exibir o cabeçalho e as letras das colunas do tabuleiro
            printf("Tabuleiro de Batalha Naval\n");
            printf("    A B C D E F G H I J\n"); // Espaço para alinhar com o tabuleiro

            // Exibir o número das linhas do tabuleiro
            for (int i = 0; i < TAMANHO_TABULEIRO; i++)
            {
                printf("%2d  ", i + 1); // Número da linha (1 a 10), alinhado à direita
                for (int j = 0; j < TAMANHO_TABULEIRO; j++)
                {
                    printf("%d ", tabuleiro[i][j]);
                }
                printf("\n"); // Quebra de linha
            }
        }
        else
        {
            printf("Os navios se sobrepõem, altere as coordenadas.\n"); // Mensagem de erro caso os navios se sobrepõem
        }
    }
    else
    {
        printf("Coordenadas inválidas para posicionamento dos navios.\n"); // Mensagem de erro caso os navios ultrapassem os limites do tabuleiro
    }

    return 0;
}