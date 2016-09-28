#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// What's up cristal? I'm sure this is full of inefficiencies but as is, it works :) 
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Add one keyword on command line as key please!\n");
        return 1;
    }
    
    string key = argv[1];
    int keylength = strlen(argv[1]);
    
    // Make sure it's all letters...
    for(int i = 0; i < keylength; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Nope.");
            return 1;
        }
    }
    
    string message = GetString();

    // array size starts at 0. string length starts at 1. ex : strlength("merde") will return 5, so you need a char array[4] (array[0] = "m", array[4] = "e")
    char code[strlen(message - 1)];

    // Counter for non-alphabetic characters so the key isn't used on them
    int nonalpha = 0;
    
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        if (isupper(message[i]))
        {
            if (isupper(key[i % keylength]))
            {
                code[i] = message[i] + key[(i - nonalpha) % keylength] - 'A';
                // if outside of capital letter range bring it back (I should probably use modulo)
                if ((message[i] + key[(i - nonalpha) % keylength] - 'A') > 'Z')
                    code[i] = code[i] - 26;
            }
            else
            {
                code[i] = message[i] + key[(i - nonalpha) % keylength] - 'a';
                // same here
                if ((message[i] + key[(i - nonalpha) % keylength] - 'a') > 'Z')
                    code[i] = code[i] - 26;
            }
        }
        else if (islower(message[i]))
        {
            if (isupper(key[i % keylength]))
            {
                code[i] = message[i] + key[(i - nonalpha) % keylength] - 'A';
                // same
                if ((message[i] + key[(i - nonalpha) % keylength] - 'A') > 'z')
                    code[i] = code[i] - 26;
            }
            else
            {
                code[i] = message[i] + key[(i - nonalpha) % keylength] - 'a';
                // same
                if ((message[i] + key[(i - nonalpha) % keylength] - 'a') > 'z')
                    code[i] = code[i] - 26;
            }
        }
        else
        {
            code[i] = message[i];
            nonalpha++;
        }
        
    }
    
    // Important part cris: I would have used normal printf for string "code" but weird characters kept on showing up. Not sure how to fix.
    /*for (int i = 0, n = strlen(message); i < n; i++)
        printf("%c", code[i]);*/
    printf("%s \n", code);
        
    //printf("\n");
}
