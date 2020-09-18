#include "teacher.h"
#include "student.h"
//Ĭ�Ϲ��캯��
Teacher::Teacher() {}

//�вι��캯��(ְ����ţ�����������)
Teacher::Teacher(int empId, string name, string Passwd)
{
	//��ʼ������
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Passwd = Passwd;
}


void Teacher::Menu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "ԤԼ���ڣ� ��" << of.mOrder[i]["date"];
		cout << "  ʱ�Σ�" << (of.mOrder[i]["interval"] == "1" ? "����" : "����");
		cout << "  ������" << of.mOrder[i]["roomId"];
		string status = "  ״̬��";	//0 ȡ����ԤԼ   1 �����   2 ��ԤԼ  -1 ԤԼʧ��
		if (of.mOrder[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.mOrder[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.mOrder[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;

	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
			if (of.mOrder[i]["status"] == "1")
			{
				v.push_back(i);
				cout << index++ << "��" << endl;

				cout << "ԤԼ���ڣ� ��" << of.mOrder[i]["date"];
				cout << "  ʱ�Σ�" << (of.mOrder[i]["interval"] == "1" ? "����" : "����");
				cout << "  ������" << of.mOrder[i]["roomId"];
				string status = "  ״̬��";	//0 ȡ����ԤԼ   1 �����   2 ��ԤԼ  -1 ԤԼʧ��
				if (of.mOrder[i]["status"] == "1")
				{
					status += "�����";
				}

				cout << status << endl;
			}
	}

	cout << "��������˵�ԤԼ��¼,0�����ء�" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.mOrder[v[select - 1]]["status"] == "2";
				}
				else
				{
					of.mOrder[v[select - 1]]["status"] == "-1";
				}

				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
}