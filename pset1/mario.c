#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

// Loop for creating multiple lines.
    for (int i = 0; i < height; i++)
    {
        // Loop for placing spaces before the first hashes.
        for (int j = height - (i + 1); j > 0; j--)
        {
            printf(" ");
        }
        // Loop for placing the first hashes.
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        // the space between the two stairs.
        printf("  ");
        // Loop for making the last hashes
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}