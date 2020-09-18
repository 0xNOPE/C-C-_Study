#pragma once
#include "Identity.h"

class Teacher :public Identity
{
public:
	//默认构造函数
	Teacher();

	//有参构造函数(职工编号，姓名，密码)
	Teacher(int empId, string name, string Passwd);

	//菜单界面
	virtual void Menu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	int m_EmpId; //教师编号
};