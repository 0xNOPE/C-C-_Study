#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 8
#define BUFSIZE 1000
#define _CRT_SECURE_NO_WARNINGS

//���ѧ���ɼ��ṹ��
typedef struct
{
	char m_Id[20];		//ѧ��
	char m_Name[20];	//����
	int m_Math;			//��ѧ
	int m_Physics;		//����
	int m_English;		//Ӣ��
	int m_Computer;		//�����
	int m_Sum;			//�ܷ�
	float m_Average;	//ƽ���ɼ�
} Student;

//���ѧ���ṹ������ṹ��
typedef struct
{
	Student ss[NUM];
}StuArr;

//��Ƶ������ݽṹ��
typedef struct
{
	//��ѧ
	int m_mMax;		//��ѧ��߷�
	int m_mMin;		//��ѧ��ͷ�
	int m_mSum;		//��ѧ�ܷ�
	float m_mAvr;	//��ѧƽ����
	int m_mFailNum;	//��ѧ����������
	int m_mPassNum;	//��ѧ��������
	int m_mGoodNum;	//��ѧ��������
	int m_mFineNum;	//��ѧ��������

	//����
	int m_phyMax;		//������߷�
	int m_phyMin;		//������ͷ�
	int m_phySum;		//�����ܷ�
	float m_phyAvr;		//����ƽ����
	int m_phyFailNum;	//������������
	int m_phyPassNum;	//����������
	int m_phyGoodNum;	//������������
	int m_phyFineNum;	//������������

	//Ӣ��
	int m_eMax;		//Ӣ����߷�
	int m_eMin;		//Ӣ����ͷ�
	int m_eSum;		//Ӣ���ܷ�
	float m_eAvr;	//Ӣ��ƽ����
	int m_eFailNum;	//Ӣ�ﲻ��������
	int m_ePassNum;	//Ӣ�Ｐ������
	int m_eGoodNum;	//Ӣ����������
	int m_eFineNum;	//Ӣ����������

	//�����
	int m_cMax;		//�������߷�
	int m_cMin;		//�������ͷ�
	int m_cSum;		//������ܷ�
	float m_cAvr;	//�����ƽ����
	int m_cFailNum;	//���������������
	int m_cPassNum;	//�������������
	int m_cGoodNum;	//�������������
	int m_cFineNum;	//�������������

} Subject;

//Student ss[NUM];
Subject sj;

//�˵���ʾ
void list();
//����ѧ���ɼ�
void fileread(StuArr *sa);
//���˳ɼ�����
void paverage(StuArr *sa);
//���Ƴɼ�����
void count(StuArr *sa);
//�ܷ��ɸߵ�������
void sort(StuArr *sa);
//���ɳɼ��ļ�
void filewrite(StuArr *sa);

//������
int main()
{
	//����ѧ���ṹ������ṹ��
	StuArr sa;

	int select = 0;		//�����û�ѡ�����

	while (1)
	{
		//��ʾ�˵�
		list();

		scanf("%d", &select);

		switch (select)
		{
		case 1:		//���ļ�stuscore.in����ѧ���ɼ�
			fileread(&sa);
			break;
		case 2:		//���˳ɼ����� ��ʾÿ���˵�ѧ�ţ����������Ƴɼ����ܷ֣�ƽ����
			paverage(&sa);
			break;
		case 3:		//���Ƴɼ���������ʾ��߷֣���ͷ֣�ƽ���֣������񣬼������ã���������
			count(&sa);
			break; 
		case 4:		//���ܷ��ɸߵ�������
			sort(&sa);
			break;
		case 5:		//��ѧ���ɼ��͵��Ƴɼ�����д���ļ�stuscore.out
			filewrite(&sa);
			break;
		case 6:		//�˳�
			printf("\n\t\t\t      ��ӭ�´�ʹ�ã�\n\n");
			system("pause");
			exit(0);
			break;
		default:
			printf("�����������������룡��");
			system("pause");
			system("cls");
			break;
		}
	}

}

//�˵���ʾ
void list()
{
	printf("\t\t  ************************************\n");
	printf("\t\t  *     ��ӭʹ��ѧ���ɼ�����ϵͳ     *\n");
	printf("\t\t  *         1������ѧ���ɼ�          *\n");
	printf("\t\t  *         2�����˳ɼ�����          *\n");
	printf("\t\t  *         3�����Ƴɼ�����          *\n");
	printf("\t\t  *         4��ѧ���ɼ�����          *\n");
	printf("\t\t  *         5�����ɳɼ��ļ�          *\n");
	printf("\t\t  *         6������                  *\n");
	printf("\t\t  ************************************\n");
	printf("\t\t              ��ѡ��1~6��");
}

