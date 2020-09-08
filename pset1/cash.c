#include <stdio.h>
#include <cs50.h>
#include <math.h>

float getChangeOwed(void);
int getCoinsOwed(int cents);

int main(void)
{
    float centsOwed = getChangeOwed();
    int coins = getCoinsOwed(centsOwed);
    
    printf("Coins: %i\n", coins);
}

int getCoinsOwed(int cents)
{
    int coins = 0;
    
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
            coins++;
        } 
        else if (cents >= 10)
        {
            cents -= 10;
            coins++;
        } 
        else if (cents >= 5)
        {
            cents -= 10;
            coins++;
        } 
        else 
        {
            cents--;
            coins++;
        }
    }
    
    return coins;
}

float getChangeOwed(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed? ");
    } 
    while (dollars < 0);
    
    return round(100 * dollars);
}