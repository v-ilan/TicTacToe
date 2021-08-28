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
#define NUM_ROUNDS 9

int startGame();
int anEnd(int gameStop);
int checkWinner(char board[][COLS], int player, const int  ROW_SIZE);
int doTurn(char board[][COLS], int player, const int ROW_SIZE);
int displayBoard(char board[][COLS], const int  ROW_SIZE);
/*
* 
*/
int main()
{
	int stopGame = FALSE, rounds = NUM_ROUNDS;
	char board[ROWS][COLS] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	int player = NUM_PLAYERS;
	stopGame =startGame(board);
	while (rounds && !stopGame)
	{
		system("cls");
		puts("Lets play Tic-Tac-Toe!");
		displayBoard(board, ROWS);
		rounds--;
		player=doTurn(board, player, ROWS);
		stopGame = checkWinner(board, player, ROWS);
	}
	system("cls");
	displayBoard(board, ROWS);
	anEnd(stopGame);
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
	Function will announce who won the game or tell if no one did
	input:	gameStop - indication of winner
	output: 0 on success
*/
int anEnd(int gameStop)
{

	if (gameStop)
	{
		printf("player %d hsa won the game!\n", gameStop);
	}
	else
	{
		puts("No one has one the game");
	}
	return 0;
}

/*
	function checks if last player won
	input: gamaing board, player num
	output: 0 - if no player won
			1 - if player1 won
			2 - if player2 won
*/
int checkWinner(char board[][COLS], int player, const int  ROW_SIZE)
{
	char sym = 'X';
	int isWinner = FALSE, winner = 0;
	int flag = FALSE;
	int rows = 0, cols = 0;

	if (player-1)
	{
		sym = 'O';
	}
	putchar(sym);
	//check main diag
	for (rows = 0, cols = 0; !flag && rows < ROW_SIZE && cols < COLS; rows++, cols++)
	{
		if (board[rows][cols] != sym)
		{
			flag = TRUE;
		}
	}
	if (!flag)
	{
		isWinner = TRUE;
	}
	else
	{	//check sec diag
		flag = FALSE;
		for (rows = ROW_SIZE-1, cols = 0; !flag && rows >= 0 && cols < COLS; rows--, cols++)
		{
			if (board[rows][cols] != sym)
			{
				flag = TRUE;
			}
		}
		if (!flag)
		{
			isWinner = TRUE;
		}
		else
		{	//check by rows
			flag = FALSE;
			for (rows = 0; !isWinner && rows < ROW_SIZE; rows++)
			{
				for (cols = 0; !flag && cols < COLS; cols++)
				{
					if (sym != board[rows][cols])
					{
						flag = TRUE;
					}
				}
				if (!flag)
				{
					isWinner = TRUE;
				}
			}
			//check by cols
			flag = FALSE;
			for (cols = 0; !isWinner && cols < COLS; cols++)
			{
				flag = FALSE;
				for (rows = 0; !flag && rows < ROW_SIZE; rows++)
				{
					if (sym != board[rows][cols])
					{
						flag = TRUE;
					}
				}
				if (!flag)
				{
					isWinner = TRUE;
				}
			}
		}
	}
	//call winner to stop game
	if (isWinner)
	{
		winner = player;
	}
	return winner;
}

/*
	this is the main game function, where the players make turns
	input: gamaing board
	output: 0 on success
*/
int doTurn(char board[][COLS], int player, const int  ROW_SIZE)
{
	int winner = 0;
	int cell = 0, row = 0, col = 0;
	int madeTurn = FALSE;
	player = player % NUM_PLAYERS + 1;
	puts("player 1 you play X, player 2 you are O");
	printf("player %d, it's your turn\n", player);
	do
	{
		puts("choose an empty cell, by click on a number, and make your move: ");
		cell = _getch();
		putchar(cell);
		if (cell >= '1' && cell <= '9') //check if is a number
		{
			cell = cell - '0';
			row = ROW_SIZE - 1 - (cell-1) / ROW_SIZE;
			col = (cell - 1) % COLS;
			if (' ' == board[row][col]) //check if player chose an empty cell
			{
				if (player-1)
				{
					board[row][col] = 'O';
				}
				else
				{
					board[row][col] = 'X';
				}
				//move to next player
				madeTurn = TRUE;
			}
			else
			{
				printf("player %d,", player);
				puts("this cell is not empty");
			}
		}
		else
		{
			printf("player %d,", player);
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
int displayBoard(char board[][COLS], const int  ROW_SIZE)
{
	int rows = 0, cols = 0;
	printf("-------------------\n");
	for (rows = 0; rows < ROW_SIZE; rows++)
	{
		putchar('|');
		for (cols = 0; cols < COLS; cols++)
		{
			printf("    %d|", ROW_SIZE *(ROW_SIZE -rows)-COLS+cols+1);
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