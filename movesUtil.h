int isValid(int row, int col, Board *realBoard)
{
	if (row < 0 || col < 0 || row >= realBoard->size || col >= realBoard->size)
		return 0;
	return 1;
}
int isMine(int row, int col, Board *realBoard)
{
	if (realBoard->table[row][col] == '*')
		return 1;
	else
		return 0;
}

int countAdjacentMines(int row, int col, int **mines, Board *realBoard)
{
	int i, count = 0;
	if (isValid(row - 1, col, realBoard) == 1)
	{
		if (isMine(row - 1, col, realBoard) == 1)
			count++;
	}
	if (isValid(row + 1, col, realBoard) == 1)
	{
		if (isMine(row + 1, col, realBoard) == 1)
			count++;
	}

	if (isValid(row, col + 1, realBoard) == 1)
	{
		if (isMine(row, col + 1, realBoard) == 1)
			count++;
	}


	if (isValid(row, col - 1, realBoard) == 1)
	{
		if (isMine(row, col - 1, realBoard) == 1)
			count++;
	}


	if (isValid(row - 1, col + 1, realBoard) == 1)
	{
		if (isMine(row - 1, col + 1, realBoard) == 1)
			count++;
	}

	if (isValid(row - 1, col - 1, realBoard) == 1)
	{
		if (isMine(row - 1, col - 1, realBoard) == 1)
			count++;
	}


	if (isValid(row + 1, col + 1, realBoard) == 1)
	{
		if (isMine(row + 1, col + 1, realBoard) == 1)
			count++;
	}


	if (isValid(row + 1, col - 1, realBoard) == 1)
	{
		if (isMine(row + 1, col - 1, realBoard) == 1)
			count++;
	}
	return count;
}
	


int handleMove(Board * myBoard, Board*realBoard, int **mines, int row, int col)
{
	
	int i, j;
	if (realBoard->table[row][col] >= '0' || realBoard->table[row][col] <= 9)
		return 0;
	if (realBoard->table[row][col] == '*')
	{
		myBoard->table[row][col] = '*';


		for (i = 0; i < myBoard->mines; i++)
			myBoard->table[mines[i][0]][mines[i][1]] = '*';

		printBoard(*myBoard);
		printf("\nSorry, you stepped on a mine! You lost!\n");
		return -1;
	}
	else
	{
		int count = countAdjacentMines(row, col, mines, realBoard);
		myBoard->table[row][col] = count + '0';
		if (!count)
		{
			if (isValid(row - 1, col, realBoard) == 1)
			{
				if (myBoard->table[row - 1][ col]=='-')
					handleMove(myBoard, realBoard, mines, row - 1, col);
			}
			if (isValid(row + 1, col, realBoard) == 1)
			{
				if (myBoard->table[row + 1][col] == '-')
					handleMove(myBoard, realBoard, mines, row + 1, col);
			}
			if (isValid(row, col + 1, realBoard) == 1)
			{
				if (myBoard->table[row ][col+1] == '-')
					handleMove(myBoard, realBoard, mines, row, col + 1);
			}
			if (isValid(row, col - 1, realBoard) == 1)
			{
				if (myBoard->table[row ][col-1] == '-')
					handleMove(myBoard, realBoard, mines, row, col - 1);
			}
			if (isValid(row - 1, col + 1, realBoard) == 1)
			{
				if (myBoard->table[row - 1][col+1] == '-')
					handleMove(myBoard, realBoard, mines, row - 1, col + 1);
			}
			if (isValid(row - 1, col - 1, realBoard) == 1)
			{
				if (myBoard->table[row - 1][col-1] == '-')
					handleMove(myBoard, realBoard, mines, row - 1, col - 1);
			}
			if (isValid(row + 1, col + 1, realBoard) == 1)
			{
				if (myBoard->table[row +1][col+1] == '-')
					handleMove(myBoard, realBoard, mines, row + 1, col + 1);
			}
			if (isValid(row + 1, col - 1, realBoard) == 1)
			{
				if (myBoard->table[row +1][col-1] == '-')
					handleMove(myBoard, realBoard, mines, row + 1, col - 1);
			}
		}
		return 1;
	}


}