#pragma once
#include <vector>
#include <map>
#include <deque>
#include "speaker.h"
#include <algorithm>
#include <numeric>
#include <functional>
#include <fstream>
#include <ctime>


//设计演讲管理类
class SpeechManager
{
public:

	//构造函数
	SpeechManager();

	//析构函数
	~SpeechManager();

	//显示菜单界面
	void ShowMenu();

	//退出系统
	void ExitSystem();

	//初始化容器属性
	void InitSpeech();

	//创建选手
	void CreateSpeaker();

	//开始比赛
	void StartSpeech();

	//抽签
	void SpeechDraw();

	//比赛
	void SpeechContest();

	//显示得分信息
	void ShowScore();

	//保存分数
	void SaveScore();

	//获取记录
	void LoadRecord();

	//查看记录
	void ShowRecord();

	//清空记录
	void ClearRecord();

	//成员属性
	//保存第一轮选手编号容器
	vector<int> v1;

	//第一轮晋级选手编号容器
	vector<int> v2;

	//前三名选手编号容器
	vector<int> v3;

	//存放编号以及对应选手的容器
	map<int, Speaker>m_Speaker;

	//轮数
	int m_Index;

	//文件为空的标志
	bool fileIsEmpty;

	//往届记录
	map<int, vector<string>> m_Record;
};
