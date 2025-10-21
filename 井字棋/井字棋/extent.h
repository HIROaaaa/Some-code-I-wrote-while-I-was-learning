#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3  //设置棋盘行数
#define COL 3  //设置棋盘列数
#define Win 3  //设置胜利条件
void reboard(char board[ROW][COL], int row, int col);
void printboard(char board[ROW][COL], int row, int col);
void player(char board[ROW][COL], int row, int col);
void player2(char board[ROW][COL], int row, int col);
void computer(char board[ROW][COL], int row, int col);
int isWin(char board[ROW][COL], int row, int col);
int isWin2(char board[ROW][COL], int row, int col);

