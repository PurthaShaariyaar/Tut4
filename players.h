/**
 * @file players.h
 * @author Group 12 
 * @brief 
 * @version 1.0
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef PLAYERS_H_
#define PLAYERS_H_

#include <stdbool.h>

#define MAX_LEN 256

/**
 * @brief Type structure for name and score for player
 * 
 */
typedef struct {
    char name[MAX_LEN];
    int score;
} player;

// True if player exists
extern bool player_exists(player *players, int num_players, char *name);

// Update score of player
extern void update_score(player *players, int num_players, char *name, int score);

#endif 