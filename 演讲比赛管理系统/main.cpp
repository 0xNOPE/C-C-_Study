#include "speechManager.h"


int main()
{
	srand((unsigned int)time(NULL));
	SpeechManager sm;
	int i_Select = 0;
	
	while (true)
	{
		sm.ShowMenu();

		cout << "请输入你的选择：" << endl;
		cin >> i_Select;

		switch (i_Select)
		{
		case 1:		//开始比赛
			sm.StartSpeech();
			break;
		case 2:		//查看记录
			sm.ShowRecord();
			break;
		case 3:		//清空记录
			sm.ClearRecord();
			break;
		case 0:		//退出系统
			sm.ExitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}