#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int vetor[], int tamanho) {
    int i, j;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos adjacentes
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void exibirVetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[8];
    int i;

    // Inicializa o gerador de números aleatórios
    srand(time(0));

    // Preenche o vetor com números aleatórios
    for (i = 0; i < 8; i++) {
        vetor[i] = rand() % 100; // Números de 0 a 99
    }

    printf("Vetor original: ");
    exibirVetor(vetor, 8);

    // Ordena o vetor usando Bubble Sort
    bubbleSort(vetor, 8);

    printf("Vetor ordenado: ");
    exibirVetor(vetor, 8);

    return 0;
}