#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include<time.h>
#include"snake.h"
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

typedef int bool;
#define true 1
#define false 0


//显示首页
int FirstPage();
//播放音乐
void StartMusic();
//停止音乐
void StopMusic();
//检测空格
void TestSpace();
//画蛇
void DrawSnake();
//画背景
void DrawBackground();
//为蛇产生一个随机的位置
void SetSnakeRandPos();
//销毁蛇
void DestroySnake();
//蛇动起来
void SnakeMove();
//蛇随方向动起来
void ChangeDir();
//蛇死亡判断
bool IsSnakeDie();
//产生新的食物
void ProduceFood();
//蛇变长
void SnakeGrowUp();
//记分
void Score();

//主函数
int main(void)
{
	//播放音乐
	StartMusic();
	//显示首页
	FirstPage();
	//检测空格
	TestSpace();
	//停止音乐
	StopMusic();
	//清空控制台
	system("cls");
	//为蛇产生随机位置
	SetSnakeRandPos();
	//画背景
	DrawBackground();

	//进入游戏界面
	while (1)
	{
		system("cls");
		//产生食物
		ProduceFood();
		//蛇变长
		SnakeGrowUp();
		//改变方向
		ChangeDir();
		//判断死亡
		if (false == IsSnakeDie())
		{
			printf("\n\n\n\n\n\n\n\n\n");
			printf("\t\t\t\t\tsnake die!!!\n\n\n\n\n\n\n\n\n\n\n\n\n");
			break;
		}
		//蛇动
		SnakeMove();
		//显示背景
		DrawBackground();
		//记分
		Score();
		Sleep(150);
	}

	system("pause");
	return 0;
}

