#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
     //Variáveis
    int tabuleiro[10][10]; //Variável do tamanho do tabuleiro.
    char posicao[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};// Variável de posições das colunas
    int i, j, letreiro; // Variáveis para loops

    // Determinando inicialização do tabuleiro
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    //Inicializando posições dos navios
    // Horizontal
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    // Vertical
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    // Espaço para ficar confortável esteticamente.
    printf(" ");

    // loop para mostrar array de letras do tabuleiro
    for(letreiro = 0; letreiro < 10; letreiro++){
        printf("%2c", posicao[letreiro]);
    }

    printf("\n");

    for(i = 0; i < 10; i++){
        printf("%d", i);

        for(j = 0; j < 10; j++){
            
            //Imprimindo tabuleiro
            printf("%2d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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
