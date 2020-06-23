// Calculate the readablity of a text.

// .---------------.
// |    Imports    |
// '---------------'
#include <stdio.h> // Standard input.
#include <cs50.h> // CS50 utility script. Includes get_string and string.
#include <ctype.h> // ASCII utils
#include <string.h> // String utils
#include <math.h> // Used for rounding

// .-------------.
// |  Prototypes |
// '-------------'
int get_letters(string text); // Counts letters for formula
int get_words(string text); // Counts words for formula
int get_sentences(string text); // Counts sentences for formula
float formula(int sentences, int letters, int words); // Formula

// .---------------.
// | Main Function |
// '---------------'

int main(void)
{
    string text = get_string("Text:");

    float index = formula(get_sentences(text), get_letters(text), get_words(text));

    // printf("Sentences: %i. Letters: %i. Words: %i \n", get_sentences(text), get_letters(text), get_words(text));

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", (int) index);
    }
    else if (index > 16 )
    {
        printf("Grade 16+\n");
    }
}

// .-------------------.
// | Utility Functions |
// '-------------------'
int get_letters(string text)
{
    int num_letters = 0; // letter counter

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            num_letters ++;
        }
    }
    return num_letters;
}

int get_words(string text)
{
    int num_words = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            num_words++;
        }
    }
    return num_words + 1;
}

int get_sentences(string text)
{
    int num_sentences = 0; // sentence counter

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((int) text[i] == 46 || (int) text[i] == 63)
        {
            num_sentences ++;
        }
    }

    return num_sentences;
}


float formula(int sentences, int letters, int words)
{
    float L = (float) letters * 100 / (float) words;
    float S = (float) sentences * 100 / (float) words;

    // Coleman-Liau index is computed using the formula
    return round(0.0588 * L - 0.296 * S - 15.8);

}
