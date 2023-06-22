// Crie um vetor com 8 elementos aleatórios e através do algoritmo QuickSort, ordene-o

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main()
{
  int arr[8];
  int i;

  // Semente para gerar números aleatórios
  srand(time(NULL));

  // Preenche o vetor com números aleatórios entre 1 e 100
  for (i = 0; i < 8; i++)
  {
    arr[i] = rand() % 100 + 1;
  }

  printf("Vetor original: ");
  for (i = 0; i < 8; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  quickSort(arr, 0, 7);

  printf("Vetor ordenado: ");
  for (i = 0; i < 8; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}