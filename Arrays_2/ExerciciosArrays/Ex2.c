#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
//Verifica se há 2 argumentos
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for(int i = 0, n = strlen(argv[1]); i < n; i++)
    {
//Verificar se o segundo argumento possui letras
        if(isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

//a função "atoi" da biblioteca "stdlib.h" converte uma "string" em "int"
    int k = atoi(argv[1]);
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    for(int j = 0, n = strlen(text); j < n; j++)
    {
/*Ao subtrair 97 ou 65, obtem-se a posição de 0 a 25 do alfabeto. Em seguida, aplica-se a fórmula de Caesar.
Depois acrescenta-se os 97 ou 65 que foram retirados inicialmente, para se obter novamente o valor da tabela ASCII
correspondente ao valor cifrado*/
        if(islower(text[j]))
        {
            printf("%c", (((text[j] - 97) + k) % 26) + 97);
        }
        else if(isupper(text[j]))
        {
            printf("%c", (((text[j] - 65) + k) % 26) + 65);
        }
        else
        {
            printf("%c", text[j]);
        }
    }
    printf("\n");
    return 0;
}