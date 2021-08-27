#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
/**
	This is the first rpogram im uploading to GitHub
	So I decided to mamke a tix-tac-toe game for my time
	Creator: Ilan Vol
**/

#define FALSE 0
#define TRUE !FALSE
#define ROWS 3
#define COLS 3

bool startGame();
int displayBoard(char board[][COLS]);

int main()
{
	bool toPlay = FALSE;
	char board[ROWS][COLS] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	toPlay=startGame(board);
	//while(toPlay)
	displayBoard(board);
	puts("Bye-bye");
	system("pause");
	return 0;
}


/*
	printf a B E A Utiful welcoming messege for the players and ask if they want to play
	input:  none
	output: FALSE - if players dont want to play
	        TRUE  - if players want to play
*/
bool startGame()
{
	bool toPlay = FALSE;
	char answer = '0';

	system("cls");
	puts("Welcome players!");
	puts("This is a game of Tic-Tac-Toe");
	puts("As you will see in the board below, it is as the numpad on the right of your keyboard");
	puts("Do you wish to play?");
	puts("click y or Y to play and anything else to quit the game");
	answer = _getch();
	printf("%c\n",answer);
	if (answer == 'y' || answer == 'Y')
	{
		puts("Lets play Tic-Tac-Toe!");
		toPlay = TRUE;
	}
	return toPlay;
}

/*
	Function will display game-board
	input: two dim array - board
	output: 0 on success
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