#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }
    
    bool copia = false;
    char *filename = malloc(8);
    FILE *memory = fopen(argv[1], "r");  //abrimos la memoria
    if (memory == NULL)
    {
        return 1;
    }
    FILE *jpeg = NULL;
    int num = 0;
    BYTE *buffer = malloc(512 * sizeof(BYTE));

    while (fread(buffer, 512, 1, memory) == 1) //lea hasta el final
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)  //es jpeg?
        {
            if (copia == false)  //si no esta abierto por primera vez
            {
                copia = true;  //poner en true para hacer saber que esta abierto uno
                num = num + 1;
                sprintf(filename, "%03i.jpg", num - 1);
                jpeg = fopen(filename, "w");
                fwrite(buffer, 512, 1, jpeg);

            }
            else  //significa que ya hay un bloque abierto
            {
                fclose(jpeg);
                num = num + 1;
                sprintf(filename, "%03i.jpg", num - 1);
                jpeg = fopen(filename, "w");
                fwrite(buffer, 512, 1, jpeg);



            }

        }
        else
        {
            if (copia)
            {
                fwrite(buffer, 512, 1, jpeg);  //que siga copiando
            }
            else
            {
                continue;
            }

        }
    }
    fclose(jpeg);
    fclose(memory);
    free(filename);


}
