#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //calculate the average channel values of the pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3;
            average = round(average);

            //set the channel values to the average
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
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
            int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

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
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width/2) ; j++)
        {
            RGBTRIPLE temp = image[i][j];

            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //make a temp copy of the image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            temp[i][j] = image [i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumblue;
            int sumgreen;
            int sumred;
            float counter;

            sumblue = sumgreen = sumred = counter = 0;

            //right corners
            if (i >= 0 && j >= 0)
            {
                sumred += temp[i][j].rgbtRed;
                sumgreen += temp[i][j].rgbtGreen;
                sumblue += temp[i][j].rgbtBlue;
                counter++;
            }

            if (i - 1 >= 0 && j - 1 >= 0)
            {
                sumred += temp[i-1][j-1].rgbtRed;
                sumgreen += temp[i-1][j-1].rgbtGreen;
                sumblue += temp[i-1][j-1].rgbtBlue;
                counter++;
            }

            //left corners
            if (i >= 0 && j - 1 >= 0)
            {
                sumred += temp[i][j-1].rgbtRed;
                sumgreen += temp[i][j-1].rgbtGreen;
                sumblue += temp[i][j-1].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0 && j >= 0)
            {
                sumred += temp[i-1][j].rgbtRed;
                sumgreen += temp[i-1][j].rgbtGreen;
                sumblue += temp[i-1][j].rgbtBlue;
                counter++;
            }

            //now the edges
            //bottom
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                sumred += temp[i][j+1].rgbtRed;
                sumgreen += temp[i][j+1].rgbtGreen;
                sumblue += temp[i][j+1].rgbtBlue;
                counter++;
            }
            //top
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                sumred += temp[i-1][j+1].rgbtRed;
                sumgreen += temp[i-1][j+1].rgbtGreen;
                sumblue += temp[i-1][j+1].rgbtBlue;
                counter++;
            }
            //left
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                sumred += temp[i+1][j].rgbtRed;
                sumgreen += temp[i+1][j].rgbtGreen;
                sumblue += temp[i+1][j].rgbtBlue;
                counter++;
            }
            //right
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                sumred += temp[i+1][j-1].rgbtRed;
                sumgreen += temp[i+1][j-1].rgbtGreen;
                sumblue += temp[i+1][j-1].rgbtBlue;
                counter++;
            }

            //last but not least, middle pixels
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                sumred += temp[i+1][j+1].rgbtRed;
                sumgreen += temp[i+1][j+1].rgbtGreen;
                sumblue += temp[i+1][j+1].rgbtBlue;
                counter++;
            }

            //average colour
            image[i][j].rgbtRed = round(sumred / counter);
            image[i][j].rgbtGreen = round(sumgreen / counter);
            image[i][j].rgbtBlue = round(sumblue / counter);
        }
    }
    return;
}
