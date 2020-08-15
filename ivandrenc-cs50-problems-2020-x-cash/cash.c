#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change = 0; //declaracion de variables
    do
    {
        change = round(get_float("Change owed: ") * 100); //redondea el numero
    }
    while (change <= 0);

    int rest = change; 
    int coins = 0;

    if (change >= 25) //se compureba primero con el centavo mas grande y se va reduciendo el monto a cambiar 
    {
        do
        {
            rest = rest - 25;
            coins = coins + 1;
        }
        while (rest >= 25);
    }

    if (rest >= 10) // monto a cambiar en monedas de 10
    {
        do
        {
            rest = rest - 10;
            coins = coins + 1;
        }
        while (rest >= 10);
    }

    if (rest >= 5) //monto a cambiar en monedas de 5
    {
        do
        {
            rest = rest - 5;
            coins = coins + 1;
        }
        while (rest >= 5);
    }

    if (rest >= 1) //monto a cambiar en monedas de 1
    {
        do
        {
            rest = rest - 1;
            coins = coins + 1;
        }
        while (rest >= 1);
    }


    printf("%i\n", coins); //restante de cuantas monedas se deberian usar
}
