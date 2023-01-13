#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int v_inicial, v_final, i = 0;
    // TODO: Solicite o valor inicial ao usuário
    do
    {
        v_inicial = get_int("Start size: ");
    }
    while (v_inicial < 9);
    // TODO: Solicite o valor final ao usuário
    do
    {
        v_final = get_int("End size: ");
    }
    while (v_final < v_inicial);
    // TODO: Calcule o número de anos até o limite
    while (v_inicial < v_final)
    {
        v_inicial += (v_inicial / 3) - (v_inicial / 4);
        i++;
    }
    // TODO: Imprima o número de anos
    printf("Years: %i\n", i);

}