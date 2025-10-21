#define _CRT_SECURE_NO_WARNINGS
#include "extent.h"
void reboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row;i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void printboard(char board[ROW][COL],int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j<col-1)
			printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void player(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = 0;
		int y = 0;
		printf("������Ҫ�µ�λ��(����:1 1)(Please enter the location to be downloaded)(exmple:1 1)��");
		scanf("%d %d", &x, &y);
		if (x <= row && y <= col & x >= 1 & y >= 1)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("��λ���Ѿ����壬��������This position is already playing chess, please try again\n");
		}
		else
		{
			printf("�������Input error\n");
		}
	}
}
void player2(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = 0;
		int y = 0;
		printf("������Ҫ�µ�λ��(����:1 1)(Please enter the location to be downloaded(exmple[1 1])��");
		scanf("%d %d", &x, &y);
		if (x <= row && y <= col & x >= 1 & y >= 1)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
				printf("��λ���Ѿ����壬��������This position is already playing chess, please try again\n");
		}
		else
		{
			printf("�������Input error\n");
		}
	}
}

void computer(char board[ROW][COL], int row, int col)
{
	int i, j;
	while (1)
	{
		i = rand() % row;
		j = rand() % col;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
}
int isWin(char board[ROW][COL], int row, int col)
{
	// ���ж�Line judgment
	int n = 0, m = 0;
	for (int i = 0; i < row; i++)
	{
		n = 0; m = 0;
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == '*') n++;
			else if (board[i][j] == '#') m++;
		}
		if (n == Win) return 1;  // ���ӮPlayers win
		if (m == Win) return 2;  // ����ӮComputer wins
	}

	// ���ж�Column judgment
	for (int j = 0; j < col; j++)
	{
		n = 0; m = 0;
		for (int i = 0; i < row; i++)
		{
			if (board[i][j] == '*') n++;
			else if (board[i][j] == '#') m++;
		}
		if (n == Win) return 1;
		if (m == Win) return 2;
	}

	// �Խ���1�����ϵ����£�Diagonal 1 (top left to bottom right)
	n = 0; m = 0;
	for (int i = 0; i < row; i++)
	{
		int j = i;
		if (board[i][j] == '*') n++;
		else if (board[i][j] == '#') m++;
	}
	if (n == Win) return 1;
	if (m == Win) return 2;

	// �Խ���2�����ϵ����£�Diagonal 2 (top left to bottom right)
	n = 0; m = 0;
	for (int i = 0; i < row; i++)
	{
		int j = row - 1 - i;
		if (board[i][j] == '*') n++;
		else if (board[i][j] == '#') m++;
	}
	if (n == Win) return 1;
	if (m == Win) return 2;

	// ����Ƿ��пո�δ������Check for spaces (not filled)
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 3;  // �пո񣬼�����ϷThere are spaces, continue the game
			}
		}
	}

	// û�пո�ƽ��No spaces, tie
	return 4;
}
int isWin2(char board[ROW][COL], int row, int col)
{
	int n = 0, m = 0;
	for (int i = 0; i < row; i++)
	{
		n = 0; m = 0;
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == '*') n++;
			else if (board[i][j] == '#') m++;
		}
		if (n == Win) return 1;  // Players 1 wins
		if (m == Win) return 2;  // Players 2 wins
	}
	for (int j = 0; j < col; j++)
	{
		n = 0; m = 0;
		for (int i = 0; i < row; i++)
		{
			if (board[i][j] == '*') n++;
			else if (board[i][j] == '#') m++;
		}
		if (n == Win) return 1;
		if (m == Win) return 2;
	}
	n = 0; m = 0;
	for (int i = 0; i < row; i++) 
	{
		int j = i;
		if (board[i][j] == '*') n++;
		else if (board[i][j] == '#') m++;
	}
	if (n == Win) return 1;
	if (m == Win) return 2;
	n = 0; m = 0;
	for (int i = 0; i < row; i++)
	{
		int j = row - 1 - i;
		if (board[i][j] == '*') n++;
		else if (board[i][j] == '#') m++;
	}
	if (n == Win) return 1;
	if (m == Win) return 2;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 3;
			}
		}
	}
	return 4;
}

	