//1������ѧ���ɼ�
void fileread(StuArr *sa)
{
	FILE * fp = NULL;
	int i;
	char buf[BUFSIZE];

	//���ļ�
	fopen_s(&fp, "stuscore.in", "r");

	if (fp == NULL)
	{
		printf("Cannot open file!\n");
		return 1;
	}

	for (i = 0; i < NUM; i++)
	{
		fgets(buf, BUFSIZE, fp);
		sscanf(buf, "%s%s%d%d%d%d", sa->ss[i].m_Id, sa->ss[i].m_Name, &sa->ss[i].m_Math, &sa->ss[i].m_Physics, &sa->ss[i].m_English, &sa->ss[i].m_Computer);
	}

	//�ر��ļ�
	fclose(fp);

}

//2�����˳ɼ�����
void paverage(StuArr *sa)
{
	int i;
	FILE * fp = NULL;
	char buf[BUFSIZE];

	//����¼������
	//���ļ�
	fopen_s(&fp, "stuscore.in", "r");
	if (fp == NULL)
	{
		printf("Cannot open file!\n");
		return 1;
	}
	for (i = 0; i < NUM; i++)
	{
		fgets(buf, BUFSIZE, fp);
		sscanf(buf, "%s%s%d%d%d%d", sa->ss[i].m_Id, sa->ss[i].m_Name, &sa->ss[i].m_Math, &sa->ss[i].m_Physics, &sa->ss[i].m_English, &sa->ss[i].m_Computer);
	}
	//�ر��ļ�
	fclose(fp);
	//�����ܷ�ƽ����
	for (i = 0; i < NUM; i++)
	{
		sa->ss[i].m_Sum = sa->ss[i].m_Math + sa->ss[i].m_Physics + sa->ss[i].m_English + sa->ss[i].m_Computer;
		sa->ss[i].m_Average = sa->ss[i].m_Sum / 4.0;
	}

	printf("\t\t\t  ��ѧ���ɼ�ͳ�Ʒ������£�\n\n");
	printf("       ѧ��           ����    ��ѧ    ����    Ӣ��  �����    �ܷ�  ƽ���ɼ�");
	for (i = 0; i < NUM; i++)
	{
		printf("\n%s%15s%8d%8d%8d%8d%8d%8.2f", sa->ss[i].m_Id, sa->ss[i].m_Name, sa->ss[i].m_Math, sa->ss[i].m_Physics, sa->ss[i].m_English, sa->ss[i].m_Computer, sa->ss[i].m_Sum, sa->ss[i].m_Average);
	}
	printf("\n");
	printf("\n\t\t  ��ѧ���ɼ�������ϣ���ѡ������������\n\n");

}

