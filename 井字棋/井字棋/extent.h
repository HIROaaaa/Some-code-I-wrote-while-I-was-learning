#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3  //������������
#define COL 3  //������������
#define Win 3  //����ʤ������
void reboard(char board[ROW][COL], int row, int col);
void printboard(char board[ROW][COL], int row, int col);
void player(char board[ROW][COL], int row, int col);
void player2(char board[ROW][COL], int row, int col);
void computer(char board[ROW][COL], int row, int col);
int isWin(char board[ROW][COL], int row, int col);
int isWin2(char board[ROW][COL], int row, int col);

