#include <stdio.h>
#include <cs50.h>
#include <math.h>

int length(long long cc);

int main(void)
{
    long long cc = get_long("Enter cc: ");

    long long n = (cc % (long long) round(pow(10, 2)) - cc % (long long) round(pow(10, 1)))/10;
    printf("%lli\n", n);

    int len = length(cc);
    printf("length: %i\n", len);

    int even = 0;
    int odd = 0;

    if (len > 1)
    {
        for (int i = 1; i <= len; i++)
        {
            // extracting the nth number from the cc.

            long long before = cc % (long long) pow(10, i);
            long long after = cc % (long long) pow(10, i - 1);
            long long divide = (long long) pow(10, i - 1);
            long long x;


            if (i == 1)
            {
                x = before;
                printf("nth no: %lli\n", x);
            }
            else
            {
                x = (before - after) / divide;
                printf("nth no: %lli\n", x);
            }



            //even............(if nth no. is even)
            if (i % 2 == 0)
            {
                //if 2-digit.
                if (x > 4)
                {
                    int o = x*2;
                    // int l = ((o % 100) - (o % 10));

                    for (int a = 1; a <= 2; a++)
                    {
                        int l = ((o % (int) pow(10, a)) - (o % (int) pow(10, a - 1)))/(int) pow(10, a - 1);

                        printf("l: %i\n", l);

                        even = even + l;

                        printf("even: %i\n", even);

                    }
                }

                //if the no. is < 5............1-digit.
                else
                {
                    int o = x*2;
                    even += o;
                    printf("even: %i\n", even);

                }
            }

            //odd..............(if nth no. is odd)
            else
            {
                odd += x;
            }

        }
        int total = odd + even;
        printf("TOTAL: %i\n", total);
    }
    else
    {
        printf("INVALID\n");
    }

}

int length(long long cc)
{
    int n = 1;
    if (cc >= pow(10, 15) && cc < pow(10, 16))
    {
        n = 16;
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