//显示首页
int FirstPage()
{
	printf("\n\n\n\n\n");
	printf("\t\t\t     welcome to my game_world!\n\n");
	printf("\t\t\t       now,it is your time!!\n\n");
	printf("\t\t\tw a s d 控制蛇方向，按空格开始游戏\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
//播放音乐
void StartMusic()
{
	PlaySound(L"snakebgm.wav", NULL, SND_FILENAME | SND_ASYNC);
}
//停止音乐
void StopMusic()
{
	PlaySound(NULL, 0, 0);
}
//检测空格
void TestSpace()
{
	char chInput;
	while (1)
	{
		chInput = _getch();
		if ((' ') == chInput)
		{
			break;
		}
	}
}
//画蛇
void DrawSnake()
{
	int i = 0;
	for (i = 0; g_arrSnake[i][0] != 0; i++)
	{
		strncpy(&g_strGameBack[g_arrSnake[i][0]][g_arrSnake[i][1]], "■", 2);
	}
}
//画背景
void DrawBackground()
{

	int i = 0;
	for (i = 0; i < 20; i++)
	{
		printf(g_strGameBack[i]);
	}
}
//为蛇产生一个随机的位置
void SetSnakeRandPos()
{
	int nX = 0;
	int nY = 0;

	//产生随机数
	srand((unsigned int)time(NULL));//种种子
	nX = rand() % 19 + 1;
	nY = rand() % 18 + 1;

	//初始化
	g_arrSnake[0][0] = nY;	//行
	g_arrSnake[0][1] = nX * 2;//列
	g_arrSnake[0][2] = to_west;

	g_arrSnake[1][0] = nY;	//行
	g_arrSnake[1][1] = nX * 2 + 2;//列
	g_arrSnake[1][2] = to_west;

	g_arrSnake[2][0] = nY;	//行
	g_arrSnake[2][1] = nX * 2 + 4;//列
	g_arrSnake[2][2] = to_west;

	//画蛇到背景
	DrawSnake();
}
//销毁蛇
void DestroySnake()
{
	int i = 0;
	for (i = 0; g_arrSnake[i][0] != 0; i++)
	{
		strncpy(&g_strGameBack[g_arrSnake[i][0]][g_arrSnake[i][1]], "  ", 2);
	}
}
//蛇动起来
void SnakeMove()
{
	int i = DEF_SNAKE_LONG - 1;

	//销毁蛇
	DestroySnake();

	for (i; i >= 1; i--)
	{
		//过滤掉非法蛇身
		if (0 == g_arrSnake[i][0])
		{
			continue;
		}
		//把前一个节点的值赋值给当前节点
		g_arrSnake[i][0] = g_arrSnake[i - 1][0];
		g_arrSnake[i][1] = g_arrSnake[i - 1][1];
		g_arrSnake[i][2] = g_arrSnake[i - 1][2];
	}
	//处理蛇头
	g_arrSnake[0][2] = g_nSnakeDir;

	if (to_west == g_arrSnake[0][2] || to_east == g_arrSnake[0][2])
	{
		g_arrSnake[0][1] += g_arrSnake[0][2];
	}
	else
	{
		g_arrSnake[0][0] += g_arrSnake[0][2];
	}

	//画蛇
	DrawSnake();
}
//蛇死亡判断
bool IsSnakeDie()
{
	if (to_west == g_arrSnake[0][2] || to_east == g_arrSnake[0][2] )
	{
		//蛇头的下一个，是方块 就是死亡
		if (0 == strncmp(&g_strGameBack[g_arrSnake[0][0]][g_arrSnake[0][1] + g_arrSnake[0][2]], "■", 2))
		{
			return false;
		}
	}
	else
	{
		if (0 == strncmp(&g_strGameBack[g_arrSnake[0][0] + g_arrSnake[0][2]][g_arrSnake[0][1]], "■", 2))
		{
			return false;
		}
	}

	return true;
}
//蛇随方向动起来
void ChangeDir()
{
	//异步检测方向键
	//short 两个字节 高字节 低字节	
	//W一直按着高字节装一个非零数
	//W按一下，低字节返回一个1
	if (GetAsyncKeyState('W'))
	{
		if (to_south != g_arrSnake[0][2])
		{
			g_nSnakeDir = to_nouth;
		}
	}
	else if (GetAsyncKeyState('A'))
	{
		if (to_east != g_arrSnake[0][2])
		{
			g_nSnakeDir = to_west;
		}
	}
	else if (GetAsyncKeyState('S'))
	{
		if (to_nouth != g_arrSnake[0][2])
		{
			g_nSnakeDir = to_south;
		}
	}
	else if (GetAsyncKeyState('D'))
	{
		if (to_west != g_arrSnake[0][2])
		{
			g_nSnakeDir = to_east;
		}
	}

}
//产生新的食物
void ProduceFood()
{
	
	int i = 0;
	srand((unsigned int)time(NULL));
	//判断是否产生新的食物
	if (0 == g_IsProFood)//否
	{
		return;
	}

	while (1)
	{
		bool Flag = true;
		g_nLine = rand() % 16 + 2;
		g_nColumn = rand() % 18 + 2;
		for (i = 0; g_arrSnake[i][0] != 0; i++)
		{
			if (g_nLine == g_arrSnake[i][0] && g_nColumn == g_arrSnake[i][1])
			{
				Flag = false;
				break;
			}
		}

		if (true == Flag)
		{
			break;
		}
	}
	//画食物
	strncpy(&g_strGameBack[g_nLine][g_nColumn * 2], "★", 2);

	g_IsProFood = 0;
}
//蛇变长
void SnakeGrowUp()
{
	//蛇头坐标和食物坐标相等
	if (g_nLine == g_arrSnake[0][0] && g_nColumn*2 == g_arrSnake[0][1])
	{
		//蛇长大
		if (to_east == g_arrSnake[g_nSnakelen][2])
		{
			g_arrSnake[g_nSnakelen + 1][0] = g_arrSnake[g_nSnakelen][0];
			g_arrSnake[g_nSnakelen + 1][1] = g_arrSnake[g_nSnakelen][0] - 2;
			g_arrSnake[g_nSnakelen + 1][2] = g_arrSnake[g_nSnakelen][0];
		}
		else if (to_west == g_arrSnake[g_nSnakelen][2])
		{
			g_arrSnake[g_nSnakelen + 1][0] = g_arrSnake[g_nSnakelen][0];
			g_arrSnake[g_nSnakelen + 1][1] = g_arrSnake[g_nSnakelen][0] + 2;
			g_arrSnake[g_nSnakelen + 1][2] = g_arrSnake[g_nSnakelen][0];
		}
		else if (to_nouth == g_arrSnake[g_nSnakelen][2])
		{
			g_arrSnake[g_nSnakelen + 1][0] = g_arrSnake[g_nSnakelen][0];
			g_arrSnake[g_nSnakelen + 1][1] = g_arrSnake[g_nSnakelen][0] + 1;
			g_arrSnake[g_nSnakelen + 1][2] = g_arrSnake[g_nSnakelen][0];
		}
		else if (to_south == g_arrSnake[g_nSnakelen][2])
		{
			g_arrSnake[g_nSnakelen + 1][0] = g_arrSnake[g_nSnakelen][0];
			g_arrSnake[g_nSnakelen + 1][1] = g_arrSnake[g_nSnakelen][0] - 1;
			g_arrSnake[g_nSnakelen + 1][2] = g_arrSnake[g_nSnakelen][0];
		}
		g_nSnakelen++;
		g_IsProFood = 1;
		g_nScore++;
	}
}
//记分
void Score()
{
	COORD rd;
	rd.X = 56;
	rd.Y = 9;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), rd);
	printf("分数：%d",g_nScore);
}