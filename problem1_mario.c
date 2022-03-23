#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while(n < 1 || n > 8);

    int a;
    for(a = 0; a < n; a++)
    {
        for(int x = 0; x < n-a-1; x++)
        {
            printf(" ");
        }

        for(int y = 0; y < a+1; y++)
        {
            printf("#");
        }

        printf("\n");
    }
}
