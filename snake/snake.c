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


//��ʾ��ҳ
int FirstPage();
//��������
void StartMusic();
//ֹͣ����
void StopMusic();
//���ո�
void TestSpace();
//����
void DrawSnake();
//������
void DrawBackground();
//Ϊ�߲���һ�������λ��
void SetSnakeRandPos();
//������
void DestroySnake();
//�߶�����
void SnakeMove();
//���淽������
void ChangeDir();
//�������ж�
bool IsSnakeDie();
//�����µ�ʳ��
void ProduceFood();
//�߱䳤
void SnakeGrowUp();
//�Ƿ�
void Score();

//������
int main(void)
{
	//��������
	StartMusic();
	//��ʾ��ҳ
	FirstPage();
	//���ո�
	TestSpace();
	//ֹͣ����
	StopMusic();
	//��տ���̨
	system("cls");
	//Ϊ�߲������λ��
	SetSnakeRandPos();
	//������
	DrawBackground();

	//������Ϸ����
	while (1)
	{
		system("cls");
		//����ʳ��
		ProduceFood();
		//�߱䳤
		SnakeGrowUp();
		//�ı䷽��
		ChangeDir();
		//�ж�����
		if (false == IsSnakeDie())
		{
			printf("\n\n\n\n\n\n\n\n\n");
			printf("\t\t\t\t\tsnake die!!!\n\n\n\n\n\n\n\n\n\n\n\n\n");
			break;
		}
		//�߶�
		SnakeMove();
		//��ʾ����
		DrawBackground();
		//�Ƿ�
		Score();
		Sleep(150);
	}

	system("pause");
	return 0;
}

//��ʾ��ҳ
int FirstPage()
{
	printf("\n\n\n\n\n");
	printf("\t\t\t     welcome to my game_world!\n\n");
	printf("\t\t\t       now,it is your time!!\n\n");
	printf("\t\t\tw a s d �����߷��򣬰��ո�ʼ��Ϸ\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
//��������
void StartMusic()
{
	PlaySound(L"snakebgm.wav", NULL, SND_FILENAME | SND_ASYNC);
}
//ֹͣ����
void StopMusic()
{
	PlaySound(NULL, 0, 0);
}
//���ո�
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
//����
void DrawSnake()
{
	int i = 0;
	for (i = 0; g_arrSnake[i][0] != 0; i++)
	{
		strncpy(&g_strGameBack[g_arrSnake[i][0]][g_arrSnake[i][1]], "��", 2);
	}
}
//������
void DrawBackground()
{

	int i = 0;
	for (i = 0; i < 20; i++)
	{
		printf(g_strGameBack[i]);
	}
}
//Ϊ�߲���һ�������λ��
void SetSnakeRandPos()
{
	int nX = 0;
	int nY = 0;

	//���������
	srand((unsigned int)time(NULL));//������
	nX = rand() % 19 + 1;
	nY = rand() % 18 + 1;

	//��ʼ��
	g_arrSnake[0][0] = nY;	//��
	g_arrSnake[0][1] = nX * 2;//��
	g_arrSnake[0][2] = to_west;

	g_arrSnake[1][0] = nY;	//��
	g_arrSnake[1][1] = nX * 2 + 2;//��
	g_arrSnake[1][2] = to_west;

	g_arrSnake[2][0] = nY;	//��
	g_arrSnake[2][1] = nX * 2 + 4;//��
	g_arrSnake[2][2] = to_west;

	//���ߵ�����
	DrawSnake();
}
//������
void DestroySnake()
{
	int i = 0;
	for (i = 0; g_arrSnake[i][0] != 0; i++)
	{
		strncpy(&g_strGameBack[g_arrSnake[i][0]][g_arrSnake[i][1]], "  ", 2);
	}
}
//�߶�����
void SnakeMove()
{
	int i = DEF_SNAKE_LONG - 1;

	//������
	DestroySnake();

	for (i; i >= 1; i--)
	{
		//���˵��Ƿ�����
		if (0 == g_arrSnake[i][0])
		{
			continue;
		}
		//��ǰһ���ڵ��ֵ��ֵ����ǰ�ڵ�
		g_arrSnake[i][0] = g_arrSnake[i - 1][0];
		g_arrSnake[i][1] = g_arrSnake[i - 1][1];
		g_arrSnake[i][2] = g_arrSnake[i - 1][2];
	}
	//������ͷ
	g_arrSnake[0][2] = g_nSnakeDir;

	if (to_west == g_arrSnake[0][2] || to_east == g_arrSnake[0][2])
	{
		g_arrSnake[0][1] += g_arrSnake[0][2];
	}
	else
	{
		g_arrSnake[0][0] += g_arrSnake[0][2];
	}

	//����
	DrawSnake();
}
//�������ж�
bool IsSnakeDie()
{
	if (to_west == g_arrSnake[0][2] || to_east == g_arrSnake[0][2] )
	{
		//��ͷ����һ�����Ƿ��� ��������
		if (0 == strncmp(&g_strGameBack[g_arrSnake[0][0]][g_arrSnake[0][1] + g_arrSnake[0][2]], "��", 2))
		{
			return false;
		}
	}
	else
	{
		if (0 == strncmp(&g_strGameBack[g_arrSnake[0][0] + g_arrSnake[0][2]][g_arrSnake[0][1]], "��", 2))
		{
			return false;
		}
	}

	return true;
}
//���淽������
void ChangeDir()
{
	//�첽��ⷽ���
	//short �����ֽ� ���ֽ� ���ֽ�	
	//Wһֱ���Ÿ��ֽ�װһ��������
	//W��һ�£����ֽڷ���һ��1
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
//�����µ�ʳ��
void ProduceFood()
{
	
	int i = 0;
	srand((unsigned int)time(NULL));
	//�ж��Ƿ�����µ�ʳ��
	if (0 == g_IsProFood)//��
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
	//��ʳ��
	strncpy(&g_strGameBack[g_nLine][g_nColumn * 2], "��", 2);

	g_IsProFood = 0;
}
//�߱䳤
void SnakeGrowUp()
{
	//��ͷ�����ʳ���������
	if (g_nLine == g_arrSnake[0][0] && g_nColumn*2 == g_arrSnake[0][1])
	{
		//�߳���
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
//�Ƿ�
void Score()
{
	COORD rd;
	rd.X = 56;
	rd.Y = 9;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), rd);
	printf("������%d",g_nScore);
}