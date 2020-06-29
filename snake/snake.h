#define DEF_SNAKE_LONG 100

char g_strGameBack[20][48] = { "■■■■■■■■■■■■■■■■■■■■■■■\n",  //两个字节 占两个字符位
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■                                          ■\n",
							   "■■■■■■■■■■■■■■■■■■■■■■■\n" };
//方向
enum { to_east = 2, to_south = 1, to_west = -2, to_nouth = -1 };
//蛇长度
int g_nSnakelen = 2;
//蛇数组
int g_arrSnake[DEF_SNAKE_LONG][3] = { 0 };
int g_nSnakeDir = to_west;
//标记
int g_IsProFood = 1;

//产生随机坐标
int g_nLine;
int g_nColumn;
//
int g_nScore = 0;
#pragma once
