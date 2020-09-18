#include "student.h"

//Ĭ�Ϲ���
Student::Student() {}

//�вι���(ѧ�š�����������)
Student::Student(int stuId, string name, string passwd)
{
	//��ʼ��ѧ������
	this->m_StuId = stuId;
	this->m_Name = name;
	this->m_Passwd = passwd;

	//��ȡ������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

//�˵�����
void Student::Menu()
{
	cout << "��ӭ " << this->m_Name << " ͬѧ" << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;

}

//����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	
	int date = 0;
	int interval = 0;
	int room = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "�����������������룡" << endl;
	}

	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "�����������������룡" << endl;
	}

	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << vCom[0].m_MaxNum << endl;
	cout << "2�Ż���������" << vCom[1].m_MaxNum << endl;
	cout << "3�Ż���������" << vCom[2].m_MaxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_StuId<< " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
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
		if (atoi(of.mOrder[i]["stuId"].c_str()) == this->m_StuId)
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
	}

	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder()
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

//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.mOrder[i]["stuId"].c_str()) == this->m_StuId)
		{
			if (of.mOrder[i]["status"] == "1" || of.mOrder[i]["status"] == "1")
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
				else if (of.mOrder[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				
				cout << status << endl;
			}
		}
	}

	cout << "��������Ҫȡ���ļ�¼��ţ�0��ʾ���ء�" << endl;
	int select = 0;

	while (true)
	{
		if (select == 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.mOrder[v[select - 1]]["status"] = "0";
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
