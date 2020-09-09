#include <stdio.h>
#include <cs50.h>
#include <math.h>

const char* get_card_type(long card_number);
bool card_checksum(long card_number);

int main(void)
{
    long card_number = get_long("Please enter your card number: \n");

    //If the card number passes the checksum
    if (card_checksum(card_number))
    {
        printf("%s\n", get_card_type(card_number));
    }
    else
    {
        printf("INVALID\n");
    }
}

bool card_checksum(long card_number)
{
    int multiplied_total = 0;
    int added_total = 0;
    int checksum;
    long card_numberCopy = card_number;


    while(card_numberCopy)
    {
      added_total += card_numberCopy % 10;
      card_numberCopy /= 10;


      int x = (card_numberCopy % 10) * 2;

      if (x > 9) {
          x = (x % 10) + 1;
      }

      multiplied_total += x;
      card_numberCopy /= 10;
    }

    checksum = (added_total + multiplied_total) % 10;

    if (checksum == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

const char* get_card_type(long card_number)
{
    long x = card_number;

    // Get the first two digits of the card number
    while (x > 100)
    {
        x = x / 10;
    }

    if (x == 34 || x == 37)
    {
        return "AMEX";
    }
    else if (x >= 51 && x <= 55)
    {
        return "MASTERCARD";
    }
    else if (x / 10 == 4)
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}

