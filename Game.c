#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

    FILE *sp;
    sp = fopen("spells.txt", "r");

    if (sp == NULL) {
        perror("Error opening file");
        return 0;
    }

    int value;
    char spells[79][20];
    fscanf(sp, "%d", &value);

    int i = 0;
    while (fscanf(sp, "%19s", spells[i]) == 1) {
        i++;
    }
    fclose(sp);

    char Player1[40];
    char Player2[40];
    printf("Please enter your names:\nPlayer 1: ");
    scanf("%s", Player1);
    printf("Player 2: ");
    scanf("%s", Player2);

    printf("Number of spells is: %d\n", value);
    int n = 0;
    for (int j = 0; j < i; j++) {
        printf("Spell %d: %s\t", j + 1, spells[j]);
        n++;
        if (n == 5) {
            printf("\n");
            n = 0;
        }
    }

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
    int remainingValidSpells = i;
    char chosenSpells[79][20];

    while (1) {
        char chosenSpell[20];

        printf("\nRound %d: %s, enter your spell: ", round, currentPlayer);
        scanf("%s", chosenSpell);

        int spellIndex = -1;
        for (int j = 0; j < i; j++) {
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

            for (int j = 0; j < i; j++) {
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