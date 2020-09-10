#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0; //declaracion
    do
    {
        height = get_int("height: "); //pido la altura
    }
    while (height <= 0 || height > 8); //restriccion de numeros solo de 0-8



    int counter = 0; //counter para restar a los puntos cuando van bajando 

    for (int i = 0; i < height; i++)
    {
        counter = counter + 1;
        for (int j = height - counter; j > 0; j--) //aqui se hace por cada linia un punto menos
        {
            printf(" ");
        }

        for (int a = 1; a <= counter; a++) //aca se empieza desde un # hasta tener muchos como la variable height
        {
            printf("#");
        }
        printf("\n"); //salto de linia
    }


}

