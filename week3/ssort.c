#include<stdio.h>
#include<cs50.h>

void swap(int numbers[], int a, int b);

int main(void)
{
    int numbers[] = {3, 32, 12, 1, 13, 44, 25, 42, 36, 76, 34, 7, 0};

    int n = sizeof(numbers)/sizeof(int);

    int csmall = 0;

    for(int i = 0; i < n; i++)
    {
        if (numbers[i] < csmall)
        {
            csmall = numbers[i];
        }
    }
    swap(numbers[], csmall)



}

void swap(int numbers[], int a, int b)
{
    int temp = numbers[b];
    numbers[b] = numbers[a];
    numbers[a] = temp;
}