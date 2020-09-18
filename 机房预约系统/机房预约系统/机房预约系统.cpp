#include <iostream>
#include <fstream>
#include "globalFile.h"
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
using namespace std;

//管理员菜单
void managerMenu(Identity * &person);

//登录函数
void loginIn(string fileName, int type);

//一级菜单
void showMenu();

//学生菜单
void studentMenu(Identity * &person);

//教师菜单
void teacherMenu(Identity * &person);

//登录函数
void loginIn(string fileName, int type)
{
	//输入：编号，姓名，密码
	int id;
	string name;
	string passwd;

	//文件内容：编号，姓名，密码
	int fId;
	string fName;
	string fPasswd;

	//父类指针，指向子类对象
	Identity * person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//输入编号信息
	if (type == 1)
	{
		cout << "请输入您的学号：";
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工编号：";
		cin >> id;
	}
	//输入姓名信息
	cout << "请输入您的姓名：";
	cin >> name;
	//输入密码信息
	cout << "请输入您的密码：";
	cin >> passwd;

	if (type == 1)
	{
		//学生登录验证
		while (ifs >> fId && ifs >> fName && ifs >> fPasswd)
		{
			if (id == fId && name == fName && passwd == fPasswd)
			{
				//登陆成功后按任意键继续，进入学生界面
				cout << "验证学生登录成功!" << endl;
				system("pause");
				system("cls");
				//创建学生对象
				person = new Student(id, name, passwd);
				//进入学生菜单
				studentMenu(person);
				return;
			}
			
		}
		
	}
	else if (type == 2)
	{
		//教师登录验证
		while (ifs >> fId && ifs >> fName && ifs >> fPasswd)
		{
			if (id == fId && name == fName && passwd == fPasswd)
			{
				//登陆成功后按任意键继续，进入教师界面
				cout << "验证教师登录成功!" << endl;
				system("pause");
				system("cls");
				//创建教师对象
				person = new Teacher(id, name, passwd);
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员登录验证
		while (ifs >> fName && ifs >> fPasswd)
		{
			if (name == fName && passwd == fPasswd)
			{
				////登陆成功后按任意键继续，进入管理员界面
				cout << "验证管理员登录成功!" << endl;
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager(name, passwd);
				//进入管理员菜单
				managerMenu(person);
				return;
			}
		}
	}

	cout << "验证登录失败!" << endl;

	system("pause");
	system("cls");
	return;
}

//管理员菜单
void managerMenu(Identity * &person)
{
	while (true)
	{
		//管理员菜单
		person->Menu();

		Manager* manager = (Manager*)person;
		int select = 0;

		cin >> select;

		if (select == 1)  //添加账号
		{
			cout << "添加账号" << endl;
			manager->addPerson();
		}
		else if (select == 2) //查看账号
		{
			cout << "查看账号" << endl;
			manager->showPerson();
		}
		else if (select == 3) //查看机房
		{
			cout << "查看机房" << endl;
			manager->showComputer();
		}
		else if (select == 4) //清空预约
		{
			cout << "清空预约" << endl;
			manager->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//学生菜单
void studentMenu(Identity * &person)
{
	while (true)
	{
		//学生菜单
		person->Menu();

		Student* student = (Student*)person;
		int select = 0;

		cin >> select;

		if (select == 1) //申请预约
		{
			student->applyOrder();
		}
		else if (select == 2) //查看自身预约
		{
			student->showMyOrder();
		}
		else if (select == 3) //查看所有预约
		{
			student->showAllOrder();
		}
		else if (select == 4) //取消预约
		{
			student->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//教师菜单
void teacherMenu(Identity * &person)
{
	while (true)
	{
		//教师菜单
		person->Menu();

		Teacher* teacher = (Teacher*)person;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//查看所有预约
			teacher->showAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			teacher->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

void showMenu()
{
	cout << "====================  欢迎使用本机房预约系统  ===================" << endl;
	cout << endl << "请输入您的身份" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.学    生           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.老    师           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.管 理 员           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.退    出           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "输入您的选择: ";

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
		case 1:			//学生身份
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:			//老师身份
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:			//管理员身份
			loginIn(ADMIN_FILE, 3);
			break;
		case 0:			//退出
			cout << "\t\t\t   欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;

		default:
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}




	return 0;
}