//3�����Ƴɼ�����
void count(StuArr *sa)
{
	int i;
	int math[NUM], physics[NUM], English[NUM], computer[NUM];

	//��ʼ������
	sj.m_cFailNum = sj.m_cFineNum = sj.m_cGoodNum = sj.m_cPassNum = sj.m_cSum = 0;
	sj.m_eFailNum = sj.m_eFineNum = sj.m_eGoodNum = sj.m_ePassNum = sj.m_eSum = 0;
	sj.m_mFailNum = sj.m_mFineNum = sj.m_mGoodNum = sj.m_mPassNum = sj.m_mSum = 0;
	sj.m_phyFailNum = sj.m_phyFineNum = sj.m_phyGoodNum = sj.m_phyPassNum = sj.m_phySum = 0;
	
	//ѭ������Student�ṹ������,�����Ƴɼ������Ӧ��������
	for (i = 0; i < NUM; i++)
	{
		math[i] = sa->ss[i].m_Math;
		physics[i] = sa->ss[i].m_Physics;
		English[i] = sa->ss[i].m_English;
		computer[i] = sa->ss[i].m_Computer;
	}

	//������ѧ����
	sj.m_mMax = sj.m_mMin = math[0];
	for (i = 0; i < NUM; i++)
	{
		if (sj.m_mMax < math[i])	sj.m_mMax = math[i];
		if (sj.m_mMin > math[i])	sj.m_mMin = math[i];

		if (math[i] < 60)	sj.m_mFailNum++;
		else if (math[i] >= 60 && math[i] < 70)	sj.m_mPassNum++;
		else if (math[i] >= 70 && math[i] < 85)	sj.m_mGoodNum++;
		else  sj.m_mFineNum++;

		sj.m_mSum += math[i];
	}
	sj.m_mAvr = sj.m_mSum / 8.0;

	//������������
	sj.m_phyMax = sj.m_phyMin = physics[0];
	for (i = 0; i < NUM; i++)
	{
		if (sj.m_phyMax < physics[i])	sj.m_phyMax = physics[i];
		if (sj.m_phyMin > physics[i])	sj.m_phyMin = physics[i];

		if (physics[i] < 60)	sj.m_phyFailNum++;
		else if (physics[i] >= 60 && physics[i] < 70)	sj.m_phyPassNum++;
		else if (physics[i] >= 70 && physics[i] < 85)	sj.m_phyGoodNum++;
		else  sj.m_phyFineNum++;

		sj.m_phySum += physics[i];
	}
	sj.m_phyAvr = sj.m_phySum / 8.0;

	//����Ӣ������
	sj.m_eMax = sj.m_eMin = English[0];
	for (i = 0; i < NUM; i++)
	{
		if (sj.m_eMax < English[i])	sj.m_eMax = English[i];
		if (sj.m_eMin > English[i])	sj.m_eMin = English[i];

		if (English[i] < 60)	sj.m_eFailNum++;
		else if (English[i] >= 60 && English[i] < 70)	sj.m_ePassNum++;
		else if (English[i] >= 70 && English[i] < 85)	sj.m_eGoodNum++;
		else  sj.m_eFineNum++;

		sj.m_eSum += English[i];
	}
	sj.m_eAvr = sj.m_eSum / 8.0;

	//�������������
	sj.m_cMax = sj.m_cMin = computer[0];
	for (i = 0; i < NUM; i++)
	{
		if (sj.m_cMax < computer[i])	sj.m_cMax = computer[i];
		if (sj.m_cMin > computer[i])	sj.m_cMin = computer[i];

		if (computer[i] < 60)	sj.m_cFailNum++;
		else if (computer[i] >= 60 && computer[i] < 70)	sj.m_cPassNum++;
		else if (computer[i] >= 70 && computer[i] < 85)	sj.m_cGoodNum++;
		else  sj.m_cFineNum++;

		sj.m_cSum += computer[i];
	}
	sj.m_cAvr = sj.m_cSum / 8.0;

	printf("\t\t\t  ���Ƴɼ�ͳ�Ʒ������£�\n\n");
	printf("�� ��    ��߷�    ��ͷ�    ƽ����    ������   ����   ����    ����\n");
	printf("�� ѧ\t%5d%10d%12.2f%7d%8d%8d%8d\n", sj.m_mMax, sj.m_mMin, sj.m_mAvr, sj.m_mFailNum, sj.m_mPassNum, sj.m_mGoodNum, sj.m_mFineNum);
	printf("�� ��\t%5d%10d%12.2f%7d%8d%8d%8d\n", sj.m_phyMax, sj.m_phyMin, sj.m_phyAvr, sj.m_phyFailNum, sj.m_phyPassNum, sj.m_phyGoodNum, sj.m_phyFineNum);
	printf("Ӣ ��\t%5d%10d%12.2f%7d%8d%8d%8d\n", sj.m_eMax, sj.m_eMin, sj.m_eAvr, sj.m_eFailNum, sj.m_ePassNum, sj.m_eGoodNum, sj.m_eFineNum);
	printf("�����\t%5d%10d%12.2f%7d%8d%8d%8d\n", sj.m_cMax, sj.m_cMin, sj.m_cAvr, sj.m_cFailNum, sj.m_cPassNum, sj.m_cGoodNum, sj.m_cFineNum);
	
	printf("\n\n\t\t  ���Ƴɼ�������ϣ���ѡ������������\n\n");
}

