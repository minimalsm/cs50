#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

string cipher_text(string text, int cipher);
bool is_letter(char c);
int create_key(string arg);
bool valid_args(int count, string arg);

int main(int argc, string argv[])
{
    if (!(valid_args(argc, argv[1])))
    {
        return 1;
    }
    
    string user_input = get_string("plaintext: ");
    int key = create_key(argv[1]);
    string ciphered_input = cipher_text(user_input, key);
    printf("ciphertext: %s\n", ciphered_input);
    
    return 0;
}

bool valid_args(int count, string arg)
{
    if (count != 2)
    {
        printf("Wrong number of arguments!\n");
        printf("Usage: ./caesar key\n");
        return false;
    }
    else if (atoi(arg) < 1)
    {
        printf("Must enter a number greater than 0\n");
        printf("Usage: ./caesar key\n");
        return false;
    }
    else
    {
        for (int i = 0, n = strlen(arg); i < n; i++)
        {
            if (!(isdigit(arg[i])))
            {
                printf("Invalid input\n");
                printf("Usage: ./caesar key\n");
                return false;
            }
        }
    }

    return true;
}

int create_key(string arg)
{
    return atoi(arg);
}

bool is_letter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

string cipher_text(string text, int cipher)
{
    while (cipher > 26)
    {
        cipher -= 26;
    }

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (is_letter(text[i]))
        {
            if (is_letter(text[i] + cipher))
            {
                text[i] = text[i] + cipher;
            }
            else
            {
                text[i] = text[i] - 26 + cipher;
            }
        }
    }

    return text;
}