#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "FunctionHeader.h"
#include <string.h>

void singlePlayer(int num_spells, char spells[][MAX_SPELL_LENGTH], int difficulty) {
    char playerName[MAX_NAME_LENGTH];
    char botName[MAX_NAME_LENGTH] = "Bot";

    printf("Enter your name: ");
    scanf("%s", playerName);

    printf("Number of spells is: %d\n", num_spells);
    print_spells(num_spells, spells);

    srand(time(NULL));

    int whoStarts = rand() % 2;
    char *currentPlayer;
    char *currentBot;

    if (whoStarts == 0) {
        currentPlayer = playerName;
        currentBot = botName;
    } else {
        currentPlayer = botName;
        currentBot = playerName;
    }

    printf("\n\n%s starts.\n", currentPlayer);

    int spellUsed[MAX_SPELLS] = {0};
    int round = 1;
    int winner = 0;
    int remainingValidSpells = num_spells;
    char chosenSpells[MAX_SPELLS][MAX_SPELL_LENGTH];

    while (1) {
        char chosenSpell[MAX_SPELL_LENGTH];

        if (strcmp(currentPlayer, playerName) == 0) {
            printf("\nRound %d: %s, enter your spell: ", round, currentPlayer);
            scanf("%s", chosenSpell);
        } else {
            getBotMove(currentBot, spells, (round > 1) ? chosenSpells[round - 2] : "", num_spells, chosenSpell, difficulty);
        }

        int spellIndex = -1;
        for (int j = 0; j < num_spells; j++) {
            if (strcmp(chosenSpell, spells[j]) == 0 && spellUsed[j] == 0) {
                spellIndex = j;
                break;
            }
        }

        if (spellIndex == -1 || (round > 1 && chosenSpell[0] != chosenSpells[round - 2][strlen(chosenSpells[round - 2]) - 1])) {
            printf("Invalid spell or spell has already been used. %s wins because %s cannot make a valid move.\n", currentBot, currentPlayer);
            break;
        } else {
            spellUsed[spellIndex] = 1;
            strcpy(chosenSpells[round - 1], chosenSpell);
            round++;

            remainingValidSpells--;
        }

        if (remainingValidSpells == 0) {
            printf("No more valid moves for %s. %s wins!\n", currentPlayer, currentBot);
            winner = 1;
            break;
        }

        char *tempPlayer = currentPlayer;
        currentPlayer = currentBot;
        currentBot = tempPlayer;
    }

    if (winner) {
        printf("%s wins!\n", currentPlayer);
    }
}


void getBotMove(char* botName, char spells[MAX_SPELLS][MAX_SPELL_LENGTH], char* lastSpell, int numSpells, char* move, int difficulty) {
    switch (difficulty) {
        case 1:  // Easy
            for (int i = 0; i < numSpells; i++) {
                if (isValidMove(spells[i], lastSpell)) {
                    strcpy(move, spells[i]);
                    break;
                }
            }
            break;
        case 2:  // Medium
            int maxRemainingValidMoves = -1;
            for (int i = 0; i < numSpells; i++) {
                if (!isValidMove(spells[i], lastSpell)) continue;

                int remainingValidMoves = 0;
                for (int j = 0; j < numSpells; j++) {
                    if (!isValidMove(spells[j], spells[i])) continue;
                    remainingValidMoves++;
                }

                if (remainingValidMoves > maxRemainingValidMoves) {
                    maxRemainingValidMoves = remainingValidMoves;
                    strcpy(move, spells[i]);
                }
            }
            break;
        case 3:  // Hard
            int minRemainingValidMoves = numSpells + 1;

            for (int i = 0; i < numSpells; i++) {
                if (!isValidMove(spells[i], lastSpell)) continue;
                int remainingValidMoves = 0;
                int opponentRemainingValidMoves;

                for (int j = 0; j < numSpells; j++) {
                    if (!isValidMove(spells[j], spells[i])) continue;
                    opponentRemainingValidMoves = 0;
                    for (int k = 0; k < numSpells; k++) {
                        if (!isValidMove(spells[k], spells[j])) continue;
                        opponentRemainingValidMoves++;
                    }
                    if (opponentRemainingValidMoves < minRemainingValidMoves) {
                        minRemainingValidMoves = opponentRemainingValidMoves;
                        strcpy(move, spells[i]);
                    }
                }
            }
            break;
        default:
            printf("Invalid difficulty level for the bot.\n");
            exit(1);
    }

    printf("Bot chooses: %s\n", move);
}

