#pragma once
#include "includes.h"

class Maze {
public:
	//��maze.txt�ļ����ж�ȡ����
	vector<string> initMaze(string fileName);
	//���ڲ��Կո�Ϊ·���������Թ����ַ�֮����ڿո������Թ��������ļ����еĿո�
	void trimSpace(string& s);
	//�����Կո�Ϊ·���������Թ����У����ļ����еĿո��滻ΪH
	void replaceSpace(string& iniString);
	//��������㷨
	void BFS(Pos& start);
	//���·�����ַ���
	void printPathStr(Pos& end);
	//�����Թ��������ķ��ţ�����ڳ�������
	void inputMazeSymbols();
	//����Թ�
	void showMaze(vector<string>& maze);
	//��ʾ�Թ���Ϣ��������������·���ȵȣ�
	void showResult();

private:
	Pos m_pos;
	string m_mazefilename;
	char m_pathstr;
	char m_direction[4];
	Pos m_start, m_end;	//�Թ���ʼ����ͽ�������
	int m_rows, m_cols;	// �Թ�����������

};
