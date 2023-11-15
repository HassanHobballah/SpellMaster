#include <stdio.h>
#include <stdlib.h>

#include "FunctionHeader.h"

void game_mode_screen(int *userChoice) {
    printf("-----------\033[0;32mGAME MODES:\033[0m-----------\n\n");
    printf("     1) Simulation\n");
    printf("     2) Two-Player\n\n"); 
    printf("---------------------------------\n");
    printf("Enter your choice (1-2): ");

    scanf("%d", userChoice);
}

void difficulty_screen() {
  printf("------\033[0;32mGAME DIFFICULTIES:\033[0m------\n\n");
  printf("          1) Easy\n");
  printf("          2) Medium\n");
  printf("          3) Hard\n\n");
  printf("------------------------------\n");
}


void print_welcome_screen() {
    printf("\n");
    printf("          Welcome to the Spell Master Game!\n");
    printf("     Two wizards will battle by casting spells,\n");
    printf("   choosing wisely to outsmart their opponent.\n");
    printf("\n");
    printf("          May the magical duels begin!\n\n\n");
}