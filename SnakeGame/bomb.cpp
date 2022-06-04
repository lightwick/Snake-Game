#include "value.h"
#include "SnakeGame.h"
#include "console_related.h"
#include <stdlib.h>
#include <stdio.h>

#define DEBUG

typedef struct coordinate coordinate;
extern coordinate head, bend[500], food, body[MAX_SIZE];

//TODO: set bomb site to some color like: RED; food and bomb could be in the same place
int tick = 0;
// info for abs_y=11, abs_x=11 as 0, 0 in bombTimer (g_ to represent that)
int g_bombTimer[G_HEIGHT][G_WIDTH];

// sets n x n bomb
void setBomb(int score) {
	// n: bomb size; random number between 2 and 4, inclusive
	int n = rand() % 3 + 2 + score / 20;
	// timer: random number between 3 and 5, inclusive
	int timer = rand() % 3 + 3;

	int abs_right_limit = X_END - n;
	int abs_left_limit = X_BEGIN + 1;
	int abs_bottom_limit = Y_END - n;
	int abs_top_limit = Y_BEGIN + 1;

	int abs_top_left_x = rand() % (abs_right_limit - abs_left_limit + 1) + X_BEGIN + 1;
	int abs_top_left_y = rand() % (abs_bottom_limit - abs_top_limit + 1) + Y_BEGIN + 1;

	for (int i = 0; i < n; i++) {
		gotoxy(abs_top_left_x, abs_top_left_y + i);
		for (int j = 0; j < n; j++) {
			int* nextBomb = &g_bombTimer[abs_top_left_y - 11 + i][abs_top_left_x - 11 + j];
			// if there already is a bomb in the area, do not place a new one
			if (*nextBomb != -1) continue;
			g_bombTimer[abs_top_left_y - 11 + i][abs_top_left_x - 11 + j] = timer;
			printf("%d", timer);
		}
	}
}

void decreaseTimer() {
	for (int i = 0; i < G_HEIGHT; i++) {
		for (int j = 0; j < G_WIDTH; j++) {
			if (g_bombTimer[i][j] != -1) {
				g_bombTimer[i][j]--;
				gotoxy(j + X_BEGIN + 1, i + Y_BEGIN + 1);

				switch (g_bombTimer[i][j]) {
				case -1:
					printf(" ");
					break;
				case 0:
					setTextColor(RED);
					printf("B");
					setTextColor(WHITE);
					if (isDead()) ExitGame();
					break;
				default:
					printf("%d", g_bombTimer[i][j]);
				}
			}
		}
	}
}