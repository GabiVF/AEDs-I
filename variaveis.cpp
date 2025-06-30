#include <cstdlib>
#include <iostream>
#include<string.h>
#include <fstream>
#include <time.h>
#include <stdio.h>

using namespace std;

/*15/05/2025
 * Gabriela Vinha Fitosa
 * AEDs-pratica Unifal
 */
int main(int argc, char** argv) {

    int TAM = 100;

    // declaração do vetor

    int alturas [TAM];
    float media, busca;

    // variavel de auxilio

    int i, cima, baixo, opcao;


    // abrir o arquivo para leitura
    ofstream arquivo("Entrada.txt");
    if (!arquivo.is_open()) {
        cout << "\nErro: Arquivo não encontrado.\n";
        return 1;
    }

//Gerar numeros aleatorios
srand(time(NULL));
for (i = 0; i < TAM; i++) {
    alturas[i] = rand() % 100 + 1; // Gera números aleatórios entre 1 e 100
    arquivo << alturas[i] << endl; // Escreve os números no arquivo
}
    // leitura do vetor
    for (i = 0; i < TAM; i++) {
        cout << "O " << i + 1 << "º valor é " << alturas [i] << endl;
    }
    // fechar o arquivo para salvar os numeros
    arquivo.close();

    //Cardápio de opções
    do {

        cout << "1-inverter os valores dos vetores (ex: primeiro com o ultimo, segundo com o penultimo e assim segue)" << endl;
        cout << "2- adicione um valor a todos os elementos" << endl;
        cout << "3- adicione um valor a todos os elementos não divisiveis por três" << endl;
        cout << "4- remova do vetor a ocorrencia de um valor" << endl;
        cout << "5- remova do vetor todas as ocorrencias de um valor" << endl;
        cout << "6- inserir um valor no vetor se nao estiver cheio" << endl;
        cout << "7- inserir um valor em uma posiçao determinada" << endl;
        cout << "8- remover todos os valores repetidos de um vetor" << endl;

        cin >> opcao;

        switch (opcao) {

            case 1:
                for (i = 0; i < TAM / 2; i++) {
                    float temp = alturas[i];
                    alturas[i] = alturas[TAM - 1 - i];
                    alturas[TAM - 1 - i] = temp;
                }
                cout << "Vetor invertido:\n";
                for (i = 0; i < TAM; i++) {
                    cout << "O " << i + 1 << "º valor é " << alturas [i] << endl;
                }
                break;

            case 2:
                int valor;

                cout << "Qual o valor deseja adcionar?" << endl;
                cin >> valor;
                for (i = 0; i < TAM; i++) {
                    alturas [i] += valor;
                }
                for (i = 0; i < TAM; i++) {
                    cout << "O " << i + 1 << "º valor é " << alturas [i] << endl;
                }
                break;

            case 3:

                cout << "Qual o valor deseja adcionar?" << endl;
                cin >> valor;
                for (i = 0; i < TAM; i++) {
                    if (alturas[i] % 3 != 0) {
                        alturas [i] += valor;
                    }
                }
                for (i = 0; i < TAM; i++) {
                    cout << "O " << i + 1 << "º valor é " << alturas [i] << endl;
                }
                break;


            case 4:
                
                cout << "Qual o valor que deseja remover?" << endl;
                cin >> valor;
                for (i = 0; i < TAM; i++) {
                    if (alturas[i] == valor){
                       alturas[i] = alturas[i - valor];
                    }
                    for (i = 0; i < TAM; i++) {
                    cout << "O " << i + 1 << "º valor é " << alturas [i] << endl;
                }
                   
                } break;
            case 5: 
                cout << "Qual o valor que deseja remover?" << endl;
                cin >> valor;
                for (i = 0; i < TAM; i++) {
                    if (alturas[i] == valor){
                       alturas[i] = 0;
                    }
                    for (i = 0; i < TAM; i++) {
                    cout << "O " << i + 1 << "º valor é " << alturas [i] << endl;
                }
                   
                } break;
            case 6:
                cout << "Qual o valor que deseja adicionar?" << endl;
                cin >> valor;
                if (TAM < 10) {
                    alturas[TAM] = valor;
                    TAM++;
                } else {
                    cout << "Vetor cheio!" << endl;
                }
                for (i = 0; i < TAM; i++) {
                    cout << "O " << i + 1 << "º valor é " << alturas [i] << endl;
                }
                break;
            
            case 7: 
                cout << "Qual o valor que deseja adicionar?" << endl;
                cin >> valor;
                cout << "Qual a posição que deseja adicionar?" << endl;
                cin >> i;
                if (i >= 0 && i < TAM) {
                    alturas[i] = valor;
                } else {
                    cout << "Posição inválida!" << endl;
                }
                for (i = 0; i < TAM; i++) {
                    cout << "O " << i + 1 << "º valor é " << alturas [i] << endl;
                }
                break;  
            case 8:
                cout << "Removendo valores repetidos..." << endl;
                for (i = 0; i < TAM; i++) {
                    for (int j = i + 1; j < TAM; j++) {
                        if (alturas[i] == alturas[j]) {
                            for (int k = j; k < TAM - 1; k++) {
                                alturas[k] = alturas[k + 1];
                            }
                            TAM--;
                            j--;
                        }
                    }
                }
                cout << "Valores repetidos removidos." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
                for (i = 0; i < TAM; i++) {
                    cout << "O " << i + 1 << "º valor é " << alturas [i] << endl;
                }
            
            }
    }
    
 while (opcao != 0);
    
    return 0;
}
