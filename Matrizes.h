

using namespace std;
#include <iostream>

const int TAM = 128;
typedef int Vetor[TAM][TAM];

// Recebe valores da matriz
void EscreverMatriz(Vetor matriz, int linhas, int colunas) {
    int* p = &matriz[0][0];
    int total = linhas * TAM;  // passar de linha
    for (int i = 0; i < linhas; ++i) {
        int* linha = p + i * TAM;
        for (int j = 0; j < colunas; ++j) {
            cin >> *(linha + j);
        }
    }
}

// Imprime os valores da matriz
void MostrarMatriz(Vetor matriz, int linhas, int colunas) {
    int* p = &matriz[0][0];
    for (int i = 0; i < linhas; ++i) {
        int* linha = p + i * TAM;
        for (int j = 0; j < colunas; ++j) {
            cout << *(linha + j) << " ";
        }
        cout << endl;
    }
}

// Multiplica cada elemento por um valor
void multiplicarMatrizPorValor(Vetor matriz, int linhas, int colunas, int valor) {
    int* p = &matriz[0][0];
    for (int i = 0; i < linhas * colunas; ++i) {
        *(p + i) *= valor;
    }
}

// Gera a transposta da matriz 
void transporMatriz(const Vetor entrada, Vetor saida, int linhas, int colunas) {
    const int* p = &entrada[0][0];
    int* q = &saida[0][0];
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            *(q + j * TAM + i) = *(p + i * TAM + j);
        }
    }
}

// Inverte as colunas horizontalmente
void inverterColunas(Vetor matriz, int linhas, int colunas) {
    int* p = &matriz[0][0];
    for (int i = 0; i < linhas; ++i) {
        int* linha = p + i * TAM;
        for (int j = 0; j < colunas / 2; ++j) {
            int* a = linha + j;
            int* b = linha + (colunas - 1 - j);
            int temp = *a;
            *a = *b;
            *b = temp;
        }
    }
}

// Inverte as linhas verticalmente
void inverterLinhas(Vetor matriz, int linhas, int colunas) {
    int* p = &matriz[0][0];
    for (int i = 0; i < linhas / 2; ++i) {
        int* linhaA = p + i * TAM;
        int* linhaB = p + (linhas - 1 - i) * TAM;
        for (int j = 0; j < colunas; ++j) {
            int temp = *(linhaA + j);
            *(linhaA + j) = *(linhaB + j);
            *(linhaB + j) = temp;
        }
    }
}
