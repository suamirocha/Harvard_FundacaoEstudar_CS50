#include <cs50.h>
#include <stdio.h>
#include <math.h>

//25,10,5 e 1 são os valores das moedas
float troco;
int cent, cont;
int m25, m10, m5, m1;
int main(void) {
    do {
    troco = get_float ("Qual é o valor do troco? \n");
    }
    while (troco <= 0);

    //passando o valor de Real para Centavos

    cent = troco*100;

    printf ("O valor do troco a ser devolvido é: %i \n", cent);

    //Uma variável int para cada tipo de moeda

    m25=25;
    m10=10;
    m5=5;
    m1=1;
    cont=0;

    // Subtrai o valor do troco com cada tipo de moeda e incrementa o contador

    while (cent >= m25) {
        cont++;
        cent = cent - m25;
    }
     while (cent >= m10) {
        cont++;
        cent = cent - m10;
    }
     while (cent >= m5) {
        cont++;
        cent = cent - m5;
    }
     while (cent >= m1) {
        cont++;
        cent = cent - m1;
    }

  //Ao final teremos a quantidade de moedas utilizadas

    printf("A quantidade de moedas utilizadas no troco foi: %i \n", cont);
}