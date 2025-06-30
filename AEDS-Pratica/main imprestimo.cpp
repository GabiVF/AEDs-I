/* Unifal - Alfenas
 * File: main.cpp
 * Author: Gabriela Vinha Feitosa
 * Created on 25 de março de 2025, 11:25
 * AEDs prática - Paulo Bressan
 * objetivo: avaliar o nível de renda e histórico de creditos do usuário para permitir ou não o imprestimo 
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {


    float idade, renda, statusnome, parcelasatual, parcelasdois;

    printf("sistema de aprovação de imprestimo");

    //solicitação da idade
    printf("\n\tQual a sua idade? ");
    scanf("%f", &idade);

    //crédito do usuário
    printf("\n\tQual a sua renda mensal? ");
    scanf("%f", &renda);

    //status do nome
    printf("\n\tO seu nome está negativado? (digite 1 para sim e 0 para não)");
    scanf("%f", &statusnome);

    //parcelas em atraso
    printf("\n\tQuantas parcelas estão atrasadas atualmente? ");
    scanf("%f", &parcelasatual);

    //parcelas em atraso em anos anteriores
    printf("\n\tQuantas parcelas foram atrasadas nos ultimos 2 anos? ");
    scanf("%f", &parcelasdois);

    //condições de crédito
    if (idade < 18 or idade > 70 or renda < 2000 or statusnome == 1) {
        printf("\n\tSeu imprestimo foi negado");
    } else {
        if (renda >= 2000 and renda < 5000 and parcelasatual <= 2) {
            printf("\n\tVocê pode fazer um Empréstimo de Baixo Valor (até R$ 5.000,00)");
        }
        if (renda >= 5000 and renda < 10000 and parcelasdois <= 4 and parcelasatual == 0) {
            printf("\n\tVocê pode fazer um Empréstimo de Médio Valor (até R$ 20.000,00)");
        }
        if (renda > 10000 and parcelasdois == 0) {
            printf("\n\tVocê pode fazer um Empréstimo de Alto Valor (acima de R$ 20.000,00)");
        } else {
            printf("\n\tSeu imprestimo foi negado");
        }
    }


    return 0;
}
