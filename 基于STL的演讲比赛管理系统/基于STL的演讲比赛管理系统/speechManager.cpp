#include "speechManager.h"


//���캯��
SpeechManager::SpeechManager()
{
	//��ʼ����������
	this->InitSpeech();

	//����ѡ��
	this->CreateSpeaker();

	//��ȡ�����¼
	this->LoadRecord();
}

//��������
SpeechManager::~SpeechManager() {}

//��ʾ�˵�����
void SpeechManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void SpeechManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ�ã�����" << endl;
	system("pause");
	exit(0);
}

//��ʼ����������
void SpeechManager::InitSpeech()
{
	//�����ÿ�
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();
	//��ʼ����������
	m_Index = 1;
	//��ʼ����¼����
	this->m_Record.clear();
}

//����ѡ��
void SpeechManager::CreateSpeaker()
{
	string s_nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < s_nameSeed.size(); ++i)
	{
		string name = "ѡ��";
		name += s_nameSeed[i];
		int num;				//ѡ�ֱ��
		Speaker spk;

		spk.m_Name = name;
		for (int i = 1; i < 2; i++)
		{
			spk.m_Score[i] = 0;
		}
		//12��ѡ�ֱ��
		num = 1000 + i;
		this->v1.push_back(num);

		//12��ѡ�ַ���map����
		this->m_Speaker.insert(make_pair(num, spk));
	}
	
}

//��ʼ����
void SpeechManager::StartSpeech()
{
	//��һ�ֱ���
	//��ǩ
	this->SpeechDraw();

	//����
	this->SpeechContest();

	//���
	this->ShowScore();

	//�ڶ��ֱ���
	this->m_Index++;

	//��ǩ
	this->SpeechDraw();

	//����
	this->SpeechContest();

	//���
	this->ShowScore();
	
	//�������
	SaveScore();

	//���ñ���
	//��ʼ������
	this->InitSpeech();
	//����ѡ��
	this->CreateSpeaker();
	//��ȡ�����¼
	this->LoadRecord();

	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");


}

//��ǩ
void SpeechManager::SpeechDraw()
{
	system("cls");
	cout << "�� " << this->m_Index << " ��ѡ�����ڳ�ǩ������" << endl;
	cout << "--------------------------" << endl;
	cout << "��ǩ������£�" << endl;
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

//����
void SpeechManager::SpeechContest()
{
	system("cls");
	cout << "----------- ��" << this->m_Index << " �ֱ�����ʽ��ʼ --------------" << endl;

	//׼����ʱ���� ���С��ɼ�
	multimap<double, int, greater<double>> groupScore;

	int num = 0; //��¼��Ա���� 6��һ��

	vector<int>v_Tmp;//����ѡ������
	if (this->m_Index == 1)
	{
		v_Tmp = v1;
	}
	else
	{
		v_Tmp = v2;
	}

	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Tmp.begin(); it != v_Tmp.end(); it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;   // 600 ~ 1000
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>());//����
		d.pop_front(); //ȥ����߷�
		d.pop_back(); //ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f); //�ܷ�
		double avg = sum / (double)d.size();  //ƽ����

		//��ӡƽ����
		//cout << "��ţ� " << *it << " ������ " << this->m_Speaker[*it].m_Name << " ��ȡƽ���֣� " << avg << endl;

		//��ƽ���ַ��뵽 map������
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//��������� ���뵽��ʱС��������
		groupScore.insert(make_pair(avg, *it)); //key�ǵ÷֣�value�Ǿ���ѡ�ֱ��
		//ÿ6��ȡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ� " << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ� " << it->second << " ������ " << this->m_Speaker[it->second].m_Name << " �ɼ��� "
					<< this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}

			//ȡ��ǰ����
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

			groupScore.clear(); //С���������
			cout << endl;

		}
	}

	cout << "------------------ ��" << this->m_Index << "�ֱ������ --------------" << endl;
	system("pause");

}

//��ʾ�÷���Ϣ
void SpeechManager::ShowScore()
{
	cout << "------------------ ��" << this->m_Index << "�ֽ���ѡ����Ϣ���£� -------------------" << endl;

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
		cout << "ѡ�ֱ�ţ�" << *it << " ������" << this->m_Speaker[*it].m_Name << 
				" �÷֣�" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
}

//�������
void SpeechManager::SaveScore()
{
	ofstream ofs;

	ofs.open("speech.csv", ios::out | ios::app);	//׷�ӵķ�ʽд�ļ�

	//д������
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();

	cout << "�ļ��ѱ��棡" << endl;
	this->fileIsEmpty = false;

}

//��������ɼ���¼
void SpeechManager::LoadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	//�ļ�������
	if ( !ifs.is_open())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;

	ifs.putback(ch);	//������Ķ�ȡ�ĵ����ַ��Ż���
	string data;
	int index = 0;

	while (ifs >> data)
	{
		//����
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

//��ռ�¼
void SpeechManager::ShowRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "�� " <<
				"�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
				"�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
				"������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

void SpeechManager::ClearRecord()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//��ʼ������
		this->InitSpeech();

		//����ѡ��
		this->CreateSpeaker();

		//��ȡ�����¼
		this->LoadRecord();


		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}