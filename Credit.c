#include <stdio.h>
#include <cs50.h>
int main(void)
{
    long long cardNumber ;
    do
    {
        cardNumber = get_long("Enter your card's number:\n");
    }
    while (false);
    
    long oddSum = 0, evenSum = 0, finalSum = 0;
    int count = 0;
    long cop = cardNumber;
    //to calculate the length of cardNumber.
    while (cop != 0)
    {
        cop /= 10;
        ++count;
    }
    long product, cop2 = cardNumber;
    //if the length is even
    if (count % 2 == 0)
    {
        for (int i = count; i > 0 ; i--)
        {
            /*
             * begins with the end of cardNumber and detemines if if it will get (multiplication path) or (sum path) depends on i%2 if it's odd or even.
            */
            cop = cop2 % 10;
            cop2 = (long)(cop2 / 10);
            if (i % 2 == 0)
            {
                evenSum += cop ; 
            }
            else
            {
                product = cop * 2;
                if (product > 9)
                {
                    oddSum += (product / 10) + (product % 10);
                }
                else
                {
                    oddSum += product ;
                }
            }
        }
    }
    else //if the length is odd
    {
        for (int i = count; i > 0; i--)
        {
            /*
             * begins with the end of cardNumber and detemines if if it will get (multiplication path) or (sum path) depends on i%2 if it's odd or even.
            */
            cop = cop2 % 10;
            cop2 = (long)(cop2 / 10);
            if (i % 2 == 1)
            {
                evenSum += cop ; 
            }
            else
            {
                product = cop * 2;
                if (product > 9)
                {
                    oddSum += (product / 10) + (product % 10);
                }
                else
                {
                    oddSum += product ;
                }
              
             
            }
        }
    }   
    finalSum = evenSum + oddSum ;
    /*
     * boolean isValid to check if the final sum is valid (ex:20 , 50 , 10)
     */
    bool isValid = (finalSum % 10 == 0);      
    long number[count];
    for (int i = (count - 1); i >= 0; i--)
    {
        //to detemine the first & second number that cardNumber starts with
        number[i] = cardNumber % 10;
        cardNumber = cardNumber / 10;
    }
    //VISA validation   
    if ((isValid == true) && (count == 13 || count == 16) && (number[0] == 4))
    {
        printf("VISA\n");
    }
    //MASTERCARD validation
    else if ((isValid == true) && (count == 16) && (number[0] == 5) && (number[1] == 1 || number[1] == 2 || number[1] == 3
             || number[1] == 4 || number[1] == 5))
    {
        printf("MASTERCARD\n");
    }
    //AMEX validation
    else if ((isValid == true) && (count == 15) && (number[0] == 3) && (number[1] == 4 || number[1] == 7))
    {
        printf("AMEX\n");
    }
    //when it is not valid
    else
    {
        printf("INVALID\n"); 
    }
   
}
     
