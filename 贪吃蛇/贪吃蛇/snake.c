#define _CRT_SECURE_NO_WARNINGS
#include"snake.h"
void SetPos(short x, short y)
{
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x,y };
	SetConsoleCursorPosition(houtput, pos);
}
void WelcomeToGame()
{
	SetPos(40, 14);
	wprintf(L"欢迎来到贪吃蛇小游戏\n");
	SetPos(42, 20);
	system("pause");
	system("cls");
	SetPos(25, 14);
	wprintf(L"用 ↑.↓.←.→来控制蛇的方向   F3加速，F4减速");
	SetPos(25,15);
	wprintf(L"加速能够得到更高的分数");
	SetPos(42, 20);
	system("pause");
	system("cls");
}
void CreatMap() 
{
	//上
	int i = 0;
	for (i= 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}
	//下
	SetPos(0, 26);
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}
	//左
	for (i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	//右
	for (i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc",WALL);
	}

}
void InitSnake(pSnake ps)
{
	pSnakeNode cur = NULL;
	for (int i = 0; i < 5; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("InitSnake()::malloc()");
			return;
		}
		cur->next = NULL;
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;
		//头插法插入链表
		if (ps->_pSnake == NULL)
		{
			ps->_pSnake = cur;
		}
		else
		{
			cur->next=ps->_pSnake;
			ps->_pSnake = cur;
		}
	}
	cur = ps->_pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	//设置蛇的属性
	ps->_dir = RIGHT;
	ps->_score = 0;
	ps->_sleep_time = 200;
	ps->_food_weight = 10;
	ps->_status = OK;
}
void CreatFood(pSnake ps)
{
	int x = 0;
	int y = 0;
again:
	do
	{
		x = rand() % 53 + 2;
		y = rand() % 25 + 1;
	} while (x % 2 != 0);
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		if (cur->x == x && cur->y == y)
		{
			goto again;
		}
		cur = cur->next;
	}
	pSnakeNode pfood=(pSnakeNode)malloc(sizeof(SnakeNode));
	if (pfood == NULL)
	{
		perror("CreatFood()::malloc()");
		return;
	}
	pfood->x = x;
	pfood->y = y;
	pfood->next = NULL;

	SetPos(x, y);
	wprintf(L"%lc", FOOD);
	ps->_pFood = pfood;
}

void GameStart(pSnake ps)
{
	//0.光标隐藏
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOutput, &CursorInfo);
	CursorInfo.bVisible = 0; 
	SetConsoleCursorInfo(hOutput, &CursorInfo);
	//1.欢迎界面 2.功能介绍
	WelcomeToGame();
	//3.绘制地图
	CreatMap();
	//4.创建蛇
	InitSnake(ps);
	//5.创建食物
	CreatFood(ps);
}
void PrintfHelpInfo()
{
	SetPos(64, 15);
	printf("不能穿墙，不能咬到⾃⼰\n");
	SetPos(64, 16);
	printf("⽤↑.↓.←.→分别控制蛇的移动.");
	SetPos(64, 17);
	printf("F3 为加速，F4 为减速\n");
	SetPos(64, 18);
	printf("ESC ：退出游戏.space：暂停游戏.");
}
#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&1)?1:0)
//游戏运行逻辑
void Pause()
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE))
		{
			break;
		}
	}
}
int NextIsFood(pSnakeNode pn, pSnake ps)
{
	return (ps->_pFood->x == pn->x && ps->_pFood->y == pn->y);
}
void EatFood(pSnakeNode pn, pSnake ps)
{
	ps->_pFood->next = ps->_pSnake;
	ps->_pSnake = ps->_pFood;
	free(pn);
	pn = NULL;
	pSnakeNode cur = ps->_pSnake;

	//打印
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	ps->_score += ps->_food_weight;
	//重新创建食物
	CreatFood(ps);
}
void NoFood(pSnakeNode pn, pSnake ps)
{
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;
	pSnakeNode cur = ps->_pSnake;
	while (cur->next->next!=NULL)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur=cur->next;
	}
	SetPos(cur->next->x, cur->next->y);
	printf("  ");
	free(cur->next);
	cur->next = NULL;
}
void KillByWall(pSnake ps)
{
	if (ps->_pSnake->x == 0 || ps->_pSnake->x == 56 || ps->_pSnake->y == 0 || ps->_pSnake->y == 26)
	{
		ps->_status = KILL_BY_WALL;
	}
}
void KillBySelf(pSnake ps)
{
	pSnakeNode cur = ps->_pSnake->next;
	while (cur)
	{
		if (cur->x == ps->_pSnake->x && cur->y == ps->_pSnake->y)
		{
			ps->_status = KILL_BY_SELF;
		}
		cur = cur->next;
	}
}
void SnakeMove(pSnake ps)
{
	pSnakeNode pNextNode=(pSnakeNode)malloc(sizeof(SnakeNode));
	if (pNextNode==NULL)
	{
		perror("SnakeMove()::malloc()");
		return;
	}

	switch (ps->_dir)
	{
	case UP:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y - 1;
		break;
	case DOWN:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y + 1;
		break;
	case LEFT:
		pNextNode->x = ps->_pSnake->x - 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	case RIGHT:
		pNextNode->x = ps->_pSnake->x + 2;
		pNextNode->y = ps->_pSnake->y;
		break;

	}
	if (NextIsFood(pNextNode, ps))
	{
		EatFood(pNextNode, ps);
	}
	else
	{
		NoFood(pNextNode, ps);
	}
	KillByWall(ps);
	KillBySelf(ps);
}

void GmaeRun(pSnake ps)
{
	//打印帮助信息;
	PrintfHelpInfo();
	do
	{
		//打印总分数和食物的分值
		SetPos(64,10);
		printf("总分数:%d", ps->_score);
		SetPos(64, 11);
		printf("当前一个食物的分数:%2d", ps->_food_weight);
		if (KEY_PRESS(VK_UP) && ps->_dir != DOWN)
		{
			ps->_dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->_dir != UP)
		{
			ps->_dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->_dir != RIGHT)
		{
			ps->_dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->_dir != LEFT)
		{
			ps->_dir = RIGHT;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			Pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			ps->_status = END_NORMAL;
		}
		else if (KEY_PRESS(VK_F3))
		{
			if (ps->_sleep_time > 80)
			{
				ps->_sleep_time -= 30;
				ps->_food_weight += 2;
			}
		}
		else if (KEY_PRESS(VK_F4))
		{
			if (ps->_food_weight >2 )
			{
				ps->_sleep_time += 30;
				ps->_food_weight -= 2;
			}
		}
		SnakeMove(ps);
		Sleep(ps->_sleep_time);
	} while (ps->_status==OK);
}
void GameEnd(pSnake ps)
{
	SetPos(24, 12);
	switch (ps->_status)
	{
	case END_NORMAL:
		printf("您主动结束游戏");
		break;
	case KILL_BY_WALL:
		printf("您撞到了墙上，游戏结束");
		break;
	case KILL_BY_SELF:
		printf("您撞到了自己，游戏结束");
		break;
	}
	SetPos(0, 29);
	//释放列表
	pSnakeNode cur = ps->_pSnake->next;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}
}
