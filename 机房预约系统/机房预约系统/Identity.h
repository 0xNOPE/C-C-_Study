#pragma once
#include<iostream>
#include<string>
#include"globalFile.h"
#include "orderFile.h"
#include <fstream>
#include <vector>
#include<cstdlib>

using namespace std;

//��ݳ�����
class Identity
{
public:

	//ÿ����ݵ��¼������˵�
	virtual void Menu() = 0;

	string m_Name; //�û���
	string m_Passwd;  //����
};