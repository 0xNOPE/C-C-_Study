#include <iostream>
#include <fstream>
#include "globalFile.h"
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
using namespace std;

//����Ա�˵�
void managerMenu(Identity * &person);

//��¼����
void loginIn(string fileName, int type);

//һ���˵�
void showMenu();

//ѧ���˵�
void studentMenu(Identity * &person);

//��ʦ�˵�
void teacherMenu(Identity * &person);

//��¼����
void loginIn(string fileName, int type)
{
	//���룺��ţ�����������
	int id;
	string name;
	string passwd;

	//�ļ����ݣ���ţ�����������
	int fId;
	string fName;
	string fPasswd;

	//����ָ�룬ָ���������
	Identity * person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//��������Ϣ
	if (type == 1)
	{
		cout << "����������ѧ�ţ�";
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ����ţ�";
		cin >> id;
	}
	//����������Ϣ
	cout << "����������������";
	cin >> name;
	//����������Ϣ
	cout << "�������������룺";
	cin >> passwd;

	if (type == 1)
	{
		//ѧ����¼��֤
		while (ifs >> fId && ifs >> fName && ifs >> fPasswd)
		{
			if (id == fId && name == fName && passwd == fPasswd)
			{
				//��½�ɹ������������������ѧ������
				cout << "��֤ѧ����¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				//����ѧ������
				person = new Student(id, name, passwd);
				//����ѧ���˵�
				studentMenu(person);
				return;
			}
			
		}
		
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		while (ifs >> fId && ifs >> fName && ifs >> fPasswd)
		{
			if (id == fId && name == fName && passwd == fPasswd)
			{
				//��½�ɹ�������������������ʦ����
				cout << "��֤��ʦ��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				//������ʦ����
				person = new Teacher(id, name, passwd);
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա��¼��֤
		while (ifs >> fName && ifs >> fPasswd)
		{
			if (name == fName && passwd == fPasswd)
			{
				////��½�ɹ���������������������Ա����
				cout << "��֤����Ա��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				//��������Ա����
				person = new Manager(name, passwd);
				//�������Ա�˵�
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
	return;
}

//����Ա�˵�
void managerMenu(Identity * &person)
{
	while (true)
	{
		//����Ա�˵�
		person->Menu();

		Manager* manager = (Manager*)person;
		int select = 0;

		cin >> select;

		if (select == 1)  //����˺�
		{
			cout << "����˺�" << endl;
			manager->addPerson();
		}
		else if (select == 2) //�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			manager->showPerson();
		}
		else if (select == 3) //�鿴����
		{
			cout << "�鿴����" << endl;
			manager->showComputer();
		}
		else if (select == 4) //���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			manager->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//ѧ���˵�
void studentMenu(Identity * &person)
{
	while (true)
	{
		//ѧ���˵�
		person->Menu();

		Student* student = (Student*)person;
		int select = 0;

		cin >> select;

		if (select == 1) //����ԤԼ
		{
			student->applyOrder();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			student->showMyOrder();
		}
		else if (select == 3) //�鿴����ԤԼ
		{
			student->showAllOrder();
		}
		else if (select == 4) //ȡ��ԤԼ
		{
			student->cancelOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//��ʦ�˵�
void teacherMenu(Identity * &person)
{
	while (true)
	{
		//��ʦ�˵�
		person->Menu();

		Teacher* teacher = (Teacher*)person;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//�鿴����ԤԼ
			teacher->showAllOrder();
		}
		else if (select == 2)
		{
			//���ԤԼ
			teacher->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

void showMenu()
{
	cout << "====================  ��ӭʹ�ñ�����ԤԼϵͳ  ===================" << endl;
	cout << endl << "�������������" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.ѧ    ��           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.��    ʦ           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.�� �� Ա           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.��    ��           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "��������ѡ��: ";

}


int main()
{
	int select = 0;
	
	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:			//ѧ�����
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:			//��ʦ���
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:			//����Ա���
			loginIn(ADMIN_FILE, 3);
			break;
		case 0:			//�˳�
			cout << "\t\t\t   ��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;

		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}




	return 0;
}