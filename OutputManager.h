#pragma once

#include "Types.h"

void print_end_screen(Game *game);

/**
  Prints the different game modes to stdout
*/
void game_mode_screen();

/**
  Prints the difficulty levels to stdout
*/
void difficulty_screen();

#ifdef _WIN32
#define PRINTREDTOKEN() printf(" \033[0;31m%c%c\033[0m ", 219, 219);
#define PRINTYELLOWTOKEN() printf(" \033[0;33m%c%c\033[0m ", 219, 219);
#else
#define PRINTREDTOKEN() printf(" \033[0;31m%s\033[0m ", "██");
#define PRINTYELLOWTOKEN() printf(" \033[0;33m%s\033[0m ", "██");
#endif
