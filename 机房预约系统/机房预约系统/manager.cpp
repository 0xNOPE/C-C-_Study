#include "manager.h"


//默认构造
Manager::Manager() {}

//有参构造  (管理员姓名，密码)
Manager::Manager(string name, string passwd)
{
	this->m_Name = name;
	this->m_Passwd = passwd;

	//初始化容器
	this->initVector();

	//获取机房信息
	ifstream ifs;

	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为： " << vCom.size() << endl;

	ifs.close();
}

//选择菜单
void Manager::Menu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//添加账号  
void Manager::addPerson()
{
	string fileName;
	ofstream ofs;
	int select = 0;
	string idTips;		//输入id类型提示
	string errorTips;	//重复错误提示

	int id;
	string name;
	string passwd;

	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		idTips = "请输入学号：";
		errorTips = "学号重复，该学号已被添加，请重新输入！";
	}
	else
	{
		fileName = TEACHER_FILE;
		idTips = "请输入职工编号：";
		errorTips = "职工编号重复，该职工编号已被添加，请重新输入！";
	}

	ofs.open(fileName, ios::out | ios::app);
	cout << idTips << endl;
	while (true)
	{
		cin >> id;

		bool ret = this->checkRepeat(id, 1);

		if (ret) //有重复
		{
			cout << errorTips << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名：";
	cin >> name;

	cout << "请输入密码：";
	cin >> passwd;

	ofs << id << " " << name << " " << passwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//刚添加的账号由于没有更新到容器中，不会做检测,因此每次添加过后要将容器进行初始化需要
	this->initVector();
}

//打印学生信息
void printStudent(Student & s)
{
	cout << "学号： " << s.m_StuId << " 姓名： " << s.m_Name << " 密码：" << s.m_Passwd << endl;
}

//打印教师信息
void printTeacher(Teacher & t)
{
	cout << "职工号： " << t.m_EmpId << " 姓名： " << t.m_Name << " 密码：" << t.m_Passwd << endl;
}

//查看账号
void Manager::showPerson()
{
	int select = 0;

	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有教师" << endl;

	cin >> select;

	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "所有教师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下： " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号： " << it->m_ComId << " 机房最大容量： " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector()
{
	//读取学生信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败！" << endl;
		return;
	}

	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_StuId && ifs >> s.m_Name &&  ifs >> s.m_Passwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为： " << vStu.size() << endl;
	ifs.close(); //学生初始化

	//读取老师信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败！" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Passwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师数量为：" << vTea.size() << endl;
	ifs.close();
}

//检测重复 参数:(传入id，传入类型) 返回值：(true 代表有重复，false代表没有重复)
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

