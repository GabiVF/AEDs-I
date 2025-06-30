#include <stdio.h>
#include <stdlib.h>

// Aritmética de ponteiros em C

typedef int vetor;

int main (int argc, char** argv){
    
int x,y,z;
int *p;
vetor v[] = {13,12,16,15,14,19,18,20,11,10};

x = 10;
y = 12;
z = 17;

p = &x;
printf("Valor de x: %p e o valor de *p: %d\n", &x, x);
printf("Valor de p: %p e o valor de *p: %d\n", p, *p);

p++;
printf("Valor de p: %p e o valor de *p: %d\n", p, *p);

printf("\nValores do vetor\n");
for (int i = 0; i < 10; i++) {
    printf("o valor de &v[i]: %p o valor de v[i]: %d\n", &v[i], v[i]);
}

printf("\nvalores do vetor\n");
for (int *q = v; q < v + 10; q++) {
    printf("o valor de &v[i]: %p o valor de v[i]: %d\n", q ,*q);
}

// Bubble sort usando ponteiros para ordenar o vetor v
for (int i = 0; i < 9; i++) {
    for (int *q = v; q < v + 9 - i; q++) {
        if (*q > *(q + 1)) {
            int temp = *q;
            *q = *(q + 1);
            *(q + 1) = temp;
        }
    }
}

printf("\nValores do vetor ordenado\n");
for (int *q = v; q < v + 10; q++) {
    printf("o valor de &v[i]: %p o valor de v[i]: %d\n", q ,*q);
}

printf("\nValores do vetor inverso\n");
for (int *q = v + 9; q >= v; q--) {
    printf("o valor de &v[i]: %p o valor de v[i]: %d\n", q ,*q);
}


return 0;
}