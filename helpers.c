#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // getting rgb value
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            int greyShade = round((red + blue + green) / 3.0);

            // Assigning the greyshade
            image[i][j].rgbtRed = greyShade;
            image[i][j].rgbtGreen = greyShade;
            image[i][j].rgbtBlue = greyShade;
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
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            // applying sepia color
            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);

            // Assigning the sepia color
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];

            // swaping process
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // variable to put the rgb value of neighbour pixels
            int redSum = 0, greenSum = 0, blueSum = 0;
            int pixelCount = 0;

            // looking at all neighboring pixels
            for (int bi = -1; bi <= 1; bi++)
            {
                for (int bj = -1; bj <= 1; bj++)
                {
                    int ni = i + bi;
                    int nj = j + bj;

                    // Make sure the new indices are within the image boundaries
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        // rgb valid value of neighbour pixel
                        redSum += copy[ni][nj].rgbtRed;
                        greenSum += copy[ni][nj].rgbtGreen;
                        blueSum += copy[ni][nj].rgbtBlue;

                        pixelCount++;
                    }
                }
            }

            // changing the value of pixel to blur
            image[i][j].rgbtRed = round((float) redSum / pixelCount);
            image[i][j].rgbtGreen = round((float) greenSum / pixelCount);
            image[i][j].rgbtBlue = round((float) blueSum / pixelCount);
        }
    }
    return;
}