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
    else if (strlen(argv[1]) < 26 || strlen(argv[1]) > 26)
    {
        printf("Key must contain 26 characters.\n");
        return (1);
    }
    else  //sino, comprobar que todos los digitos del primer indice [1] sean numeros
    {
        for (int i = 0, n = strlen(argv[1]), counter = 1; i < n; i++)
        {
            digit = argv[1][i]; //recorrido de digitos por indices
            if (isdigit(digit) != 0)  //comprobacion de digitos que sean caracteres. Si no es igual a cero es un caracter no numerico.
            {
                printf("Usage: ./caesar key\n");
                return (1);
            }

            for (int j = i + 1; j < strlen(argv[1]); j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    counter++;
                }
                if (counter > 1)
                {
                    printf("Duplicated found\n");
                    return 1;
                }

            }
        }
    }


    string plaintext = get_string("plaintext: ");  //texto a encriptar
    int ciphertext[(strlen(plaintext))];  //texto encriptado. Almacenado en array de caracteres.
    printf("ciphertext: ");

    char alphabetM[] = {argv[1][13], argv[1][14], argv[1][15], argv[1][16], argv[1][17], argv[1][18], argv[1][19], argv[1][20], argv[1][21], argv[1][22], argv[1][23], argv[1][24], argv[1][25], argv[1][0], argv[1][1], argv[1][2], argv[1][3], argv[1][4], argv[1][5], argv[1][6], argv[1][7], argv[1][8], argv[1][9], argv[1][10], argv[1][11], argv[1][12]};

    for (int a = 0, c = strlen(plaintext); a < c; a++) //recorrido de caracteres a transformar.
    {
        if (isalpha(plaintext[a]) != 0)  //es un caracter alfanumerico?
        {
            if (isupper(plaintext[a]) != 0)  //es un caracter mayuscula?
            {
                ciphertext[a] = ((int)plaintext[a] + atoi(argv[1])) % 26;  //si es una mayuscula
                printf("%c", toupper((char)alphabetM[ciphertext[a]])); //si
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
