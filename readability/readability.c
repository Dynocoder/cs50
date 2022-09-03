#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("TEXT: ");
    int letters = count_letters(text);

    int words = count_words(text);

    int sentences = count_sentences(text);



    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;

    int index = (int) round((0.0588 * L) - (0.296 * S) - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }

}

int count_letters(string text)
{
    char x;
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        x = tolower(text[i]);
        if (x >= 'a' && x <= 'z')
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int words = 1;
    char x;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        x = text[i];
        if (x == ' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    char x;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        x = text[i];
        if (x == '!' || x == '?' || x == '.')
        {
            sentences++;
        }
    }
    return sentences;
}

// int count_sentences(string text)
// {
//     int sentences = 0;
//     char x;
//     for (int i = 0, n = strlen(text); i < n; i++)
//     {
//         x = text[i];
//         if (x == '!' || x == '?' || x == '.')
//         {
//             sentences++;
//         }
//     }
//     return sentences;
// }

// int count_sentences(string text)
// {
//     int sentences = 0;
//     char x;
//     for (int i = 0, n = strlen(text); i < n; i++)
//     {
//         x = text[i];
//         if (x == '!' || x == '?' || x == '.')
//         {
//             sentences++;
//         }
//     }
//     return sentences;
// }

// int count_sentences(string text)
// {
//     int sentences = 0;
//     char x;
//     for (int i = 0, n = strlen(text); i < n; i++)
//     {
//         x = text[i];
//         if (x == '!' || x == '?' || x == '.')
//         {
//             sentences++;
//         }
//     }
//     return sentences;
// }
