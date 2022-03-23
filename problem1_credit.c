#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long CreditNumber = get_long("Your credit number: ");
    long validC = CreditNumber;
    int one = 0;
    int two = 0;
    while(CreditNumber != 0)
    {
        int a = (CreditNumber / 10) % 10;
        int b = CreditNumber % 10;
        CreditNumber = CreditNumber / 100;
        int m = 2 * a;
        if(m >= 10)
        {
            m = m - 9;
        }
        two = two + m;
        one = one + b;
    }
    int sum = one + two;

    if(sum % 10 == 0)
    {
        while(validC >= 100)
        {
            validC = validC / 10;
        }

        if(validC == 34 || validC == 37)
        {
            printf("American Express\n");
        }
        else if(validC >= 51 && validC <= 55)
        {
            printf("MasterCard\n");
        }
        else if(validC / 10 % 10 == 4)
        {
            printf("Visa\n");
        }
    }
    else
    {
        printf("invalid\n");
    }
}
