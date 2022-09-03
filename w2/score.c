#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n = get_int("enter no. of tests: ");
    int scores[n];
    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("enter scores: ");
    }
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x += scores[i];
    }

    printf("Average: %f\n", x/(float) n);
}