// Function to check if a move is valid based on the last spell
bool isValidMove(const char* spell, const char* lastSpell) {
    return (strcmp(lastSpell, "") == 0 || lastSpell[strlen(lastSpell) - 1] == spell[0]);
}


void print_spells(int num_spells, char spells[][MAX_SPELL_LENGTH]) {
    int n = 0;
    for (int j = 0; j < num_spells; j++) {
        printf("Spell %d: %s\t", j + 1, spells[j]);
        n++;
        if (n == 5) {
            printf("\n");
            n = 0;
        }
    }
    printf("\n");
}


int two_player(int num_spells, char spells[][MAX_SPELL_LENGTH]) {
    char Player1[MAX_NAME_LENGTH];
    char Player2[MAX_NAME_LENGTH];

    printf("Please enter your names:\nPlayer 1: ");
    scanf("%s", Player1);
    printf("Player 2: ");
    scanf("%s", Player2);

    printf("Number of spells is: %d\n", num_spells);
    print_spells(num_spells, spells);

    srand(time(NULL));
    int whoStarts = rand() % 2;
    char *currentPlayer;
    char *otherPlayer;

    if (whoStarts == 0) {
        currentPlayer = Player1;
        otherPlayer = Player2;
    } else {
        currentPlayer = Player2;
        otherPlayer = Player1;
    }

    printf("\n\n%s starts.\n", currentPlayer);

    int spellUsed[79] = {0};
    int round = 1;
    int winner = 0;
    int remainingValidSpells = num_spells;
    char chosenSpells[79][MAX_SPELL_LENGTH];

    while (1) {
        char chosenSpell[MAX_SPELL_LENGTH];

        printf("\nRound %d: %s, enter your spell: ", round, currentPlayer);
        scanf("%s", chosenSpell);

        int spellIndex = -1;
        for (int j = 0; j < num_spells; j++) {
            if (strcmp(chosenSpell, spells[j]) == 0 && spellUsed[j] == 0) {
                spellIndex = j;
                break;
            }
        }

        if (spellIndex == -1) {
            printf("Invalid spell or spell has already been used. %s wins because %s cannot make a valid move.\n", otherPlayer, currentPlayer);
            break;
        } else {
            spellUsed[spellIndex] = 1;
            strcpy(chosenSpells[round - 1], chosenSpell);
            round++;

            char lastChar = chosenSpell[strlen(chosenSpell) - 1];
            int validMove = 0;

            for (int j = 0; j < num_spells; j++) {
                if (spellUsed[j] == 0 && spells[j][0] == lastChar) {
                    validMove = 1;
                    break;
                }
            }

            if (!validMove) {
                printf("Invalid move. %s wins because %s cannot make a valid move.\n", otherPlayer, currentPlayer);
                winner = 1;
                break;
            } else {
                remainingValidSpells--;
            }
        }

        if (remainingValidSpells == 0) {
            printf("No more valid moves for %s. %s wins!\n", currentPlayer, otherPlayer);
            winner = 1;
            break;
        }

        char *tempPlayer = currentPlayer;
        currentPlayer = otherPlayer;
        otherPlayer = tempPlayer;
        whoStarts = (whoStarts == 0) ? 1 : 0;
    }

    if (winner) {
        printf("%s wins!\n", currentPlayer);
    }

    return 0; 
}

