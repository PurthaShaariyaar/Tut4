/**
 * @file players.c
 * @author Group 12 
 * @brief 
 * @version 1.0
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "players.h"

/**
 * @brief Returns true if player currently exists
 * 
 * @param players 
 * @param num_players 
 * @param name 
 * @return true 
 * @return false 
 */
bool player_exists(player *players, int num_players, char *name)
{
    for (int i=1; i<num_players; i++)
    {
        if (strcmp(players[i].name, name)==0)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Update the score of the players
 * 
 * @param players 
 * @param num_players 
 * @param score 
 */
void update_score(player *players, int num_players, int score)
{
    	players[num_players].score += score;
}
