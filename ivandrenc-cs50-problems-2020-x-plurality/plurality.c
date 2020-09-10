#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9  //es una constante

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++) //inicializa el array con nombres y los votos empezando desde 0.
    {
        candidates[i].name = argv[i + 1]; //+ 1 porque argv[0] es ./plurality
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: "); //obtener numero de votantes

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n"); //esto pasa si es falso el valor de la funcion vote
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int b = 0; b < candidate_count; b++)
    {
        if (strcmp(name, candidates[b].name) == 0)
        {
            candidates[b].votes++;
            return true;
        }

    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    
    typedef struct
    {
        string name;
        int votes;
    }
    ganadores;

    int candidatos = candidate_count; //numero de candidatos
    int l = 1;
    ganadores ganador[candidatos];

    for (int j = 0; j < candidatos - 1; j++)  // 0 --- 1
    {
        if (candidates[j].votes < candidates[l].votes)
        {
            ganador[j].name = candidates[l].name;
            ganador[j].votes = candidates[l].votes;
            l++;

        }
        else
        {
            ganador[j].name = candidates[j].name;
            ganador[j].votes = candidates[j].votes;
            l++;
                
        }
            
            
    }
        
        
        
    if (ganador[0].votes > ganador[candidatos - 2].votes)
        
    {
        printf("%s\n", ganador[0].name); //si el ganador se encuentra en la izq
    }
    else if (ganador[0].votes == ganador[candidatos - 2].votes && ganador[0].name != ganador[candidatos - 2].name)
    {
              
        printf("%s\n", ganador[0].name);
        printf("%s\n", ganador[candidatos - 2].name); // si hay un empate de 2
    }
    else if (ganador[0].votes == ganador[candidatos - 2].votes && ganador[0].name != ganador[candidatos - 2].name
             && ganador[0].votes == candidates[candidatos - 1].votes && ganador[0].name != candidates[candidatos - 1].name)
    {
        printf("%s\n", ganador[0].name);
        printf("%s\n", candidates[candidatos - 1].name);
        printf(" jaja %s\n", ganador[candidatos - 2].name); // si hay un empate de 3
    }
    else if (ganador[0].votes == ganador[candidatos - 2].votes && ganador[0].name == ganador[candidatos - 2].name)
    {
        printf("%s\n", ganador[0].name); //si hay un ganador pero con resultados iguales de votos
    }
    else
    {
        printf("%s\n", ganador[candidatos - 2].name); //si el ganador esta a la izq
    }
            
       
}   


