#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<stdio.h>
#include "BoardUtils.h"
#include "movesUtil.h"

int main()
{
	srand(time(NULL));
	Board realBoard,myBoard;
	initializeBoard(&realBoard,&myBoard);
	//placeMines
	int **mines=placeMines(&realBoard);
	int x, y;
	while (1)
	{
		clearAndRedraw(myBoard);
		printf("\nenter your choice: (row column)");
		fflush(stdin);
		scanf("%d", &x);
		if (x == -1)
		{
			fflush(stdin);
			giveCheatSheet(realBoard);
			char ch=getchar();
			continue;
		}
		
		scanf("%d", &y);
		
		if (isValid(x-1, y-1, &realBoard))
		{
			if (handleMove(&myBoard, &realBoard, mines, x - 1, y - 1 )< 0)
				return 0;
			else if (wonGame(&myBoard,&realBoard))
			{
				printf("You won the game!");
					return 0;
			}
			
		}
		else
			printf("enter valid move");

	}


	return 0;
}