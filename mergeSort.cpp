// Crie um vetor com 8 elementos aleatórios e através do algoritmo MergeSort, ordene-o

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int vetor[], int inicio, int meio, int fim)
{
  int i, j, k;
  int tamanhoEsq = meio - inicio + 1;
  int tamanhoDir = fim - meio;

  int esquerda[tamanhoEsq], direita[tamanhoDir];

  // Copia os elementos para os vetores auxiliares
  for (i = 0; i < tamanhoEsq; i++)
  {
    esquerda[i] = vetor[inicio + i];
  }
  for (j = 0; j < tamanhoDir; j++)
  {
    direita[j] = vetor[meio + 1 + j];
  }

  // Combina os vetores auxiliares de volta no vetor original
  i = 0;
  j = 0;
  k = inicio;
  while (i < tamanhoEsq && j < tamanhoDir)
  {
    if (esquerda[i] <= direita[j])
    {
      vetor[k] = esquerda[i];
      i++;
    }
    else
    {
      vetor[k] = direita[j];
      j++;
    }
    k++;
  }

  // Copia os elementos restantes, se houver, do vetor esquerdo
  while (i < tamanhoEsq)
  {
    vetor[k] = esquerda[i];
    i++;
    k++;
  }

  // Copia os elementos restantes, se houver, do vetor direito
  while (j < tamanhoDir)
  {
    vetor[k] = direita[j];
    j++;
    k++;
  }
}

void mergeSort(int vetor[], int inicio, int fim)
{
  if (inicio < fim)
  {
    int meio = inicio + (fim - inicio) / 2;

    mergeSort(vetor, inicio, meio);
    mergeSort(vetor, meio + 1, fim);

    merge(vetor, inicio, meio, fim);
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

  mergeSort(vetor, 0, 7);

  printf("Vetor ordenado: ");
  for (i = 0; i < 8; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  return 0;
}