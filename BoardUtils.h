#include<stdlib.h>
#include <string.h>
typedef struct Board {
	char **table;
	int size;
	int mines;
};

//void initialize(Board * board);
void printBoard(Board board);
void clearScreen();
void printBoard(Board board);
void initializeBoard(Board *realBoard, Board *myBoard);
int** placeMines(Board *board);

void initializeBoard(Board *realBoard, Board *myBoard)
{
	int SIDE = 9,i,j;

	realBoard->size = SIDE;
	realBoard->mines = 10;
	myBoard->size = SIDE;
	myBoard->mines = 10;
	realBoard->table = (char **)malloc(sizeof(char*) * SIDE);
	myBoard->table = (char **)malloc(sizeof(char*) * SIDE);

	for ( i = 0; i < SIDE; i++)
	{
		realBoard->table[i] = (char *)malloc(sizeof(int)*SIDE);
		myBoard->table[i] = (char *)malloc(sizeof(int)*SIDE);

		for (j = 0; j < SIDE; j++)
		{
			realBoard->table[i][j] = myBoard->table[i][j]= '-';
		}
	}
	
	return;
}

int** placeMines(Board *board)
{
	int **mines = (int**)malloc(sizeof(int)*board->mines);


	int i, j;
	
	
	int random;

	// Continue until all random mines have been created.
	for ( i = 0; i<board->mines;)
	{
		random = rand() % (board->size*board->size);
		int x = random % board->size;
		random = rand() % (board->size*board->size);
		int y = random % board->size;
		if (board->table[x][y] != '*')
		{
			mines[i] = (int *)malloc(sizeof(int) * 2);
			// Row Index of the Mine
			mines[i][0] = x;
			// Column Index of the Mine
			mines[i][1] = y;

			// Place the mine
			board->table[x][y] = '*';
			//mark[random] = 1;
			i++;
		}
	}
	return mines;
}

void printBoard(Board board)
{
	printf("  1 2 3 4 5 6 7 8 9 \n");
	for (int i = 0; i < board.size; i++)
	{
		printf("%d ",i + 1);
		for (int j = 0; j < board.size; j++)
		{
			printf("%c ", board.table[i][j]);
		}
		printf("\n");
	}
}
void clearScreen(){
	system("cls");
}

void clearAndRedraw(Board board)
{
	clearScreen();
	printBoard(board);
}

void giveCheatSheet(Board board)
{
	clearScreen();
	printf("Congrats on cracking!!..here goes your cheatsheet\n");
	printBoard(board);
	printf("press any key to continue\n");

}

int wonGame(Board *board,Board *realBoard)
{
	int i, j;
	for (i = 0; i < board->size; i++)
	{
		for (j = 0; j < board->size; j++)
		{
			if (board->table[i][j] == '-'&&realBoard->table[i][j] != '*')
				return 0;
		}
	}
	return 1;
}
