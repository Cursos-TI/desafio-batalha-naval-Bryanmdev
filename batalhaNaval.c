#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define linhas 10
#define colunas 10

int main() {
     //Variáveis
    int tabuleiro[linhas][colunas]; //Variável do tamanho do tabuleiro.
    char posicao[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};// Variável de posições das colunas
    int i, j, letreiro; // Variáveis para loops

    // Determinando inicialização do tabuleiro
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            tabuleiro[i][j] = 0;
        }
    }

    //Inicializando posições dos navios
    // Horizontal
    for(int m = 2, n = 3; n < 6; n++){
        tabuleiro[m][n] = 3;
    }

    // Vertical
    for(int o = 5, p = 7; o < 8; o++){
        tabuleiro[o][p] = 3;
    }

    // Diagonal
    for(int x = 3, y = 2; x < linhas - 4; x++, y++){
        tabuleiro[x][y] = 3;
    }

    // Diagonal 2
    for(int v = 8, z = 1; z < 4; v--, z++){
        tabuleiro[v][z] = 3;
    }


    // Espaço para ficar confortável esteticamente.
    printf(" ");

    // loop para mostrar array de letras do tabuleiro
    for(letreiro = 0; letreiro < colunas; letreiro++){
        printf("%2c", posicao[letreiro]);
    }

    printf("\n");

    for(i = 0; i < linhas; i++){
        printf("%d", i);

        for(j = 0; j < colunas; j++){
            
            //Imprimindo tabuleiro
            printf("%2d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    
    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
