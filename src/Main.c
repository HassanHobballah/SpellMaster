#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "FunctionHeader.h"

int main() {
    void print_welcome_screen();

    FILE *sp;
    sp = fopen("spells.txt", "r");

    if (sp == NULL) {
        perror("Error opening file");
        return 1;
    }

    int value;
    char spells[79][20];
    fscanf(sp, "%d", &value);

    int i = 0;
    while (fscanf(sp, "%19s", spells[i]) == 1) {
        i++;
    }
    fclose(sp);

    print_welcome_screen();

    int game_mode;
    game_mode_screen(&game_mode);

    switch (game_mode) {
    case 1:  // Single-Player
        int difficulty;
        printf("\nChoose difficulty level (1: Easy, 2: Medium, 3: Hard): ");
        scanf("%d", &difficulty);
        singlePlayer(i, spells, difficulty);
        break;
    case 2:  // Two-Player
        two_player(i, spells);
        break;
    }
    return 0;
}








