#pragma once
#include "Identity.h"

class Teacher :public Identity
{
public:
	//Ĭ�Ϲ��캯��
	Teacher();

	//�вι��캯��(ְ����ţ�����������)
	Teacher(int empId, string name, string Passwd);

	//�˵�����
	virtual void Menu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	int m_EmpId; //��ʦ���
};