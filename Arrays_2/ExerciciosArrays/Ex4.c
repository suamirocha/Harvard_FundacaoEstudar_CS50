#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if(score1 == score2)
    {
        printf("Tie!");
    }
    else if(score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else
    {
        printf("Player 2 wins!");
    }
    printf("\n");
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int sum = 0;
    for(int i = 0, n = strlen(word); i < n; i++)
    {
/*Para identificar a posição do array POINTS[0 a 25] que corresponde a letra do "word", utiliza-se o valor da letra na tabela ASCII e subtrai 97 (minúscula) ou 65 (maiúscula). Assim, sendo "word[i]" uma letra e "POINTS[q]" o valor atribuído a essa letra no Scrabble, "q" precisa ser "word[i] - 97 (minúscula)" ou "word[i] - 65 (maiúscula)" para ter a posição correspondente de 0 a 25 no array POINTS[]*/
        if(islower(word[i]))
        {
//Esse loop soma o valor de cada letra minúscula com base no valor correspondente do array POINTS[]
            sum = sum + POINTS[(word[i] - 97)];
        }
        else if(isupper(word[i]))
        {
//Esse loop soma o valor de cada letra maiúscula com base no valor correspondente do array POINTS[]
            sum = sum + POINTS[(word[i] - 65)];
        }
    }
    printf("%i\n", sum);
    return sum;
}