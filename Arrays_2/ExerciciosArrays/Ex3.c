#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
//Verifica se há 2 argumentos
    if(argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
// verifica se o segundo argumento possui 26 caracteres
    else if(strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

//Isola cada caracter do segundo argumento, atribuindo valores a cada posições da chave
    for(int i = 0, n = strlen(argv[1]); i < n; i++)
    {
//Verificar se o segundo argumento possui números
        if(isdigit(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }
/*Criei um nova variável "j"com as mesmas caracteríticas de "i", a fim de possibilitar
a comparação da posição "i" da chave com as demais posições "j" da chave e verificar se a letras se repetem*/
        for(int j = 0, m = strlen(argv[1]); j < m; j++)
        {
/*Se a subtração de 2 posições for "0" ou "32, significa que os caracteres são iguais
ou diferem apenas maiúscula e minúscula, pois possuem o mesmo valor na tabela ASCII.
Precisei acrescenta a condição  "i != j", porque ao se comprara a mesma posição com certeza as letras serão iguais e nesse caso não se deve apontar nenhum erro*/
            if(i != j && argv[1][i] - argv[1][j] == 0)
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
            else if(i != j && argv[1][i] - argv[1][j] == 32)
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }

string text = get_string("plaintext: ");
    printf("ciphertext: ");
    for(int k = 0, m = strlen(text); k < m; k++)
    {
/*Para identificar a posição da chave (0 a 25) que corresponde a letra do plaintext,
utiliza-se o valor da letra na tabela ASCII e subtrai 97 (minúscula) ou 65 (maiúscula).
Assim, sendo "text[k]" uma letra do plaintext e "argv[1][q]" o valor correspondente dessa letra na minha chave,  "q" precisa ser "text[k] - 97" ou "text[k] - 65" para ter a posição correspondente de 0 a 25 da chave*/
        if(islower(text[k]))
        {
            printf("%c", tolower((argv[1][(text[k]) - 97])));
        }
        else if(isupper(text[k]))
        {
            printf("%c", toupper((argv[1][(text[k]) - 65])));
        }
        else
        {
            printf("%c", text[k]);
        }
    }
    printf("\n");
    return 0;
}