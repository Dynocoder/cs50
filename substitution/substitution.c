#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


bool check_validity(string key, int key_length);
string encrypt(string key, string input);

char key_char[26];

int main(int argc, string argv[])
{
    int count = argc;
    // Exit Status if key is not given.
    if (count < 2 || count > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    int key_length = strlen(key);


    bool valid = check_validity(key, key_length);

    // Exit Status if key is invalid.
    if (valid == false)
    {
        return 1;
    }



    // transfering the key in an array.
    for (int i = 0; i < 26; i++)
    {
        key_char[i] = tolower(key[i]);
    }


    string input = get_string("plaintext: ");

    string output = encrypt(key, input);

    printf("ciphertext: %s\n", output);


}


// Check validity.
bool check_validity(string key, int key_length)
{
    bool valid;

    for (int i = 0; i < key_length; i++)
    {
        // Length check of the key.
        if (key_length != 26)
        {
            valid = false;
            printf("Key must contain 26 alphabetic characters.\n");
            break;
        }



        // Check if all are alphabets.
        else if (isalpha(key[i]))
        {
            valid = true;
        }

        // if the no. of characters is less.
        else
        {
            valid = false;
            printf("Key must contain 26 alphabetic characters.\n");
            break;

        }

        // Checking for multiple instances of the same character.
        for (int j = 0, n = 0; j < key_length; j++)
        {
            if (key[i] == key[j])
            {
                n++;
                if (n > 1)
                {
                    printf("Key must contain 26 alphabetic characters exactly once.\n");
                    valid = false;
                    return valid;
                    break;
                }
            }
        }

    }
    return valid;

}


string encrypt(string key, string input)
{
    string output = input;
    int index;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        // Check if the current char is an alphabet or not.
        if (isalpha(input[i]))
        {
            // Check if the current char is lowercase or uppercase.
            if (islower(input[i]))
            {
                index = input[i] - 97;
                output[i] = tolower(key_char[index]);
            }
            else if (isupper(input[i]))
            {
                index = input[i] - 65;
                output[i] = toupper(key_char[index]);
            }
        }

    }
    return output;
}