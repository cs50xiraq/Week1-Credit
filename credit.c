#include<stdio.h>
#include<cs50.h>
int main()
{
    long num = get_long("Enter num : ");//Enter number of card
    int last, sec, count = 0, sum1 = 0, sum2 = 0, temp, sum = 0;
    while (num > 0)//for enter number only
    {
        sec = last;
        last = num % 10;//give last num of numbers 
        count++;
        if (count % 2 == 0)
        {        
            temp = last * 2 ;
            if (temp >= 10)
            {
                sum1 += temp % 10;
                sum1 += temp / 10;
            } 
            else
            {
                sum1 += temp;
            }
        }
        else
        {
            sum2 += last;
        }
        num /= 10;
    }
    sum = sum1 + sum2;
    if ((sum % 10) == 0)//check valid
    {
        if (((sec == 1 && last == 5) || (sec == 2 && last == 5) || (sec == 3 && last == 5) || (sec == 4 && last == 5) 
             || (sec == 5 && last == 5)) && count == 16)
            
        {
            printf("MASTERCARD\n");//check master card
        }
        else if (((sec == 4 && last == 3) || (sec == 7 && last == 3)) && count == 15)//check AMEX
        {
            printf("AMEX\n");
        }
        else if (last == 4 && (count == 13 || count == 16))//check VISA
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else 
    {
        printf("INVALID\n");
    }
}
