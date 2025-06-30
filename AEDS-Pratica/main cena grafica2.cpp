/* 
 File: main.cpp
 * Author: Gabriela Vinha Feitosa
 * Código para ler um arquivo com formas geométricas e calcula a area e volume total.
 * Created on 18 de abril de 2025
 */

#include <cstdlib>
#include<stdio.h>
#include<string.h>
#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {

    string figura = "";
    float area = 0, volume = 0, areatotal = 0, volumetotal = 0, pi = 3.14;
    int forma = 0;

    //Buscar o documento de texto com os dados das formas
    ifstream arquivo("cenagrafica.txt");
    if (!arquivo.is_open()) {
        cout << "\nErro: Arquivo não encontrado.\n";
        return 1;
    }

    //Buscar a área e o volume das formas, até encontrar a palvra de encerramento "fim"
    while (figura != "fim") {
        arquivo >> figura;
        //Verificando verificando qual a forma, seu volume e área e somando os valores
        if (figura == "Quadrado") {
            arquivo >> area;
            areatotal += area;
        } else if (figura == "Retângulo") {
            arquivo >> area;
            areatotal += area;
        } else if (figura == "Círculo") {
            arquivo >> area;
            areatotal += area;
        } else if (figura == "Cubo") {
            arquivo >> volume;
            volumetotal += volume;
        } else if (figura == "Esfera") {
            arquivo >> volume;
            volumetotal += volume;
        } else if (figura == "Cilindro") {
            arquivo >> volume;
            volumetotal += volume;
        } else if (figura == "Cone") {
            arquivo >> volume;
            volumetotal += volume;
        }

    }

    //Mostrar a àrea e o volume total da cena gráfica
    cout << "\n Área total da cena gráfica: " << areatotal << endl;
    cout << "\n Volume total da cena gráfica: " << volumetotal << endl;

    return 0;
}