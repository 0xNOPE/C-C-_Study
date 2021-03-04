#pragma once
#include "includes.h"

class Maze {
public:
	//从maze.txt文件当中读取数据
	vector<string> initMaze(string fileName);
	//（在不以空格为路径的那种迷宫但字符之间存在空格那种迷宫）过滤文件当中的空格
	void trimSpace(string& s);
	//（在以空格为路径的那种迷宫当中）将文件当中的空格替换为H
	void replaceSpace(string& iniString);
	//深度优先算法
	void BFS(Pos& start);
	//输出路径的字符串
	void printPathStr(Pos& end);
	//输入迷宫相关意义的符号，及入口出口坐标
	void inputMazeSymbols();
	//输出迷宫
	void showMaze(vector<string>& maze);
	//显示迷宫信息（行数、列数、路径等等）
	void showResult();

private:
	Pos m_pos;
	string m_mazefilename;
	char m_pathstr;
	char m_direction[4];
	Pos m_start, m_end;	//迷宫开始坐标和结束坐标
	int m_rows, m_cols;	// 迷宫行数、列数

};
