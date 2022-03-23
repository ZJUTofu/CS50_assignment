#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string key = argv[1];
    for(int i = 0; i < strlen(key); i++)
    {
        if(!isdigit(key[i]))
        {
            printf("Usage: ./caesar key\n");
            return 2;
        }
    }
    int k = atoi(argv[1]);
    // printf("%i\n", k);
    string s = get_string("plaintext: ");

    printf("ciphertext:");

    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", (s[i] + k - 97) % 26 + 97);
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            printf("%c", (s[i] + k - 65) % 26 + 65);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
