#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<locale.h>
#define POS_X 24
#define POS_Y 5
#define WALL L'□'
#define BODY L'●'
#define FOOD L'★'
//蛇的方向
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};
//蛇的状态
enum GAME_STATUS
{
	OK = 1,
	KILL_BY_WALL,
	KILL_BY_SELF,
	END_NORMAL
};
typedef struct SnakeNode
{
	//坐标
	int x;
	int y;
	//下一个节点
	struct SnakeNode* next;
}SnakeNode,* pSnakeNode;

typedef struct Snake
{
	pSnakeNode _pSnake;//指向蛇头
	pSnakeNode _pFood;//指向食物
	enum DIRECTION _dir;
	enum GAME_STATUS _status;
	int _food_weight;
	int _score;
	int _sleep_time;
}Snake,* pSnake;
//游戏初始化
void SetPos(short x, short y);
void GameStart(pSnake ps);
void WelcomeToGame();
void CreatMap();
void InitSnake(pSnake ps);
void CreatFood(pSnake ps);
void GmaeRun(pSnake ps);
void SnakeMove(pSnake ps);
int NextIsFood(pSnakeNode pn,pSnake ps);
void EatFood(pSnakeNode pn, pSnake ps);
void NoFood(pSnakeNode pn, pSnake ps);
void KillByWall(pSnake ps);
void KillBySelf(pSnake ps);
void GameEnd(pSnake ps);


