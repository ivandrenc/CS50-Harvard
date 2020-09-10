// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <strings.h>  //strcasecmp()
#include "dictionary.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

int cuenta_palabras = 0;

// Hash table
node *table[N];


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *n2 = table[hash(word)];


    if (strcasecmp(n2->word, word) == 0)  //if matches, the function returns 0. so true
    {
        return true;
    }

    while (n2->next != NULL)
    {
        n2 = n2->next;
        if (strcasecmp(n2->word, word) == 0)
        {
            return true;
        }

    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash_code = (int) tolower(word[0]) - 97;   // -97 to have a range of 0 until 25 in ascii - decimal
    return hash_code;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r"); //we open de file so to read whats in there

    if (file == NULL)
    {
        printf("Error opening file\n");
        return false;
    }

    char *palabra = malloc(LENGTH);  //we allocate memory in size of length

    if (palabra == NULL)
    {
        return false;
    }



    while ((fscanf(file, "%s", palabra)) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, palabra);

        //we point now to the array corresponding the index that we get from hash function
        //checking the first carachter of the word to organize it in the array.
        n->next = table[hash(palabra)];

        table[hash(palabra)] = n;

        //equivalent in the videos as: list = n; to set the value
        //of the beginning of the array


        cuenta_palabras++;

    }
    fclose(file);
    free(palabra);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)  //apparently while compiling this is always true
{
    return cuenta_palabras;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *tmp;
    node *n3;

    for (int i = 0; i < 26; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }

        n3 = table[i];  //n3 has access to the node of table[i]
        tmp = n3;  //here tmp has also access to n3

        while (n3->next != NULL)
        {
            n3 = n3->next;
            free(tmp);
            tmp = n3;

        }
        free(n3);  //free the whole table[i]
    }
    return true;
}
