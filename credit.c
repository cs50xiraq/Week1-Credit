#include <cs50.h>
#include <stdio.h>

long int check(long int this_num);
long int card_num;

int main(void)
{
    do
    {
        card_num = get_long("Number: ");
    } while (check(card_num) == 1);
}

long int check(long int this_num)
{
    int sum = 0, sum_product = 0, counter = 0, digit;

    while (this_num != 0)
    {
        counter++;
        digit = this_num % 10;
        this_num /= 10;

        if (counter % 2 == 0)
        {
            digit = digit * 2;

            if (digit >= 10)
            {
                sum_product = sum_product + (digit % 10);
                sum_product = sum_product + (digit / 10);
            }
            else
            {
                sum_product = sum_product + digit;
            }
        }
        else
        {
            sum = sum + digit;
        }
    }

    int checker = sum + sum_product;
    if (checker % 10 == 0)
    {
        if (counter == 15 && (((card_num / (10000000000000)) == 34) || ((card_num / (10000000000000)) == 37)))
        {
            printf("AMEX\n");
            return 0;
        }
        else if (counter == 16 && (((card_num / (100000000000000)) == 51) || ((card_num / (100000000000000)) == 52) || ((card_num / (100000000000000)) == 53) || ((card_num / (100000000000000)) == 54) || ((card_num / (100000000000000)) == 55)))
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if ((counter == 13 || counter == 16) && (((card_num / (1000000000000)) == 4 || (card_num / (1000000000000000)) == 4)))
        {
            printf("VISA\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
    return 1;
}
