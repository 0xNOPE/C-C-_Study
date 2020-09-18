#pragma once
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
#include <vector>
#include <algorithm>
class Manager:public Identity
{
public:

	//Ĭ�Ϲ��캯��
	Manager();

	//�вι���  ����Ա����������
	Manager(string name, string passwd);

	//ѡ��˵�
	virtual void Menu();

	//����˺�  
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();

	//����ظ� ����:(����id����������) ����ֵ��(true �������ظ���false����û���ظ�)
	bool checkRepeat(int id, int type);


	//ѧ������
	vector<Student> vStu;
	//��ʦ����
	vector<Teacher> vTea;
	//��������
	vector<ComputerRoom> vCom;

};