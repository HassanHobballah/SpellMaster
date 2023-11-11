#include <stdio.h>
#include <stdlib.h>

#include "../include/OutputManager.h"

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

void clear_screen() { system(CLEAR_COMMAND); }

void print_end_screen(Game *game) {
  printf("-----------------------------------------------------------------"
         "\n\n\n\n\n");
  switch (game->game_state) {
  case ONGOING:
    printf(
        "                 ERROR: the game is not over yet                 \n");
    break;
  case Player1_WINS:
    printf("                            \033[0;31mPlayer1 WON!\033[0m              "
           "               \n");
    break;
  case Player2_WINS:
    printf("                         \033[0;33mPlayer2 WON!\033[0m              "
           "             \n");
    break;
  case TIE:
    printf("                            \033[0;32mTIE!\033[0m                  "
           "             \n");
    break;
  case Player1_WON_BY_TIME:
    printf("                            \033[0;31mPlayer1 WON BY TIME!\033[0m      "
           "                         \n");
    break;
  case Player2_WON_BY_TIME:
    printf(
        "                            \033[0;33mPlayer2 WON BY TIME!\033[0m      "
        "                         \n");
    break;
  default:
    break;
  }
  printf("\n");
}

void game_mode_screen() {
  printf("-----------\033[0;32mGAME MODES:\033[0m-----------\n\n");
  printf("         1) Simulation\n");
  printf("         2) Single-Player\n");
  printf("         3) Multi-Player\n\n");
  printf("---------------------------------\n");
  printf("Enter your choice (1-3): ");
}

void difficulty_screen() {
  printf("------\033[0;32mGAME DIFFICULTIES:\033[0m------\n\n");
  printf("          1) Easy\n");
  printf("          2) Medium\n");
  printf("          3) Hard\n\n");
  printf("------------------------------\n");
}