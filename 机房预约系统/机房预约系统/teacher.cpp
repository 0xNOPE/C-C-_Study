#include "teacher.h"
#include "student.h"
//默认构造函数
Teacher::Teacher() {}

//有参构造函数(职工编号，姓名，密码)
Teacher::Teacher(int empId, string name, string Passwd)
{
	//初始化属性
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Passwd = Passwd;
}


void Teacher::Menu()
{
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//查看所有预约
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "预约日期： 周" << of.mOrder[i]["date"];
		cout << "  时段：" << (of.mOrder[i]["interval"] == "1" ? "上午" : "下午");
		cout << "  机房：" << of.mOrder[i]["roomId"];
		string status = "  状态：";	//0 取消的预约   1 审核中   2 已预约  -1 预约失败
		if (of.mOrder[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.mOrder[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.mOrder[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//审核预约
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下：" << endl;

	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
			if (of.mOrder[i]["status"] == "1")
			{
				v.push_back(i);
				cout << index++ << "、" << endl;

				cout << "预约日期： 周" << of.mOrder[i]["date"];
				cout << "  时段：" << (of.mOrder[i]["interval"] == "1" ? "上午" : "下午");
				cout << "  机房：" << of.mOrder[i]["roomId"];
				string status = "  状态：";	//0 取消的预约   1 审核中   2 已预约  -1 预约失败
				if (of.mOrder[i]["status"] == "1")
				{
					status += "审核中";
				}

				cout << status << endl;
			}
	}

	cout << "请输入审核的预约记录,0代表返回。" << endl;
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
				cout << "请输入审核结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
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
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");
}