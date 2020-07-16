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


//����ݽ�������
class SpeechManager
{
public:

	//���캯��
	SpeechManager();

	//��������
	~SpeechManager();

	//��ʾ�˵�����
	void ShowMenu();

	//�˳�ϵͳ
	void ExitSystem();

	//��ʼ����������
	void InitSpeech();

	//����ѡ��
	void CreateSpeaker();

	//��ʼ����
	void StartSpeech();

	//��ǩ
	void SpeechDraw();

	//����
	void SpeechContest();

	//��ʾ�÷���Ϣ
	void ShowScore();

	//�������
	void SaveScore();

	//��ȡ��¼
	void LoadRecord();

	//�鿴��¼
	void ShowRecord();

	//��ռ�¼
	void ClearRecord();

	//��Ա����
	//�����һ��ѡ�ֱ������
	vector<int> v1;

	//��һ�ֽ���ѡ�ֱ������
	vector<int> v2;

	//ǰ����ѡ�ֱ������
	vector<int> v3;

	//��ű���Լ���Ӧѡ�ֵ�����
	map<int, Speaker>m_Speaker;

	//����
	int m_Index;

	//�ļ�Ϊ�յı�־
	bool fileIsEmpty;

	//�����¼
	map<int, vector<string>> m_Record;
};