//4���ܷ��ɸߵ�������
void sort(StuArr *sa)
{
	int i,j;
	Student temp;

	//�����ܷ�ƽ����	
	for (i = 0; i < NUM; i++)
	{
		sa->ss[i].m_Sum = sa->ss[i].m_Math + sa->ss[i].m_Physics + sa->ss[i].m_English + sa->ss[i].m_Computer;
		sa->ss[i].m_Average = sa->ss[i].m_Sum / 4.0;
	}

	//ѡ������
	for (i = 0; i < NUM; i++)
	{
		for (j = i + 1; j < NUM + 1; j++)
			if (sa->ss[i].m_Sum < sa->ss[j].m_Sum)//���бȽ�
			//�ȽϺ���н���
			{
				temp = sa->ss[i];
				sa->ss[i] = sa->ss[j];
				sa->ss[j] = temp;
			}
	}

	//����������Ľ��
	printf("\t\t\t  ��ѧ���ɼ�ͳ�������£�\n\n");
	printf("       ѧ��           ����    ��ѧ    ����    Ӣ��  �����    �ܷ�  ƽ���ɼ�   ����");
	for (i = 0; i < NUM; i++)
	{
		printf("\n%s%15s%8d%8d%8d%8d%8d%8.2f%8d", sa->ss[i].m_Id, sa->ss[i].m_Name, 
			sa->ss[i].m_Math, sa->ss[i].m_Physics, sa->ss[i].m_English, 
			sa->ss[i].m_Computer, sa->ss[i].m_Sum, sa->ss[i].m_Average, i + 1 );
	}
	printf("\n");
}

//5�����ɳɼ��ļ�
void filewrite(StuArr *sa)
{
	FILE * fp = NULL;
	int i, j;
	Student temp;

	//���ļ�
	if ((fp = fopen("stuscore.out", "w")) == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}

	//�����ܷ�ƽ����	
	for (i = 0; i < NUM; i++)
	{
		sa->ss[i].m_Sum = sa->ss[i].m_Math + sa->ss[i].m_Physics + sa->ss[i].m_English + sa->ss[i].m_Computer;
		sa->ss[i].m_Average = sa->ss[i].m_Sum / 4.0;
	}
	//ѡ������
	for (i = 0; i < NUM; i++)
	{
		for (j = i + 1; j < NUM + 1; j++)
			if (sa->ss[i].m_Sum < sa->ss[j].m_Sum)//���бȽ�
			//�ȽϺ���н���
			{
				temp = sa->ss[i];
				sa->ss[i] = sa->ss[j];
				sa->ss[j] = temp;
			}
	}

	fprintf(fp, "       ѧ��        ����    ��ѧ    ����    Ӣ��  �����    �ܷ�  ƽ���ɼ�    ����");
	for (i = 0; i < NUM; i++)
	{
		fprintf(fp, "\n%s%12s%8d%8d%8d%8d%8d%10.2f%8d", sa->ss[i].m_Id, sa->ss[i].m_Name, 
			sa->ss[i].m_Math, sa->ss[i].m_Physics, sa->ss[i].m_English, 
			sa->ss[i].m_Computer, sa->ss[i].m_Sum, sa->ss[i].m_Average, i + 1);
	}

	fprintf(fp, "\n\n     ���Ƴɼ�ͳ�ƽ�����£�\n");
	fprintf(fp, "�� ��   ��߷�   ��ͷ�  ƽ����   ������  ����   ����   ����\n");
	fprintf(fp, "�� ѧ\t%4d%9d%10.2f%7d%7d%7d%7d\n", sj.m_mMax, sj.m_mMin, sj.m_mAvr, sj.m_mFailNum, sj.m_mPassNum, sj.m_mGoodNum, sj.m_mFineNum);
	fprintf(fp, "�� ��\t%4d%9d%10.2f%7d%7d%7d%7d\n", sj.m_phyMax, sj.m_phyMin, sj.m_phyAvr, sj.m_phyFailNum, sj.m_phyPassNum, sj.m_phyGoodNum, sj.m_phyFineNum);
	fprintf(fp, "Ӣ ��\t%4d%9d%10.2f%7d%7d%7d%7d\n", sj.m_eMax, sj.m_eMin, sj.m_eAvr, sj.m_eFailNum, sj.m_ePassNum, sj.m_eGoodNum, sj.m_eFineNum);
	fprintf(fp, "�����\t%4d%9d%10.2f%7d%7d%7d%7d\n", sj.m_cMax, sj.m_cMin, sj.m_cAvr, sj.m_cFailNum, sj.m_cPassNum, sj.m_cGoodNum, sj.m_cFineNum);


	//�ر��ļ�
	fclose(fp);
	printf("\n\t\t  �ѽ��ɼ�������ļ�����ѡ������������\n\n");
}