#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "globalFile.h"
#include <map>
#include <algorithm>

using namespace std;

class OrderFile
{
public:

	//Ĭ�Ϲ��캯��
	OrderFile();

	//����ԤԼ��Ϣ
	void updateOrder();

	//��¼������  key --- ��¼������  value --- �����¼�ļ�ֵ����Ϣ
	map<int, map<string, string>> mOrder;

	//��¼ԤԼ����
	int m_Size;
};