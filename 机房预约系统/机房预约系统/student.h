#pragma once
#include "Identity.h"
#include "computerRoom.h"
#include <vector>
#include "orderFile.h"

class Student :public Identity
{
public:
	//Ĭ�Ϲ��캯��
	Student();

	//�вι��캯��
	Student(int stuId, string name, string passwd);

	//�˵�����
	virtual void Menu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_StuId;

	//��������
	vector<ComputerRoom> vCom;

};