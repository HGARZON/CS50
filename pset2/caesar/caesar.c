#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if( argc == 2 ) {
        printf("The argument supplied is %s\n", argv[1]);
        int i = atoi(argv[1]);

        string s = get_string("plaintext: ");

        printf("ciphertext: ");

        for (int j = 0, n = strlen(s); j < n; j++)
        {
            int letter = (s[j] + i);

            if(isalpha(s[j])) {

                if(letter > 172) {
                    printf("%c", letter - 78);
                } else if(letter > 160) {
                    printf("%c", letter - 52);
                } else if(letter > 122) {
                    printf("%c", letter - 26);
                } else {
                    printf("%c", letter);
                }

            } else
            {
                printf("%c", s[j]);
            }
        }

        printf("\n");

    } else
    {
        printf("Prompt error, please try again entering two arguments\n");
        return 1;
    }
}