#ifndef FUNCTIONHEADER_H
#define FUNCTIONHEADER_H

#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LENGTH 40
#define MAX_SPELL_LENGTH 20
#define MAX_SPELLS 79

/**
  Plays game user versus bot
*/
void singlePlayer(int num_spells, char spells[][MAX_SPELL_LENGTH], int difficulty);

/**
  Gets bot move depending on difficulty 
*/
void getBotMove(char* botName, char spells[MAX_SPELLS][MAX_SPELL_LENGTH], char* lastSpell, int numSpells, char* move, int difficulty);

/**
  Checks if move is valid
*/
bool isValidMove(const char* spell, const char* lastSpell);

/**
  Prints the available spells
*/
void print_spells(int num_spells, char spells[][MAX_SPELL_LENGTH]);

/**
  Prints the different game modes to stdout
*/
int two_player(int num_spells, char spells[][MAX_SPELL_LENGTH]);

/**
  Prints the different game modes to stdout
*/
void game_mode_screen(int *userChoice);

/**
  Prints the difficulty levels to stdout
*/
void difficulty_screen();
/**
  Prints a welcome to stdout
*/
void print_welcome_screen();


#endif