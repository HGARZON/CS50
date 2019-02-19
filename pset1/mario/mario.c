// less

#include <stdio.h>
#include <cs50.h>
int main()
{
    int i, j, rows;


    do
    {
        //printf("Enter number of rows: ");
        //scanf("%d",&rows);
        rows = get_int("Enter number of rows: ");

    } while(!(rows >= 0 && rows <= 23));

    for(i=2; i<=rows+1; ++i)
    {
        int spaces = i;
        for(j=1; j<=i; ++j)
        {
            while((rows+1) - spaces > 0) {
                printf(" ");
                spaces++;
            }
            printf("#");
        }
        printf("\n");
    }
}