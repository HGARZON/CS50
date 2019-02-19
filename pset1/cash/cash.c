#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    float coins;
    float rest = 0;
    float quarter = 0.25;
    float dime = 0.10;
    float nickel = 0.05;
    float penny = 0.00999;
    int amountOfCoins = 0;

    do
    {
        coins = get_float("Change owed: ");

        printf("%g\n", ceil(coins*10));
    }

    while(coins < 0);

    if (coins >= quarter)
    {
        int quarterDivision = (int)(coins / quarter);

        printf("quarterDivision: ");
        printf("%d\n", quarterDivision);

        rest = coins - (quarter * quarterDivision);
        printf("rest: ");
        printf("%g\n", rest);

        for(int i = 0; i < quarterDivision; i++)
        {
            amountOfCoins++;
        }

        printf("amountOfCoins: ");
        printf("%d\n", amountOfCoins);
    }
    if(rest >= dime)
    {
        int dimeDivision = (int)(rest / dime);

        printf("dimeDivision: ");
        printf("%d\n", dimeDivision);

        rest = rest - (dime * dimeDivision);

        printf("rest: ");
        printf("%g\n", rest);

        for(int i = 0; i < dimeDivision; i++)
        {
            amountOfCoins++;
        }
        printf("amountOfCoins: ");
        printf("%d\n", amountOfCoins);
    }
    if(rest >= nickel)
    {
        int nickelDivision = (int)(rest / nickel);

        printf("nickelDivision: ");
        printf("%d\n", nickelDivision);

        rest = rest - (nickel * nickelDivision);
        printf("rest: ");
        printf("%g\n", rest);

        for(int i = 0; i < nickelDivision; i++)
        {
            amountOfCoins++;
        }
        printf("amountOfCoins: ");
        printf("%d\n", amountOfCoins);
    }
    else if(rest >= penny)

    printf("entra en penny");

    {
        float pennyDivision = (int)(rest / penny);

        printf("pennyDivision: ");
        printf("%g\n", pennyDivision);

        rest = rest - (penny * pennyDivision);
        printf("rest: ");
        printf("%g\n", rest);

        for(int i = 0; i < pennyDivision; i++)
        {
            amountOfCoins++;
        }
        printf("amountOfCoins: ");
        printf("%d\n", amountOfCoins);
    }

}