#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    char digit;

    if (argc > 2 || argc == 1)  //si el numero de argumentos es mayor a 2 o igual a 1, expresar error.
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }
    else  //sino, comprobar que todos los digitos del primer indice [1] sean numeros
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            digit = argv[1][i]; //recorrido de digitos por indices
            if (isdigit(digit) == 0)  //comprobacion de digitos que sean caracteres. Si es igual a cero es un caracter no numerico.
            {
                printf("Usage: ./caesar key\n");
                return (1);
            }
        }
    }

    string plaintext = get_string("plaintext: ");  //texto a encriptar
    int ciphertext[(strlen(plaintext))];  //texto encriptado. Almacenado en array de caracteres.
    printf("ciphertext: ");

    char alphabetM[] = {'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'};

    for (int a = 0, c = strlen(plaintext); a < c; a++) //recorrido de caracteres a transformar.
    {
        if (isalpha(plaintext[a]) != 0)  //es un caracter alfanumerico?
        {
            if (isupper(plaintext[a]) != 0)  //es un caracter mayuscula?
            {
                ciphertext[a] = ((int)plaintext[a] + atoi(argv[1])) % 26;  //si es una mayuscula
                printf("%c", (char)alphabetM[ciphertext[a]]); //si
            }
            else
            {
                ciphertext[a] = (((int)plaintext[a] - 32 + atoi(argv[1])) % 26); //sino es una minuscula
                printf("%c", tolower((char)alphabetM[ciphertext[a]]));
            }

        }
        else
        {
            printf("%c", (plaintext[a]));
        }

    }

    printf("\n");

}
