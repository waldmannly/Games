//EVAN WALDMANN
//TEAM 9

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define NUM_WORDS  25
#define GUESSES 6

int noLetterLeft(char* dashes, int length)
{
    int i;
    for (i=0; i< length; i++)
    {
        if (dashes[i] =='-')
            return 0;
    }
    return 1;
}

int checkLetters(char** dashes, char** word, int length, char letter)
{
    int found =0,i;
    for (i=0; i< length; i++)
    {
        if ((*word)[i] == letter)
        {
            found =1;
            (*dashes)[i] = letter;
        }
    }
    return found;
}

int main (void)
{
    printf("TEAM 9's HANGMAN\n");
    
    int guesses =GUESSES,i,fucked;
    int wordLength =0;
    int gameover =0;
    int userWin =0;
    char allWords[NUM_WORDS][26] = {"COMPUTER", "PROGRAMMING", "OPERATOR", "OPERAND", "CONDITIONAL", "REPETITION", "FUNCTION", "ARRAY", "ERROR", "LOOP", "BOOLEAN", "STRING", "NUMBER", "DEBUG", "SWITCH", "CASE","RETURN","OBJECT", "DATE","MATH", "TERNARY", "WHILE", "TABLE", "INPUT", "VALUE"};
    char* dashes;
    char* word;
    
    char userLetter;
    
    int chars[26];
    for(i=0; i<26; i++)
    {
        chars[i] = i;
    }
    
    //random numbers
    srand(time(NULL));
    int ran = rand() % NUM_WORDS;
    
    //get word length
    for(i=0; i<26; i++)
    {
        if(allWords[ran][i]=='\0')
        {
           // printf(" word: %s  word length: %d\n\n", allWords[ran],wordLength);
            break;
        }
        wordLength++;
    }
    
    //allocate memmory
    word = malloc(sizeof(char)*(wordLength+1));
    dashes = malloc(sizeof(char)*(wordLength+1));
    
    strcpy(word, allWords[ran]);
    for (i=0; i<wordLength; i++)
    {
        dashes[i] = '-';
    }
    dashes[i+1] = '\0';
    
    //guessing
    while (!(gameover))
    {
        printf("word: %s\n", dashes);
        
        fucked =1;
        while(fucked)
        {
            printf("Guess a Capital letter. (Number of guesses left: %d)\nPrevious guesses:", guesses);
            for(i=0;i<26 ;i++)
            {
                if (chars[i] == -1)
                    printf(" %c", i+65);
            }
            printf("\n\nYour guess: ");
            scanf(" %c", &userLetter);
            userLetter = toupper(userLetter);
            printf("\n");
            if(chars[userLetter-65] != -1)
            {
                fucked=0;
                break;
            }
            else
                printf("YOU HAVE ALREADY GUESSED THAT LETTER. TRY AGAIN!");
        }
        
        int correct = checkLetters(&dashes, &word, wordLength, userLetter);
        if(correct)
        {
            printf("You have guessed correctly!\n");
            chars[ ((userLetter)-65)] =-1;
        }
        else
        {
            guesses--;
            printf("You have guessed incorrectly! Only %d guesses left.\n", guesses);
            chars[ ((userLetter)-65)] =-1;
        }
        
        userWin = noLetterLeft(dashes, wordLength);
        
        if (guesses ==0 || userWin)
        {
            gameover =1;
        }
    }
    
    if(userWin)
    {
        printf("You have WON! \nGame win now end.\n");
    }
    else
    {
        printf("You could not manage to guess the word %s\nYou have LOST! \nGame win now end.\n", word);
    }
    
    
    free(dashes);
    free(word);
    return 0;
    
}