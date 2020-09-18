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

	//默认构造函数
	OrderFile();

	//更新预约信息
	void updateOrder();

	//记录的容器  key --- 记录的条数  value --- 具体记录的键值对信息
	map<int, map<string, string>> mOrder;

	//记录预约条数
	int m_Size;
};