#define _CRT_SECURE_NO_WARNINGS
#include "extent.h"
void game()
{
	int b = 0;
	printf("------------------------------------\n");
	printf("--------1.PVP----------2.PVE--------\n");
	printf("------------------------------------\n");
	printf("��ѡ��Please select��");
	scanf("%d", &b);
	switch (b)
	{
	case 1: {
		//��ʼ�����飨���̣�Initialize the array (board)
		char board[ROW][COL] = { 0 };
		reboard(board, ROW, COL);
		//��ӡ����Print the chessboard
		printboard(board, ROW, COL);
		while (1)
		{
			int i = 0;
			//����play chess
			//1.���1��Player 1
			player(board, ROW, COL);
			printboard(board, ROW, COL);
			//�ж���ӮJudging the winner or loser
			i = isWin(board, ROW, COL);
			if (i == 1)
			{
				printf("\n");
				printf("\n");
				printf("���1ӮPlayer 1 wins\n");
				printboard(board, ROW, COL);
				break;
			}
			else if (i == 4)
			{
				printf("\n");
				printf("\n");
				printf("ƽ��draw\n");
				printboard(board, ROW, COL);
				break;
			}
			player2(board, ROW, COL);
			printboard(board, ROW, COL);
			i = isWin2(board, ROW, COL);
			if (i == 2)
			{
				printf("\n");
				printf("\n");
				printf("���2ӮPlayer 2 wins\n");
				printboard(board, ROW, COL);
				break;
			}
			else if (i == 4)
			{
				printf("\n");
				printf("\n");
				printf("ƽ��draw\n");
				printboard(board, ROW, COL);
				break;
			}
		}
		break;
	}
	case 2: {
		char board[ROW][COL] = { 0 };
		reboard(board, ROW, COL);
		printboard(board, ROW, COL);
		while (1)
		{
			int i = 0;
			player(board, ROW, COL);
			printboard(board, ROW, COL);
			i = isWin(board, ROW, COL);
			if (i == 1)
			{
				printf("\n");
				printf("\n");
				printf("���ӮPlayers win\n");
				printboard(board, ROW, COL);
				break;
			}
			else if (i == 4)
			{
				printf("\n");
				printf("\n");
				printf("ƽ��draw\n");
				printboard(board, ROW, COL);
				break;
			}
			computer(board, ROW, COL);
			printboard(board, ROW, COL);
			i = isWin(board, ROW, COL);
			if (i == 2)
			{
				printf("\n");
				printf("\n");
				printf("����ӮComputer wins\n");
				printboard(board, ROW, COL);
				break;
			}
			else if (i == 3)
			{
				continue;
			}
			else
			{
				printf("\n");
				printf("\n");
				printf("ƽ��draw\n");
				printboard(board, ROW, COL);
				break;
			}
		}
		break;
	}
	default: {
		printf("�������Input error");
		break;
	}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int n = 0;
	while (1)
	{
		printf("\n");
		printf("\n");
		printf("\n");
		printf("%d������Ϸ(Three piece chess game)��\n",Win);
		printf("------------------------------------\n");
		printf("-------1.start--------2.exit--------\n");
		printf("------------------------------------\n");
		printf("��ѡ��(Please select):");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			game();

			break;
		}
		case 2:break;
		default:printf("�������Input error\n");
		}
	}
}