#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round(((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) + 0.1) / 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;


        }
    }

    /*
    sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
     sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    */

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int r = 0;
    int g = 0;
    int b = 0;


    for (int i = 0; i < height; i++)
    {
        int edge = width;
        for (int j = 0; j < width / 2; j++)
        {
            edge = edge - 1;
            //printf("edge: %i\n", edge);

            r = image[i][j].rgbtRed;
            g = image[i][j].rgbtGreen;
            b = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][edge].rgbtRed;
            image[i][j].rgbtGreen = image[i][edge].rgbtGreen;
            image[i][j].rgbtBlue = image[i][edge].rgbtBlue;

            image[i][edge].rgbtRed = r;
            image[i][edge].rgbtGreen = g;
            image[i][edge].rgbtBlue = b;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image2[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0)  // 1era fila
            {

                if (i == 0 && j == 0)  //significa q esta en el primer pixel ESQUINA 1
                {
                   image2[i][j].rgbtRed = round((image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i][j].rgbtRed
                                                 + 0.1) / 4);
                   image2[i][j].rgbtGreen = round((image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + 
                                                   image[i][j].rgbtGreen + 0.1) / 4);
                   image2[i][j].rgbtBlue = round((image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue +
                                                  image[i][j].rgbtBlue +0.1) / 4);
                }
                else if (i == 0 && j == width - 1)  //significa q esta en el ultimo pixel de la primera fila ESQUINA 2
                {
                   image2[i][j].rgbtRed = round((image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i][j].rgbtRed + 0.1) / 4);
                   image2[i][j].rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j].rgbtGreen + 0.1) / 4);
                   image2[i][j].rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j].rgbtBlue + 0.1) / 4);

                }
                else  //significa que esta en la primera fila y no en las esquinas
                {
                   image2[i][j].rgbtRed = round((image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i][j +
                                                 1].rgbtRed + image[i][j].rgbtRed + 0.1) / 6);
                   image2[i][j].rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen +
                                                   image[i][j + 1].rgbtGreen + image[i][j].rgbtGreen + 0.1) / 6);
                   image2[i][j].rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue +
                                                  image[i][j + 1].rgbtBlue + image[i][j].rgbtBlue + 0.1) / 6);
                }
            }




             else if (i == height - 1)  //ultima fila
             {



                 if (i == height - 1 && j == 0)  //ESQUINA 3
                 {
                    image2[i][j].rgbtRed = round((image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i][j].rgbtRed 
                                                  + 0.1) / 4);
                    image2[i][j].rgbtGreen = round((image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i][j].rgbtGreen 
                                                  + 0.1) / 4);
                    image2[i][j].rgbtBlue = round((image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i][j].rgbtBlue 
                                                  + 0.1) / 4);

               }
               else if (i == height - 1 && j == width - 1)  //ESQUINA 4
               {
                   image2[i][j].rgbtRed = round((image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i][j].rgbtRed
                                                + 0.1) / 4);
                   image2[i][j].rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j].rgbtGreen
                                                + 0.1) / 4);
                   image2[i][j].rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j].rgbtBlue 
                                                + 0.1) / 4);
               }
               else  //significa que esta en la ultima fila pero no en las esquinas
               {
                   image2[i][j].rgbtRed = round((image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + 
                                                 image[i][j + 1].rgbtRed + image[i][j].rgbtRed  + 0.1) / 6);
                   image2[i][j].rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen
                                                   + image[i][j + 1].rgbtGreen + image[i][j].rgbtGreen + 0.1) / 6);
                   image2[i][j].rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                                  image[i][j + 1].rgbtBlue + image[i][j].rgbtBlue + 0.1) / 6);
               }

            }
            else if (j == 0)  //1era columna
            {
                image2[i][j].rgbtRed = round((image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed +
                                              image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i][j].rgbtRed + 0.1) / 6);
                image2[i][j].rgbtGreen = round((image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + 
                                                image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j].rgbtGreen + 0.1) / 6);
                image2[i][j].rgbtBlue = round((image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue +
                                               image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j].rgbtBlue + 0.1) / 6);

            }
            else if (j == width - 1)  // ultima columna
            {
                image2[i][j].rgbtRed = round((image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j -
                                               1].rgbtRed + image[i + 1][j].rgbtRed + image[i][j].rgbtRed + 0.1) / 6);
                image2[i][j].rgbtGreen = round((image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i +
                                               1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j].rgbtGreen + 0.1) / 6);
                image2[i][j].rgbtBlue = round((image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j -
                                               1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j].rgbtBlue + 0.1) / 6);

            }
            else  //normal 3x3
            {
                image2[i][j].rgbtRed = round((image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j -
                                              1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                             image[i][j].rgbtRed + 0.1) / 9);
                image2[i][j].rgbtGreen = round((image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i +
                                                1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j +
                                                        1].rgbtGreen + image[i][j].rgbtGreen + 0.1) / 9);
                image2[i][j].rgbtBlue = round((image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j -
                                               1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue + 
                                               image[i][j].rgbtBlue + 0.1) / 9);


            }
        }
    }

    for (int b = 0; b < height; b++)
    {
        for (int c = 0; c < width; c++)
        {
            image[b][c].rgbtRed = image2[b][c].rgbtRed;
            image[b][c].rgbtGreen = image2[b][c].rgbtGreen;
            image[b][c].rgbtBlue = image2[b][c].rgbtBlue;
        }
    }
    return;
}
