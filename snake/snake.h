#define DEF_SNAKE_LONG 100

char g_strGameBack[20][48] = { "����������������������������������������������\n",  //�����ֽ� ռ�����ַ�λ
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "��                                          ��\n",
							   "����������������������������������������������\n" };
//����
enum { to_east = 2, to_south = 1, to_west = -2, to_nouth = -1 };
//�߳���
int g_nSnakelen = 2;
//������
int g_arrSnake[DEF_SNAKE_LONG][3] = { 0 };
int g_nSnakeDir = to_west;
//���
int g_IsProFood = 1;

//�����������
int g_nLine;
int g_nColumn;
//
int g_nScore = 0;
#pragma once
