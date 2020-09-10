#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string input);
int count_words(string entry);
int count_sentences(string texto);


int main(void)
{
    string text = get_string("Text: ");

    float L = round(count_letters(text) * 100) / count_words(text);
    float S = round(count_sentences(text) * 100) / count_words(text);
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }


}

int count_sentences(string texto)  //funcion para calcular las oraciones
{
    int countSentences = 0;
    for (int c = 0, d = strlen(texto); c < d;
         c++) //la base de este for es que hace un recorrido por cada caracter, revisando que es que cosa.
    {
        if (texto[c] == 46 || texto[c] == 33
            || texto[c] == 63) //no podemos usar ispunct porque en la funcion incluyen mas simbolos que no forman parte del deber
        {
            countSentences++;
        }
    }
    return countSentences;
}

int count_words(string entry)  //funcion para calcular las palabras
{
    int countWords = 1;
    for (int a = 0, b = strlen(entry); a < b; a++)
    {

        if (isblank(entry[a]) != 0) // funcion isblank revisa si el caracter es un espacio o no
        {
            countWords++;
        }

    }
    return countWords;

}

int count_letters(string input)  //funcion para calcular las letras
{
    int counterLetters = 0;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isalpha(input[i]) != 0) // funcion isalpha revisa si es un caracter alfanumerico
        {
            counterLetters++;
        }

    }

    return counterLetters;
}

