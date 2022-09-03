#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    string s = get_string("Name: ");

    for (int i = 0; i < strlen(s); i++)
    {
        // as there is a difference of 32 between the ascii no. of capital letters and small letters.
        // if ( s[i] >= 'a' && s[i] <= 'z')
        // {
        //     printf("%c", s[i] - 32);
        // }
        // else
        // {
        //     printf("%c", s[i]);
        // }

        if(islower(s[i]))
        {
            printf("%c", toupper(s[i]));
        }
    }
    printf("\n");
}