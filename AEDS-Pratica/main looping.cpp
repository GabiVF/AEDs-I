/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.007
 *
 * Created on 27 de março de 2025, 09:36
 */

#include <cstdlib>
#include <stdio.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int nota1;
    
    printf("digite a 1ª nota:");
    scanf("%d",&nota1);
    
    
    while (nota1 < 0 or nota1 > 10){
        printf("Valor inválido.");
        printf("digite novamete");
        scanf("%d", &nota1);
    }

    
    
    return 0;
}

