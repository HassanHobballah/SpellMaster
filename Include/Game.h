#pragma once

#include "Types.h"

/**
  Checks whether Game `game` is `ONGOING`, or if a player has won
  @input:
    
  @assumes:
    
  @tested:
    
  @returns:
    
*/
GameState game_check_state(Game *game, int x);

/**
  @input:
    
  @assumes:
    
  @returns:
    
*/
bool game_put_token(Game *game, int x);

/**
  Initializes Game `game` and asks players for their names
  @input:
    Game `game`
*/
void game_init(Game *game);

/**
  Runs the current player's turn and changes who's turn is next
  @input:
    Game `game`
  @assumes:
    Game `game` has been initialized
    `game_state` is ONGOING
*/
void game_run_turn(Game *game);

/**
  Runs the Game `game` until the `game_state` is not `ONGOING`
  @input:
    Game `game`
  @assumes:
    Game has been initialized
*/
void game_run(Game *game);

/**
  Prints which player won and displays the amount of time each of them took
  @input:
    Game `game`
*/