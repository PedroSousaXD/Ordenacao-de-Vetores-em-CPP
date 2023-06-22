// Crie um vetor com 8 elementos aleatórios e através do algoritmo InsertionSort, ordene-o

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

void insertionSort(int vetor[], int tamanho)
{
  int i, j, chave;
  for (i = 1; i < tamanho; i++)
  {
    chave = vetor[i];
    j = i - 1;
    while (j >= 0 && vetor[j] > chave)
    {
      vetor[j + 1] = vetor[j];
      j--;
    }
    vetor[j + 1] = chave;
  }
}

void exibirVetor(int vetor[], int tamanho)
{
  int i;
  for (i = 0; i < tamanho; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main()
{
  int vetor[8];
  int i;

  // Inicializa o gerador de números aleatórios
  srand(time(0));

  // Preenche o vetor com números aleatórios
  for (i = 0; i < 8; i++)
  {
    vetor[i] = rand() % 100; // Números aleatórios de 0 a 99
  }

  printf("Vetor original:\n");
  exibirVetor(vetor, 8);

  insertionSort(vetor, 8);

  printf("Vetor ordenado:\n");
  exibirVetor(vetor, 8);

  return 0;
}