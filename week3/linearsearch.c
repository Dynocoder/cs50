#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int numbers[] = {3, 5, 7, 0, 9, 5, 4, 2};

    for(int i = 0; i < 8; i++)
    {
        if(numbers[i] == 2)
        {
            printf("found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}