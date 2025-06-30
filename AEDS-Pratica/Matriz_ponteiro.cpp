#include <iostream>
#include <stdio.h>
#include "Matrizes.h"

using namespace std;

int main() {
    Vetor m;
    Vetor mt; // Matriz transposta
    int opção;

    cout << "quantas linhas e colunas terá a matriz? ";
    int linhas, colunas;
    cin >> linhas >> colunas;
    if (linhas > TAM || colunas > TAM) {
        cout << "Erro: tamanho máximo da matriz é " << TAM << "x" << TAM << endl;
        return 1;
    }
    cout << "Digite os valores da matriz:" << endl;
    EscreverMatriz(m, linhas, colunas);

    cout << "Matriz original:" << endl;
    MostrarMatriz(m, linhas, colunas);
    

    cout << "Escolha uma opção:" << endl;
    cout << "1. Multiplicar a matriz por número" << endl;
    cout << "2. Transpor a matriz" << endl;
    cout << "3. Inverter colunas" << endl;
    cout << "4. Inverter linhas" << endl;
    cout << "5. Sair" << endl;
    cin >> opção;

    switch (opção)
    {
    case 1:
        cout << "Digite o valor para multiplicar a matriz: ";
        int valor;
        cin >> valor;
        multiplicarMatrizPorValor(m, linhas, colunas, valor);
        MostrarMatriz(m, linhas, colunas);
        break;
    case 2:
        transporMatriz(m, mt, linhas, colunas);
        cout << "Matriz transposta:" << endl;
        MostrarMatriz(mt, colunas, linhas);
        break;
    case 3:
        inverterColunas(m, linhas, colunas);
        cout << "Matriz com colunas invertidas:" << endl;
        MostrarMatriz(m, linhas, colunas);
        break;
    case 4:
        inverterLinhas(m, linhas, colunas);
        cout << "Matriz com linhas invertidas:" << endl;
        MostrarMatriz(m, linhas, colunas);
        break;
    case 5:
        cout << "Saindo" << endl;
        return 0;   
    default:
        cout << "Opção inválida!" << endl;
        break;
    }

    return 0;
}
