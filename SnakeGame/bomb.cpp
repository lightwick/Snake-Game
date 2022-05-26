#include "value.h"
#include "SnakeGame.h"
#include <stdlib.h>
#include <stdio.h>

#define G_WIDTH X_END-X_BEGIN-1
#define G_HEIGHT Y_END-Y_BEGIN-1

typedef struct coordinate coordinate;
extern coordinate head, bend[500], food, body[MAX_SIZE];

//TODO: set bomb site to some color like: RED; food and bomb could be in the same place
int tick = 0;
// info for abs_y=11, abs_x=11 as 0, 0 in bombTimer (g_ to represent that)
int g_bombTimer[G_HEIGHT][G_WIDTH];

// sets n x n bomb
void setBomb(int n = 3, int timer = 5) {
	if (n <= 0) return;

	int abs_right_limit = X_END - n;
	int abs_left_limit = X_BEGIN + 1;
	int abs_bottom_limit = Y_END - n;
	int abs_top_limit = Y_BEGIN + 1;

	int abs_top_left_x = rand() % (abs_right_limit - abs_left_limit) + X_BEGIN;
	int abs_top_left_y = rand() % (abs_bottom_limit - abs_top_limit) + Y_BEGIN;

	for (int i = 0; i < n; i++) {
		gotoxy(abs_top_left_x,abs_top_left_y+i);
		for (int j = 0; j < n; j++) {
			g_bombTimer[abs_top_left_y - 11][abs_top_left_x - 11] = timer;
			printf("%d", timer);
		}
	}
}

void decreaseTimer() {
	for (int i = 0; i < G_WIDTH; i++) {
		for (int j = 0; j < G_HEIGHT; j++) {
			if (g_bombTimer[i][j] != 0) {
				g_bombTimer[i][j]--;
			}
		}
	}
}