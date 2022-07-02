#include <cs50.h>
#include <math.h>
#include <stdio.h>

long long get_number(void);
char card_type(long long cc);
bool checksum(long long cc);
int length(long long cc);

int even;
int odd;


// Main
int main(void)
{
    long long cc = get_number();
    bool check = checksum(cc);
    if (check)
    {
        char type = card_type(cc);
        if (type == 'a')
        {
            printf("AMEX\n");
        }
        else if (type == 'm')
        {
            printf("MASTERCARD\n");
        }
        else if (type == 'v')
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (check == false)
    {
        printf("INVALID\n");
    }
}


// Get cc number.
long long get_number(void)
{
    long long cc = get_long("Enter Your Card Number: ");
    return cc;
}

// checksum
bool checksum(long long cc)
{
    bool pass;
    int len = length(cc);

    if (len > 1)
    {
        for (int i = 1; i <= len; i++)
        {
            // extracting the nth number from the cc.

            long long before = cc % (long long) pow(10, i);
            long long after = cc % (long long) pow(10, i - 1);
            long long divide = (long long) pow(10, i - 1);
            long long x;


            //when n = 1. 
            if (i == 1)
            {
                x = before;
            }
            else
            {
                x = (before - after) / divide;
            }

            //even............(if nth no. is even)
            if (i % 2 == 0)
            {
                //if 2-digit.
                if (x > 4)
                {
                    int o = x * 2;

                    for (int a = 1; a <= 2; a++)
                    {
                        int l = ((o % (int) pow(10, a)) - (o % (int) pow(10, a - 1))) / (int) pow(10, a - 1);
                        even += l;
                    }
                }

                //if the no. is < 5............1-digit.
                else
                {
                    int o = x * 2;
                    even += o;

                }
            }

            //odd..............(if nth no. is odd)
            else
            {
                odd += x;
            }

        }
        int total = odd + even;
        printf("total: %i\n", total);
        if (total % 10 == 0)
        {
            pass = true;
        }
        else
        {
            pass = false;
        }
    }
    else
    {
        pass = false;

    }

    return pass;

}

int length(long long cc)
{
    int n = 1;
    if (cc >= pow(10, 15) && cc < pow(10, 16))
    {
        n = 16;
    }
    else if (cc >= pow(10, 14) && cc < pow(10, 15))
    {
        n = 15;
    }
    else if (cc >= pow(10, 12) && cc < pow(10, 13))
    {
        n = 13;
    }
    else
    {
        n = 0;
    }
    return n;
}


// Check for card type.
char card_type(long long cc)
{
    char card_type = 'i';
    //Mastercard or visa
    if (cc < pow(10, 16) && cc >= pow(10, 15)) //Check if the no. is 16 digit
    {
        //check for mastercard.
        if (cc >= 51 * pow(10, 14) && cc < 56 * pow(10, 14))
        {
            card_type = 'm';
        }
        //check for visa card 16-digit.
        else if (cc >= 4 * pow(10, 15) && cc < 5 * pow(10, 15))
        {
            card_type = 'v';
        }
    }
    //check for american express cards. no. of digits are 15.
    else if (cc < pow(10, 15) && cc >= pow(10, 14))
    {
        //ensuring the number starts with 34 or 37.
        if ((cc >= 34 * pow(10, 13) && cc < 35 * pow(10, 13)) || (cc >= 37 * pow(10, 13) && cc < 38 * pow(10, 13)))
        {
            card_type = 'a';
        }
    }
    //check for visa card 13-digit.
    else if (cc < pow(10, 14) && cc >= pow(10, 12))
    {
        card_type = 'v';
    }
    return card_type;
}
