#pragma once
#include<iostream>
#include<string>
#include"globalFile.h"
#include "orderFile.h"
#include <fstream>
#include <vector>
#include<cstdlib>

using namespace std;

//身份抽象类
class Identity
{
public:

	//每个身份的下级操作菜单
	virtual void Menu() = 0;

	string m_Name; //用户名
	string m_Passwd;  //密码
};