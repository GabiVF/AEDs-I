#include <stdio.h>
#include "Ordena.h"

void escrevevetor(int* vetor, int tamanho) {
    if (vetor == nullptr) {
        return;
    }
    for (int i = 0; i < tamanho; ++i) {
       printf("%d ", *(vetor + i));
    }
}

/*
Exemplo de ordenação de vetor
utilizando Bubble Sort, Selection Sort e Insertion Sort.
*/

int main(){

// Exemplo de vetor a ser ordenado    
int vetor[] = {5, 2, 9, 1, 5, 6};
int vetor2[] = {2, 5, 8, 1, 4, 6};
int vetor3[] = {9, 2, 7, 1, 3, 6};

// Exibição do vetor original para Bubble Sort
printf("Vetor original para Bubble Sort:\n");
escrevevetor(vetor, 6);
printf("\n");

//Bubble Sort
    Bublesort(vetor, 6);
printf("Vetor ordenado com Bubble Sort:\n");
escrevevetor(vetor, 6);
printf("\n");

printf("Vetor original para Selection Sort:\n");
escrevevetor(vetor2, 6);
printf("\n");

    selectionsort(vetor2, 6);
printf("Vetor ordenado com Selection Sort:\n");
escrevevetor(vetor2, 6);
printf("\n");
   
  
// Insertion Sort
printf("Vetor original para Insertion Sort:\n");
escrevevetor(vetor3, 6);
printf("\n");

    insertsort(vetor3, 6);
printf("Vetor ordenado com Insertion Sort:\n");
escrevevetor(vetor3, 6);
printf("\n");
   
return 0;
}