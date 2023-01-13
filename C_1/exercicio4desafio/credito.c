#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool checksum(long card, int qtdDigits);
int cardStart(long card, int qtdDigits);

int main(void)
{
    // Coleta número de cartão de 13 à 16 digitos
    long card;
    do
    {
        card = get_long("Número do Cartão: ");
    }
    while (card < 0 || card > 9999999999999999);

    // Calcula qnts digitos tem o cartão
    int qtdDigits = log10(card) + 1;

    // Dois primeiros digitos do cartão
    int start = cardStart(card, qtdDigits);

    // Para satisfazer a requisição do teste.
    if (qtdDigits < 13)
    {
        printf("INVALID\n");
    }
    // American Express (15n), starts with 34, 35 or 37
    else if (qtdDigits == 15 && checksum(card, qtdDigits) == true && (start == 34 || start == 35 || start == 37))
    {
        printf("AMEX\n");
    }
    // Visa (13n or 16n), starts with 4
    else if ((qtdDigits == 13 || qtdDigits == 16) && checksum(card, qtdDigits) == true && start >= 40 && start <= 49)
    {
        printf("VISA\n");
    }
    // MasterCard (16n), starts with 51, 52, 53, 54, 55
    else if (qtdDigits == 16 && checksum(card, qtdDigits) == true && (start >= 51 && start <= 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
// Verificar o algorítmo de Luhn
bool checksum(long card, int qtdDigits)
{
    int soma = 0;

    for (int i = 0; i < qtdDigits; i++)
    {
        // Posição da casa decimal
        double position = pow(10, i + 1);
        // Divisor para 1 digito
        double divider = pow(10, i);
        // Seleciona o digito
        int digit = (card % (long) position) / (long) divider;

        // seleciona o 2º digito para o calculo
        if (i % 2 != 0)
        {
            digit = digit * 2;

            // reduz para a soma dos digitos se superior a 10
            if (digit > 9)
            {
                digit = digit % 10 + (digit % 100) / 10;
            }
        }

        soma = soma + digit;
    }

    if (soma % 10 != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Seleciona os dois primeiros digitos do cartão.
int cardStart(long card, int qtdDigits)
{
    double position = pow(10, qtdDigits);
    double divider = pow(10, qtdDigits - 2);
    int start = (card % (long) position) / (long) divider;
    return start;
}