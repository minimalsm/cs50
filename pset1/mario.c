#include <stdio.h>
#include <cs50.h>

int getTowerHeight(void);
void printTower(int height);
void printRightTower(int height, int i);
void printLeftTower(int height, int i);

int main(void)
{
    int height = getTowerHeight();
    printTower(height);
}

int getTowerHeight(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    return height;
}

void printTower(int height)
{
    for (int i = 0; i < height; i++)
    {
        printLeftTower(height, i);
        printf(" ");
        printRightTower(height, i);
        printf("\n");
    }
}

void printLeftTower(int height, int i)
{
    for (int j = height; j > 0; j--)
    {
        (j > (i + 1)) ? printf(" ") : printf("#");
    }
}

void printRightTower(int height, int i)
{
    for (int k = 0; k < height; k++)
    {
        (k > i) ? printf(" ") : printf("#");
    }
}