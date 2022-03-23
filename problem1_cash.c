#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while(dollars < 0);

    int cents = round(dollars * 100);
    int a;
    int b;
    int c;
    int d;

    for(a = 0; cents >= 25; a++)
    {
        cents = cents - 25;
    }

    for(b = 0; cents >= 10; b++)
    {
        cents = cents - 10;
    }

    for(c = 0; cents >= 5; c++)
    {
        cents = cents - 5;
    }

    for(d = 0; cents >= 1; d++)
    {
        cents = cents - 1;
    }

    printf("%i\n", a + b + c + d);
}
