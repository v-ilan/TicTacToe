#include <stdio.h>
#include <stdlib.h>
/**
	This is the first rpogram im uploading to GitHub
	So I decided to mamke a tix-tac-toe game for my time
	Creator: Ilan Vol

**/

#define ROWS 3
#define COLS 3

int displayBoard(char board[][COLS]);

int main()
{
	char board[ROWS][COLS] = { {'7','8','9'},{'4','5','6'},{'1','2','3'} };

	displayBoard(board);
	return 0;
}


/*
	Function will display game-board
*/
int displayBoard(char board[][COLS])
{
	int rows = 0, cols = 0;
	system("cls");
	printf("-------------------\n");
	for (rows = 0; rows < ROWS; rows++)
	{
		putchar('|');
		for (cols = 0; cols < COLS; cols++)
		{
			printf("    %d|", ROWS*(ROWS-rows)-COLS+cols+1);
		}
		printf("\n|");
		for (cols = 0; cols < COLS; cols++)
		{
			printf("  %c  |", board[rows][cols]);
		}
		printf("\n|     |     |     |\n");
	}
	printf("-------------------\n");

	return 0;
}