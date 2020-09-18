#include "manager.h"


//Ĭ�Ϲ���
Manager::Manager() {}

//�вι���  (����Ա����������)
Manager::Manager(string name, string passwd)
{
	this->m_Name = name;
	this->m_Passwd = passwd;

	//��ʼ������
	this->initVector();

	//��ȡ������Ϣ
	ifstream ifs;

	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ�� " << vCom.size() << endl;

	ifs.close();
}

//ѡ��˵�
void Manager::Menu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����˺�  
void Manager::addPerson()
{
	string fileName;
	ofstream ofs;
	int select = 0;
	string idTips;		//����id������ʾ
	string errorTips;	//�ظ�������ʾ

	int id;
	string name;
	string passwd;

	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		idTips = "������ѧ�ţ�";
		errorTips = "ѧ���ظ�����ѧ���ѱ���ӣ����������룡";
	}
	else
	{
		fileName = TEACHER_FILE;
		idTips = "������ְ����ţ�";
		errorTips = "ְ������ظ�����ְ������ѱ���ӣ����������룡";
	}

	ofs.open(fileName, ios::out | ios::app);
	cout << idTips << endl;
	while (true)
	{
		cin >> id;

		bool ret = this->checkRepeat(id, 1);

		if (ret) //���ظ�
		{
			cout << errorTips << endl;
		}
		else
		{
			break;
		}
	}

	cout << "������������";
	cin >> name;

	cout << "���������룺";
	cin >> passwd;

	ofs << id << " " << name << " " << passwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//����ӵ��˺�����û�и��µ������У����������,���ÿ����ӹ���Ҫ���������г�ʼ����Ҫ
	this->initVector();
}

//��ӡѧ����Ϣ
void printStudent(Student & s)
{
	cout << "ѧ�ţ� " << s.m_StuId << " ������ " << s.m_Name << " ���룺" << s.m_Passwd << endl;
}

//��ӡ��ʦ��Ϣ
void printTeacher(Teacher & t)
{
	cout << "ְ���ţ� " << t.m_EmpId << " ������ " << t.m_Name << " ���룺" << t.m_Passwd << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	int select = 0;

	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴���н�ʦ" << endl;

	cin >> select;

	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "���н�ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£� " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ� " << it->m_ComId << " ������������� " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector()
{
	//��ȡѧ����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}

	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_StuId && ifs >> s.m_Name &&  ifs >> s.m_Passwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ�� " << vStu.size() << endl;
	ifs.close(); //ѧ����ʼ��

	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Passwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();
}

//����ظ� ����:(����id����������) ����ֵ��(true �������ظ���false����û���ظ�)
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_StuId)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}

