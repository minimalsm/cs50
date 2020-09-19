#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
string cipher_text(string text, string key);
bool is_letter(char c);
bool is_not_letter(char c);
bool has_duplicates(char c);
bool valid_args(int count, string arg);


int main(int argc, string argv[])
{
    if (!(valid_args(argc, argv[1]))) 
    {
        return 1;
    }
    
    string key = argv[1];
    string user_input = get_string("plaintext: ");
    string ciphered_input = cipher_text(user_input, key);
    printf("ciphertext: %s\n", ciphered_input);
    
    return 0;
}

bool valid_args(int count, string arg)
{
    if (count != 2)
    {
        printf("Usage: ./substitution key\n");
        return false;
    }
    
    int n = strlen(arg);

    if (n != 26) 
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    else 
    {
        for (int i = 0; i < n; i++)
        {
            if (is_not_letter(arg[i]))
            {
                printf("Key must contain only letters.\n");
                return false;
            }
            
            if (has_duplicates(arg[i]))
            {
                printf("Key must not contain repeated characters.\n");
                return false;
            }
        }
    }
    
    return true;
}

bool has_duplicates(char c)
{
    char lower = tolower(c);
    int ascii = (int) lower - 97;
    
    if (alphabet[ascii] == '*')
    {
        return true;
    }
    else
    {
        alphabet[ascii] = '*';
        return false;
    }
}

string cipher_text(string text, string key)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //Get ASCII char code
        int ascii = (int) text[i];
        int index;
        
        if (islower(text[i]))
        {
            index = ascii - 97;
            text[i] = tolower(key[index]);
        }
        else if (isupper(text[i]))
        {
            index = ascii - 65;
            text[i] = toupper(key[index]);
        }
    }
    
    return text;
}

bool is_not_letter(char c)
{
    return !(is_letter(c));
}

bool is_letter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}