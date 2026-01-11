#define _CRT_SECURE_NO_WARNINGS
#include"snake.h"
#include<time.h>
void test()
{
	int ch = 0;
	do
	{
		system("cls");
		//创建贪吃蛇
		Snake snake = { 0 };
		//初始化游戏
		//1.欢迎界面
		//2.功能介绍
		//3.绘制地图
		//4.创建蛇
		//5.创建食物
		//6.设置相关信息
		GameStart(&snake);


		//运行游戏
		GmaeRun(&snake);
		////结束游戏-善后
		GameEnd(&snake);
		SetPos(20, 15);
		printf("再来一局吗(Y/N):");
		ch=getchar();

		while (getchar() != '\n');

	} while (ch=='Y'||ch=='y');
	SetPos(0, 27);
}
int main()
{
	setlocale(LC_ALL, "");
	srand((unsigned int)time(NULL));
	test();
}