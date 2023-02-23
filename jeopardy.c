/**
 * @file jeopardy.c
 * @author Group 12 
 * @brief 
 * @version 1.0
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief Import all the necessary header files
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

#define BUFFER_LEN 256
#define NUM_PLAYERS 4


// Tockenize input answer from user 
void tokenize(char *input, char **tokens);

// Initiate int for winner 
int winner();

// Function to show results
void show_results(player *players);

/**
 * @brief Main driver 
 * 
 * @return int 
 */
int main()
{
    // Initiate players object
    player players[NUM_PLAYERS+1];
    int test = 0;

    // Track number of questions left
    int qleft = NUM_QUESTIONS - 1; 
    
    // Input buffer and tokenslot buffer --> set to 0 
    char buffer[BUFFER_LEN] = { 0 };
    char tokenslot[BUFFER_LEN] = { 0 };

    // Initialize game for players
    initialize_game();



    printf("Please introduce yourself:\n");
    
    // Iterate through all players with name 
    for(int i=1; i<=NUM_PLAYERS; i++)
    {
        printf("Player %d?\t", i);
        fgets(players[i].name, BUFFER_LEN, stdin);

        if (players[i].name[strlen(players[i].name)-1] == '\n') { players[i].name[strlen(players[i].name)-1] = '\0'; } //remove newline     
        players[i].score = 0; // initialise score to 0
    
    }
    
    // Clear the screen
    system("clear"); 

    // Category buffer array set --> 0 
    char cat[BUFFER_LEN] = { 0 };
    int value = 0;
    char *token;
    int participants = 1;
    int j = -1;

    // 
    while (1) 
    {
        j = -1;
        test = 0;
        value = 0;
        printf("%s? \n", players[participants].name);
        display_categories();
        fgets(buffer, BUFFER_LEN, stdin);
        buffer[strlen(buffer)-1] = '\0';

    for (int i=0; i<strlen(buffer); i++)
    {
        if (buffer[i] == ' ')
        {
            test++;
        } 
    }

    if (test == 1)
    {
        token = strtok(buffer, " ");
        strcpy(cat, token);
        token = strtok(NULL, " ");
        if (atoi(token))    value = atoi(token);
    }
        for(int jj = 0; jj < NUM_CATEGORIES; jj++) 
        {

            if ( (strcmp(cat, categories[jj]) == 0) && (value == 100 || value == 200 || value == 300 || value == 400 ) ){ 
                if ( already_answered(&categories[jj], value) ) 
                { continue;}
                printf("I hope you know a lot about %s. We've got %d on the line.\n", categories[jj], value); 
                j = jj;

               
            }
        } 
        if (j == -1)
        {
            printf("Slight issue, please try again.");
            continue;
        }   //ie, redo the above without executing the below if we cant decipher the input
        
	
        display_question(&categories[j], value);
        fgets(buffer, BUFFER_LEN, stdin);
        buffer[strlen(buffer)-1] = '\0';

        // Correct Answer
        if (valid_answer(&categories[j], value, buffer)) 
        {
                    if (value == 100)
                        printf("Easy question.\n");
                    else if (value == 200)
                            printf("Not that hard.\n");
                    else if (value == 300)
                            printf("Ok that was hard.\n");
                    else if (value == 400)
                            printf("Good job, this one was tough!\n");
                    else printf("Not quite.\n");
                    
                    update_score(players, participants, value); 
        }

        // Wrong Answer
        else 
        {
                    if (value == 100)
                        printf("Incorrect\n");
                    else if (value == 200)
                            printf("Incorrect\n");
                    else if (value == 300)
                            printf("Incorrect\n");
                    else if (value == 400)
                            printf("Incorrect\n");
                    else printf("Incorrect\n");
        }
        
        // Verify if questions are left
        if (qleft)
        {
                    qleft--;
            if (participants == NUM_PLAYERS)
                    {
                        printf("Here's the scoreboard: \n");
                        show_results(players);
                        printf("Re-start fresh with a new round.");
                        fgets(buffer, BUFFER_LEN, stdin); //wait for enter
                        participants = 1;
                    }

            else
                    {	
                        printf("Game has %s with %d points.\n", players[participants].name, players[participants].score);
                        printf("Next player");
                        participants += 1;
                        fgets(buffer, BUFFER_LEN, stdin); //pause
                    }
                
            system("clear");//clear screen
                    
                    }
            
        else 
                {
                printf("Alright, games finished, and the winner is %s with %d points. Congratulations on wasting all that time.\n", players[winner(players)].name, players[winner(players)].score);
                return EXIT_SUCCESS;
                }
                
            }
            

    return EXIT_SUCCESS; // END
}


/**
 * @brief Keeps track of winner
 * 
 * @param players 
 * @return int 
 */
int winner(player *players)
{
    int max = 0;
	int best = 0;
	int tie = 0;
	
    for (int i = 1; i <=NUM_PLAYERS; i++)
	{
	    if (players[i].score > max) 
	    {
            max = players[i].score; 
            best = i; 
            }
	    if (players[i].score == max){
		tie = i;
		}

	}
	
	return best;
}

/**
 * @brief Displays the results
 * 
 * @param players 
 */
void show_results(player *players)
{
    printf("\nLeaderboard: \n");
    for (int i =1; i<=NUM_PLAYERS; i++)
    {
        printf("%s: %-5d", players[i].name, players[i].score);
    }
    printf("\n");
 
}

/**
 * @brief Tokenize input characters
 * 
 * @param input 
 * @param token 
 */
void tokenize(char *input, char **token)
{
  	if (input[strlen(input)-1] == '\n') { input[strlen(input)-1] = '\0'; } 
	char *p = strtok(input, token);
	while(p != NULL) {
	    printf("%s\n", p);
	    p = strtok(NULL, token);
	}
}

