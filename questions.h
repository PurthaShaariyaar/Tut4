/**
 * @file questions.h
 * @author Group 12 
 * @brief 
 * @version 1.0
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Import all necessary libraries
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.c"

extern question quest[NUM_QUESTIONS] = {

{
    "BEATLES",
    "This one was married to Yoko Ono",
    "JOHN",
    100,
    false
},

{
    "BEATLES",
    "This one played bass",
    "PAUL",
    200,
    false
},

{
    "BEATLES",
    "This one died in 1966",
    "PAUL", 
    300,
    false
},

{
    "BEATLES",
    "This one lifts 850 times its body mass",
    "HERCULES",
    400,
    false
},

{
    "INSECTS",
    "This one spins a web",
    "SPIDER",
    100,
    false
},
{
    "INSECTS",
    "This one is named after its mode of transportation",
    "FLY",
    200,
    false
},

{
    "INSECTS",
    "This one crawls on the ground",
    "WORM",
     300,
    false
},

{
    "INSECTS",
    "This one is not margerine and doesn't walk",
    "BUTTERFLY",
    400,
    false
},

{
    "BUGS",
    "Number when page not found",
    "404",
    100,
    false
},

{
    "BUGS",
    "I couldn't think of another one",
"404",
    200,
    false
},

{
    "BUGS",
     "I couldn't think of one more'",
  "404",
    300,
    false
},

{
    "BUGS",
    "Name in Hyrule",
    "ERROR",
    400,
    false
}
};

// Initialize the game 
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
  
}

// Display categories and points
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    printf("On the menu tonight:\n");
    for (int i = 0; i < NUM_CATEGORIES; i++)
    {
        if (!quest[0+i].answered || !quest[1+i].answered || !quest[2+i].answered || !quest[3+i].answered)
        {
            printf ("%-5s %-5s\t", categories[i], " ");
 
                for (int j = 0; j < 4; j++)
                {
                    if (quest[i*4 + j].answered == false)
                    {
                        printf("%-2d \t", quest[i*4 +j].value);
                    }
			        else printf("%-2s\t", " ");
                }
        }
        printf("\n"); //this spacing is necessary, it was getting on my nerves
    }
    
    printf("Pick your poison: ");
    
}

// Displays the question for the category and points
void display_question(char *category, int value)
{
   //printf("%s  %d\n", category, value);
    for (int i=0; i<NUM_QUESTIONS; i++)
    {
        if ( ( strcmp(quest[i].category, category) == 0 ) && (quest[i].value == value) )
        {
        printf("\033[1;34m\t\t%s\033[0m\n", quest[i].question);
        quest[i].answered = true; //we might as well mark it here
        break; //this might fix something
        }
    }
}

// Return true if the answer is correct 
bool valid_answer(char *category, int value, char *answer)
{
    int test = 0;
    if (answer[strlen(answer)-1] == '\n') { answer[strlen(answer)-1] = '\0'; } //remove newline     
    for (int i=0; i<strlen(answer); i++)
    {
        if (answer[i] == ' ')
        {
            test++;
        }
    }

    if (! (test == 2) ) return false;
  	char *p = strtok(answer, " ");
    if ( !(strcmp(&p, "WHO") || strcmp(&p, "WHAT") ) ) return false; 
    if (p != NULL)  p = strtok(NULL, " ");
    if ( !strcmp(&p, "IS") ) return false;
    if (p != NULL)  p = strtok(NULL, " ");
    strcpy(answer, p);


    for (int i=0; i<NUM_QUESTIONS; i++)
    {
        if ( ( strcmp(quest[i].category, category) == 0 ) && (quest[i].value == value) )
        {
            if ( strcmp(quest[i].answer, answer) == 0 ) 
            {
                return true;
            }
            else { return false; }
        }
    }
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for (int i=0; i<NUM_QUESTIONS; i++)
    {
        if ( ( strcmp(quest[i].category, category) == 0 ) && (quest[i].value == value) )
        {
            if ( quest[i].answered == false ) 
            {
                return false;
            }
            else { return true; }
        }
    }

}
