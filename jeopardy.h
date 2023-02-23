/**
 * @file jeopardy.h
 * @author Group 12 
 * @brief 
 * @version 1.0
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#define MAX_LEN 256

// Tokenize user input 
extern void tokenize(char *input, char **tokens);

// Displays results 
extern void show_results(player *players);

// Return winnter
extern int winner(player *players);

#endif 
