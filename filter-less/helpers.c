#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Получаем среднее значение трёх цветов
            BYTE average = round(
                (image[i][j].rgbtBlue + 
                 image[i][j].rgbtGreen + 
                 image[i][j].rgbtRed) / 3
            );
            
            // Устанавливаем все компоненты в среднее значение
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
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
            image[i][j].rgbtBlue = 0;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
            for (int i = 0; i < height; i++)
    {
        

        // RGBTRIPLE sfawwa[height][width] ;

        
        // for (int j = width, k = 0; k <= width; j--, k++)
        // {
        //     sfawwa[i][k] = image[i][j];
        // }


        for (int j = 0, k=width-1; j < width; j++, k--)
        {
            if (j < k)
            {
                break;
            }
            

            image[i][j] = image[i][width - j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

        RGBTRIPLE sfawwa[height][width];

    for (int i = 1; i < height; i++)
    {


        
        for (int j = 1; j < width; j++)
        {
  BYTE averageRed = round(
                        
                    (

                        image[i-1][j-1].rgbtRed +
                        image[i-1][j].rgbtRed +
                        image[i-1][j+1].rgbtRed +

                        image[i][j-1].rgbtRed +
                        image[i][j].rgbtRed +
                        image[i][j+1].rgbtRed +

                        image[i+1][j-1].rgbtRed +
                        image[i+1][j].rgbtRed+
                        image[i+1][j+1].rgbtRed
                    ) / 9

                
                );
                BYTE averageGreen = round(
                      (

                        image[i-1][j-1].rgbtGreen +
                        image[i-1][j].rgbtGreen +
                        image[i-1][j+1].rgbtGreen +

                        image[i][j-1].rgbtGreen +
                        image[i][j].rgbtGreen +
                        image[i][j+1].rgbtGreen +

                        image[i+1][j-1].rgbtGreen +
                        image[i+1][j].rgbtGreen+
                        image[i+1][j+1].rgbtGreen
                    ) / 9
                );BYTE averageBlue = round(
                      (

                        image[i-1][j-1].rgbtBlue +
                        image[i-1][j].rgbtBlue +
                        image[i-1][j+1].rgbtBlue +

                        image[i][j-1].rgbtBlue +
                        image[i][j].rgbtBlue +
                        image[i][j+1].rgbtBlue +

                        image[i+1][j-1].rgbtBlue +
                        image[i+1][j].rgbtBlue+
                        image[i+1][j+1].rgbtBlue
                    ) / 9
                );


                image[i][j].rgbtRed = averageRed ;
                image[i][j].rgbtGreen = averageGreen ;
                image[i][j].rgbtBlue = averageBlue ;

        //    image[i][j].rgbtRed = image[i][j].rgbtRed;
        //      image[i][j].rgbtGreen = sfawwa[i][j].rgbtGreen;
        //      image[i][j].rgbtBlue = sfawwa[i][j].rgbtBlue;
            

        }



            for (int j = 0; j < width; j++)
            {
            //  image[i][j].rgbtRed = sfawwa[i][j].rgbtRed;
            //  image[i][j].rgbtGreen = sfawwa[i][j].rgbtGreen;
            //  image[i][j].rgbtBlue = sfawwa[i][j].rgbtBlue;

                /* code */
            }
            
    }
    return;
}
