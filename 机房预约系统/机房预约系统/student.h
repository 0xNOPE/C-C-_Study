#pragma once
#include "Identity.h"
#include "computerRoom.h"
#include <vector>
#include "orderFile.h"

class Student :public Identity
{
public:
	//默认构造函数
	Student();

	//有参构造函数
	Student(int stuId, string name, string passwd);

	//菜单界面
	virtual void Menu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//学生学号
	int m_StuId;

	//机房容器
	vector<ComputerRoom> vCom;

};