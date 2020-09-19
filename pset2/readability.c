#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

void get_text_stats(string text);
bool is_letter(char c);
bool is_space(char c);
bool end_of_sentence(char c);
int get_reading_grade(int l, int w, int s);

int words;
int letters;
int sentences;

int main(void)
{
    string text = get_string("Please enter a phrase to assess");
    get_text_stats(text);

    int reading_grade = get_reading_grade(letters, words, sentences);
    printf("READING GRADE IS: %i\n", reading_grade);
    // int letters = get_letters(text);
    printf("%i\n", words);
}

void get_text_stats(string text)
{
    words = 1; //always pad the first word with 1
    letters = 0;
    sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (is_letter(text[i]))
        {
            letters++;
        }
        else if (is_space(text[i]))
        {
            words++;
        }
        else if (end_of_sentence(text[i]))
        {
            sentences++;
        }
    }

    printf("Letters: %i\n", letters);
    printf("Words: %i\n", words);
    printf("Sentences: %i\n", sentences);
}

int get_reading_grade(int l, int w, int s)
{
    //Average number of letters per 100 words
    float L = (l / (float) w) * 100.0;
    //Average number of sentences per 100 words
    float S = (s / (float) w) * 100.0;

    //Colman-lEIU FORMULA
    float index = 0.0588 * L - 0.296 * S - 15.8;

    printf("THE INDEX IS: %f\n", index);

    int rounded_index = (int) round(index);

    printf("THE ROUNDED INDEX IS: %i\n", rounded_index);

    return rounded_index;
}


//Helper functions

bool is_space(char c)
{
    return (c == ' ');
}

bool is_letter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool end_of_sentence(char c)
{
    return (c == '!' || c == '.' || c == '?');
}