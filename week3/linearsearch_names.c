#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(void)
{
    string names[] = {"ron", "harry", "mike", "mosh", "arjun", "saurav", "madhav"};

    for(int i = 0; i < 7; i++)
    {
        //strcmp compares different strings which C itself cannot do.
        if(strcmp(names[i], "saurav") == 0)
        {
            printf("found\n");
            return 0;
        }
    }
    printf("not found\n");
    return 1;
}