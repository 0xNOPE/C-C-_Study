#include "speechManager.h"


int main()
{
	srand((unsigned int)time(NULL));
	SpeechManager sm;
	int i_Select = 0;
	
	while (true)
	{
		sm.ShowMenu();

		cout << "���������ѡ��" << endl;
		cin >> i_Select;

		switch (i_Select)
		{
		case 1:		//��ʼ����
			sm.StartSpeech();
			break;
		case 2:		//�鿴��¼
			sm.ShowRecord();
			break;
		case 3:		//��ռ�¼
			sm.ClearRecord();
			break;
		case 0:		//�˳�ϵͳ
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