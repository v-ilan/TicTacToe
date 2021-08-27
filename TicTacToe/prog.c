#include <stdio.h>
#include <stdlib.h>
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
#define NUM_PLAYERS 2

int startGame();
int checkWinner(char board[][COLS]);
int doTurn(char board[][COLS], int player);
int displayBoard(char board[][COLS]);

int main()
{
	int stopGame = FALSE;
	char board[ROWS][COLS] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	int player = 0;
	stopGame =startGame(board);
	while (!stopGame)
	{
		system("cls");
		puts("Lets play Tic-Tac-Toe!");
		displayBoard(board);
		stopGame = checkWinner(board);
		player = doTurn(board, player);
	}
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
int startGame()
{
	int stopGame = TRUE;
	char answer = '0';

	system("cls");
	puts("Welcome players!");
	puts("This is a game of Tic-Tac-Toe");
	puts("As you will see in the board is as the numpad on the right of your keyboard");
	puts("Do you wish to play?");
	puts("click y or Y to play and anything else to quit the game");
	answer = _getch();
	printf("%c\n",answer);
	if (answer == 'y' || answer == 'Y')
	{
		stopGame = FALSE;
	}
	return stopGame;
}

/*
	function checks if last player won
	input: gamaing board, player num
	output: 0 - if no player won
			1 - if player1 won
			2 - if player2 won
*/
int checkWinner(char board[][COLS])
{
	return 0;
}

/*
	this is the main game function, where the players make turns
	input: gamaing board
	output: 0 on success
*/
int doTurn(char board[][COLS], int player)
{
	int winner = 0;
	int cell = 0, row = 0, col = 0;
	int madeTurn = FALSE;
	player %= NUM_PLAYERS;
	puts("player 1 you play X, player 2 you are O");
	printf("player %d, it's your turn\n", player + 1);
	do
	{
		puts("choose an empty cell, by click on a number, and make your move");
		cell = _getch();
		putchar(cell);
		if (cell >= '1' && cell <= '9') //check if is a number
		{
			cell = cell - '0';
			row = ROWS - 1 - (cell-1) / ROWS;
			col = (cell - 1) % COLS;
			if (' ' == board[row][col]) //check if player chose an empty cell
			{
				if (player)
				{
					board[row][col] = 'O';
				}
				else
				{
					board[row][col] = 'X';
				}
				//move to next player
				madeTurn = TRUE;
				player++;
			}
			else
			{
				printf("player %d,", player + 1);
				puts("this cell is not empty");
			}
		}
		else
		{
			printf("player %d,", player + 1);
			puts("you didnt choose a number");
		}
	} while (!madeTurn);
	return player;
}

/*
	Function will display game-board
	input: two dim array - board
	output: 0 on success
*/
int displayBoard(char board[][COLS])
{
	int rows = 0, cols = 0;
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