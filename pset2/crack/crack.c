#define _XOPEN_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if( argc == 2 ) {
        // Declare variables
        char c = 'A';

        char *hashed = argv[1];
        char salt[3] = { hashed[0], hashed[1], '\0' };

        printf("\nOne letter\n\n");
        // Iterate through the letters
        for(int j = 0; j < 58; j++)
        {
            // Create letter element
            char changedNewC = c++;
            if( isalpha(changedNewC) ) {
                int equality = strncmp(crypt(&changedNewC, salt), hashed, 13);

                // Compare if the Upper letter is equal to the hash
                if(equality == 0) {
                    char key = changedNewC;
                    printf("The cracked password is: %c\n", key);
                }
            }

        }







        printf("\nTwo letters\n\n");
        c = 'A';
        for(int j = 0; j < 58; j++)
        {
            // Create letter element
            char changedNewC = c++;
            //if( isalpha(changedNewC) ) {
                char left = 'A';
                for(int i = 0; i < 58; i++)
                {
                    char changedNewLeft = left++;
                    if( isalpha(changedNewLeft) ) {
                        char key[3] = { changedNewLeft, changedNewC,'\0' };

                        int equality = strncmp(crypt(key, salt), hashed, 13);

                        // Compare if the letter is equal to the hash
                        if(equality == 0) {
                            printf("The cracked password is: %s\n", key);
                        }
                    }
                }
            //}
        }





        printf("\nThree letters\n\n");
        c = 'A';
        for(int j = 0; j < 58; j++)
        {
        // Create letter element
        char changedNewC = c++;
        char left = 'A';
            for(int i = 0; i < 58; i++)
            {
                char changedNewLeft = left++;
                char middle = 'A';

                for(int k = 0;k < 58; k++)
                {
                    char changedNewMiddle = middle ++;
                    if( isalpha(changedNewLeft) ) {
                        char key[4] = { changedNewMiddle, changedNewLeft, changedNewC, '\0' };

                        int equality = strncmp(crypt(key, salt), hashed, 13);

                        // Compare if the letter is equal to the hash
                        if(equality == 0) {
                            printf("The cracked password is: %s\n", key);
                        }
                    }
                }

            }
        }





        printf("\nFour letters\n\n");
        c = 'A';
        for(int j = 0; j < 58; j++)
        {
            char changedNewC = c++;
            char left = 'A';
            for(int i = 0; i < 58; i++)
            {
                char changedNewLeft = left++;

                char middle = 'A';
                for(int k = 0;k < 58; k++)
                {
                    char changedNewMiddle = middle ++;

                    char right = 'A';
                    for(int l = 0;l < 58; l++)
                    {
                        char changedNewRight = right++;
                        if( isalpha(changedNewLeft) ) {
                            char key[5] = { changedNewRight, changedNewMiddle, changedNewLeft, changedNewC, '\0' };

                            int equality = strncmp(crypt(key, salt), hashed, 13);

                            // Compare if the letter is equal to the hash
                            if(equality == 0) {
                                printf("The cracked password is: %c%c%c%c\n", key[0], key[1], key[2], key[3]);
                            }
                        }
                    }

                }

            }

        }






        printf("\nFive letters\n\n");
        c = 'A';
        for(int j = 0; j < 58; j++)
        {
            char changedNewC = c++;
            char left = 'A';
            for(int i = 0; i < 58; i++)
            {
                char changedNewLeft = left++;

                char middle = 'A';
                for(int k = 0;k < 58; k++)
                {
                    char changedNewMiddle = middle ++;

                    char right = 'A';
                    for(int l = 0;l < 58; l++)
                    {
                        char changedNewRight = right++;

                        char farRight = 'A';
                        for(int m = 0;m < 58; m++)
                        {
                            char changedFarRight = farRight++;
                            if( isalpha(changedNewLeft) ) {
                                char key[6] = { changedFarRight, changedNewRight, changedNewMiddle, changedNewLeft, changedNewC, '\0' };

                                int equality = strncmp(crypt(key, salt), hashed, 13);

                                // Compare if the letter is equal to the hash
                                if(equality == 0) {
                                    printf("The cracked password is: %c%c%c%c%c\n", key[0], key[1], key[2], key[3], key[4]);
                                }
                            }

                        }

                    }

                }

            }

        }

        // Print key result

        return 0;

    } else {
        printf("Prompt error, please try again entering two arguments\n");
        return 1;
    }
}