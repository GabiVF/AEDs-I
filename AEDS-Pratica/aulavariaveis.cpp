#include <stdio.h>

int main () {

    // Variable declarations
    int varinteira = 47;
    float varfloat = 47.0;
    char varchar = 80; // ASCII value for 'P'

    // Print header
    printf("\n Características das variáveis e Alocação de memória ");
    printf("\n ....................................................");
    printf("\n Tipo      Valor       Endereço        Tamanho");

    // Print details for each variable
    printf("\n int       %d          %p      %li bytes", varinteira, &varinteira, sizeof(int));
    printf("\n float     %f          %p      %li bytes", varfloat, &varfloat, sizeof(float));
    printf("\n char      %c          %p      %li bytes", varchar, &varchar, sizeof(char));

    printf("\n\n");

    return 0; 
}