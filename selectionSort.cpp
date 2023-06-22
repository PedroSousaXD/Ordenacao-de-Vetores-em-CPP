// Crie um vetor com 8 elementos aleatórios e através do algoritmo SelectionSort, ordene-o

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int vetor[], int tamanho)
{
  int i, j, minIndex, temp;

  for (i = 0; i < tamanho - 1; i++)
  {
    minIndex = i;

    for (j = i + 1; j < tamanho; j++)
    {
      if (vetor[j] < vetor[minIndex])
      {
        minIndex = j;
      }
    }

    // Troca o elemento mínimo com o elemento atual
    temp = vetor[i];
    vetor[i] = vetor[minIndex];
    vetor[minIndex] = temp;
  }
}

int main()
{
  int vetor[8];
  int i;

  // Semente para gerar números aleatórios
  srand(time(NULL));

  // Preenche o vetor com números aleatórios entre 1 e 100
  for (i = 0; i < 8; i++)
  {
    vetor[i] = rand() % 100 + 1;
  }

  printf("Vetor original: ");
  for (i = 0; i < 8; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  selectionSort(vetor, 8);

  printf("Vetor ordenado: ");
  for (i = 0; i < 8; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  return 0;
}