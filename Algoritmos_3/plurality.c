#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Número máximo de candidatos
#define MAX 9

// Candidatos têm nome e contagem de votos
typedef struct
{
    string name;
    int votes;
}
candidate;

// Matriz de candidatos
candidate candidates[MAX];

// Número de candidatos
int candidate_count;

// Protótipos de funções
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Verifique se há uso inválido
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Preencher array de candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Percorra todos os eleitores
    for (int i = 0; i < voter_count; i++)
    {
       string name = get_string("Vote: ");

        // Verifique se há voto inválido
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Mostrar vencedor da eleição
    print_winner();
}

// Atualizar totais de votos dado um novo voto
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count ; i++)
    {
        if (strcmp(name, candidates[i].name) == 0){
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Imprima o vencedor (ou vencedores) da eleição
void print_winner(void)
{
    // TODO
    int aux =  0;
    for (int i = 0; i < candidate_count ; i++)
    {
        if (candidates[i].votes > aux)
        {
            aux = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count ; i++)
    {
        if (candidates[i].votes == aux && aux != 0)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}