#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int rgbtGrey = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3;
            image[i][j].rgbtBlue = rgbtGrey;
            image[i][j].rgbtRed = rgbtGrey;
            image[i][j].rgbtGreen = rgbtGrey;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if(sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            if(sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaRed;
            }

            if(sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaRed;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            tmp[j] = image[i][j];
        }
        for(int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tmp[width - 1 - j].rgbtRed;
            image[i][j].rgbtGreen = tmp[width - 1 - j].rgbtGreen;
            image[i][j].rgbtBlue = tmp[width - 1 - j].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            tmp[h][w] = image[h][w];
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int count = 0;
            int Red = 0;
            int Green = 0;
            int Blue = 0;

            for(int m = 0; m < 3; m++)
            {
                for(int n = 0; n < 3; n++)
                {
                    if(i - 1 + m < 0 || i - 1 + m == height)
                    {
                        continue;
                    }

                    if(j - 1 + n < 0 || j - 1 + n == width)
                    {
                        continue;
                    }

                    Red += tmp[i - 1 + m][j - 1 + n].rgbtRed;
                    Green += tmp[i - 1 + m][j - 1 + n].rgbtGreen;
                    Blue += tmp[i - 1 + m][j - 1 + n].rgbtBlue;
                    count++;
                }
            }
            image[i][j].rgbtRed = Red / count;
            image[i][j].rgbtGreen = Green / count;
            image[i][j].rgbtBlue = Blue / count;
        }
    }
    return;
}
