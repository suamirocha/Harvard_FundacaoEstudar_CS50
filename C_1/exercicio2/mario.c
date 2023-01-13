#include <stdio.h>
#include <cs50.h> // Adicionar a biblioteca do CS50

int main(void)
{
    int altura;
    do
    {
        altura = get_int("Altura: ");
    }
    while (altura < 1 || altura > 8);

    // i vale 0, se i for menor que altura continua e adiciona +1 em i
    for (int i = 0; i < altura; i++)
    {
        // j vale 0, se j menor que 3 continua e adiciona +1 em j
        for (int j = 0; j < altura; j++)
        {
            if (i + j < altura -1)
            {
                printf(" ");
            }
            else
            {
                // imprime
                printf("#");

            }

        }
        printf("  #");

        for (int j = 0; j < altura; j++)
        {
            if (i + j > altura -1)
            {

                printf("#");
            }

        }

        // pula uma linha no console e repete a funcao 3 vezes
        printf("\n");


    }
}