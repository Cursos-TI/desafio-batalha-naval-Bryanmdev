#include <stdio.h>
#include <stdlib.h>

// Constantes para tabuleiro
#define linhas 10
#define colunas 10

// Funções para gerar as matrizes de habilidades
void gerarCone(int habilidade[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            if (i <= 2 && j >= 2 - i && j <= 2 + i)
                habilidade[i][j] = 1;

            else
                habilidade[i][j] = 0;
        }
    }
}

void gerarCruz(int habilidade[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            if (i == 2 || j == 2)
                habilidade[i][j] = 1;

            else
                habilidade[i][j] = 0;
        }
    }
}

void gerarOctaedro(int habilidade[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            if (abs(i - 2) + abs(j - 2) <= 2)
                habilidade[i][j] = 1;

            else
                habilidade[i][j] = 0;
        }
    }
}

// Aplica a habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[linhas][colunas], int habilidade[5][5], int origemLinha, int origemColuna)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int lin = origemLinha - 2 + i;
            int col = origemColuna - 2 + j;

            if (lin >= 0 && lin < linhas && col >= 0 && col < colunas)
            {
                if (habilidade[i][j] == 1 && tabuleiro[lin][col] == 0)
                {
                    tabuleiro[lin][col] = 5;
                }
            }
        }
    }
}

// Mostra o tabuleiro com símbolos
void mostrarTabuleiro(int tabuleiro[linhas][colunas], char posicao[10])
{

    printf("  "); // Espaço para alinhar com o os números da linha
    for (int j = 0; j < colunas; j++)
    {
        printf(" %c", posicao[j]);
    }
    printf("\n");

    for (int i = 0; i < linhas; i++)
    {
        printf("%2d", i);
        for (int j = 0; j < colunas; j++)
        {
            if (tabuleiro[i][j] == 0)
                printf(" ~");
            else if (tabuleiro[i][j] == 3)
                printf(" N");
            else if (tabuleiro[i][j] == 5)
                printf(" *");
            else
                printf(" ?");
        }
        printf("\n");
    }
}

int main()
{

    // Variáveis
    int tabuleiro[linhas][colunas];                                        // Variável do tamanho do tabuleiro.
    char posicao[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Variável de posições das colunas

    // Inicializar tabuleiro com água (0)
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // Inserir navios (3)
    for (int m = 0, n = 6; n < 9; n++)
        tabuleiro[m][n] = 3;
    for (int o = 1, p = 9; o < 4; o++)
        tabuleiro[o][p] = 3;

    // Escolha habilidade
    int habilidade[5][5];
    int tipo;
    printf("Escolha a habilidade:\n1 - Cone\n2 - Cruz\n3 - Octaedro\n> ");
    scanf("%d", &tipo);

    switch (tipo)
    {
    case 1:
        gerarCone(habilidade);
        break;
    case 2:
        gerarCruz(habilidade);
        break;
    case 3:
        gerarOctaedro(habilidade);
        break;
    default:
        printf("Opção inválida!\n");
        return 1;
    }

    // Ponto de origem da habilidade
    int origemLinha, origemColuna;
    char letraColuna;
    printf("Digite a linha de origem (0-9): ");
    scanf("%d", &origemLinha);
    printf("Digite a coluna de origem (A-J): ");
    scanf(" %c", &letraColuna);

    // Converter para maiúscula se necessário

    if (letraColuna >= 'a' && letraColuna <= 'j')
    {
        letraColuna -= 32; // transforma 'a'-'j' em 'A'-'J'
    }

    if (letraColuna < 'A' || letraColuna > 'j')
    {
        printf("Coluna inválida! Use letras de A a J. \n");
        return 1;
    }

    // Converte letra para índice (A = 0, B = 1, ..., J = 9)
    origemColuna = letraColuna - 'A';

    aplicarHabilidade(tabuleiro, habilidade, origemLinha, origemColuna);
    mostrarTabuleiro(tabuleiro, posicao);

    return 0;
}