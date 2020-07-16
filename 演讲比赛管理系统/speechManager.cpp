#include "speechManager.h"


//构造函数
SpeechManager::SpeechManager()
{
	//初始化容器属性
	this->InitSpeech();

	//创建选手
	this->CreateSpeaker();

	//获取往届记录
	this->LoadRecord();
}

//析构函数
SpeechManager::~SpeechManager() {}

//显示菜单界面
void SpeechManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//退出系统
void SpeechManager::ExitSystem()
{
	cout << "欢迎下次使用！！！" << endl;
	system("pause");
	exit(0);
}

//初始化容器属性
void SpeechManager::InitSpeech()
{
	//容器置空
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();
	//初始化比赛轮数
	m_Index = 1;
	//初始化记录容器
	this->m_Record.clear();
}

//创建选手
void SpeechManager::CreateSpeaker()
{
	string s_nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < s_nameSeed.size(); ++i)
	{
		string name = "选手";
		name += s_nameSeed[i];
		int num;				//选手编号
		Speaker spk;

		spk.m_Name = name;
		for (int i = 1; i < 2; i++)
		{
			spk.m_Score[i] = 0;
		}
		//12名选手编号
		num = 1000 + i;
		this->v1.push_back(num);

		//12名选手放入map容器
		this->m_Speaker.insert(make_pair(num, spk));
	}
	
}

//开始比赛
void SpeechManager::StartSpeech()
{
	//第一轮比赛
	//抽签
	this->SpeechDraw();

	//比赛
	this->SpeechContest();

	//结果
	this->ShowScore();

	//第二轮比赛
	this->m_Index++;

	//抽签
	this->SpeechDraw();

	//比赛
	this->SpeechContest();

	//结果
	this->ShowScore();
	
	//保存分数
	SaveScore();

	//重置比赛
	//初始化属性
	this->InitSpeech();
	//创建选手
	this->CreateSpeaker();
	//获取往届记录
	this->LoadRecord();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");


}

//抽签
void SpeechManager::SpeechDraw()
{
	system("cls");
	cout << "第 " << this->m_Index << " 轮选手正在抽签。。。" << endl;
	cout << "--------------------------" << endl;
	cout << "抽签结果如下：" << endl;
	if (1 == m_Index)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator iter = v2.begin(); iter != v2.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
	system("pause");

}

//比赛
void SpeechManager::SpeechContest()
{
	system("cls");
	cout << "----------- 第" << this->m_Index << " 轮比赛正式开始 --------------" << endl;

	//准备临时容器 存放小组成绩
	multimap<double, int, greater<double>> groupScore;

	int num = 0; //记录人员个数 6人一组

	vector<int>v_Tmp;//比赛选手容器
	if (this->m_Index == 1)
	{
		v_Tmp = v1;
	}
	else
	{
		v_Tmp = v2;
	}

	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Tmp.begin(); it != v_Tmp.end(); it++)
	{
		num++;
		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;   // 600 ~ 1000
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>());//排序
		d.pop_front(); //去除最高分
		d.pop_back(); //去除最低分

		double sum = accumulate(d.begin(), d.end(), 0.0f); //总分
		double avg = sum / (double)d.size();  //平均分

		//打印平均分
		//cout << "编号： " << *it << " 姓名： " << this->m_Speaker[*it].m_Name << " 获取平均分： " << avg << endl;

		//将平均分放入到 map容器里
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//将打分数据 放入到临时小组容器中
		groupScore.insert(make_pair(avg, *it)); //key是得分，value是具体选手编号
		//每6人取出前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次： " << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号： " << it->second << " 姓名： " << this->m_Speaker[it->second].m_Name << " 成绩： "
					<< this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}

			//取走前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					v3.push_back((*it).second);
				}
			}

			groupScore.clear(); //小组容器清空
			cout << endl;

		}
	}

	cout << "------------------ 第" << this->m_Index << "轮比赛完毕 --------------" << endl;
	system("pause");

}

//显示得分信息
void SpeechManager::ShowScore()
{
	cout << "------------------ 第" << this->m_Index << "轮晋级选手信息如下： -------------------" << endl;

	vector<int>v_Tmp;
	if (this->m_Index == 1)
	{
		v_Tmp = v2;
	}
	else
	{
		v_Tmp = v3;
	}

	for (vector<int>::iterator it = v_Tmp.begin(); it != v_Tmp.end(); it++)
	{
		cout << "选手编号：" << *it << " 姓名：" << this->m_Speaker[*it].m_Name << 
				" 得分：" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
}

//保存分数
void SpeechManager::SaveScore()
{
	ofstream ofs;

	ofs.open("speech.csv", ios::out | ios::app);	//追加的方式写文件

	//写入数据
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//关闭文件
	ofs.close();

	cout << "文件已保存！" << endl;
	this->fileIsEmpty = false;

}

//加载往届成绩记录
void SpeechManager::LoadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	//文件不存在
	if ( !ifs.is_open())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileIsEmpty = false;

	ifs.putback(ch);	//将上面的读取的单个字符放回来
	string data;
	int index = 0;

	while (ifs >> data)
	{
		//测试
		//cout << data << endl;
		vector<string>v;
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);

			if (pos == -1)	break;

			string tmp = data.substr(start, pos - start);
			v.push_back(tmp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));

		index++;
	}
	ifs.close();
}

//清空记录
void SpeechManager::ShowRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在或者为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届 " <<
				"冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
				"亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
				"季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

void SpeechManager::ClearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//初始化属性
		this->InitSpeech();

		//创建选手
		this->CreateSpeaker();

		//获取往届记录
		this->LoadRecord();


		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}