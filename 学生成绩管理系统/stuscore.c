#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 8
#define BUFSIZE 1000
#define _CRT_SECURE_NO_WARNINGS

//设计学生成绩结构体
typedef struct
{
	char m_Id[20];		//学号
	char m_Name[20];	//姓名
	int m_Math;			//数学
	int m_Physics;		//物理
	int m_English;		//英语
	int m_Computer;		//计算机
	int m_Sum;			//总分
	float m_Average;	//平均成绩
} Student;

//设计学生结构体数组结构体
typedef struct
{
	Student ss[NUM];
}StuArr;

//设计单科数据结构体
typedef struct
{
	//数学
	int m_mMax;		//数学最高分
	int m_mMin;		//数学最低分
	int m_mSum;		//数学总分
	float m_mAvr;	//数学平均分
	int m_mFailNum;	//数学不及格人数
	int m_mPassNum;	//数学及格人数
	int m_mGoodNum;	//数学良好人数
	int m_mFineNum;	//数学优秀人数

	//物理
	int m_phyMax;		//物理最高分
	int m_phyMin;		//物理最低分
	int m_phySum;		//物理总分
	float m_phyAvr;		//物理平均分
	int m_phyFailNum;	//物理不及格人数
	int m_phyPassNum;	//物理及格人数
	int m_phyGoodNum;	//物理良好人数
	int m_phyFineNum;	//物理优秀人数

	//英语
	int m_eMax;		//英语最高分
	int m_eMin;		//英语最低分
	int m_eSum;		//英语总分
	float m_eAvr;	//英语平均分
	int m_eFailNum;	//英语不及格人数
	int m_ePassNum;	//英语及格人数
	int m_eGoodNum;	//英语良好人数
	int m_eFineNum;	//英语优秀人数

	//计算机
	int m_cMax;		//计算机最高分
	int m_cMin;		//计算机最低分
	int m_cSum;		//计算机总分
	float m_cAvr;	//计算机平均分
	int m_cFailNum;	//计算机不及格人数
	int m_cPassNum;	//计算机及格人数
	int m_cGoodNum;	//计算机良好人数
	int m_cFineNum;	//计算机优秀人数

} Subject;

//Student ss[NUM];
Subject sj;

//菜单显示
void list();
//读入学生成绩
void fileread(StuArr *sa);
//个人成绩分析
void paverage(StuArr *sa);
//单科成绩分析
void count(StuArr *sa);
//总分由高到低排序
void sort(StuArr *sa);
//生成成绩文件
void filewrite(StuArr *sa);

//主函数
int main()
{
	//创建学生结构体数组结构体
	StuArr sa;

	int select = 0;		//创建用户选择变量

	while (1)
	{
		//显示菜单
		list();

		scanf("%d", &select);

		switch (select)
		{
		case 1:		//从文件stuscore.in读入学生成绩
			fileread(&sa);
			break;
		case 2:		//个人成绩分析 显示每个人的学号，姓名，各科成绩，总分，平均分
			paverage(&sa);
			break;
		case 3:		//单科成绩分析，显示最高分，最低分，平均分，不及格，及格，良好，优秀人数
			count(&sa);
			break; 
		case 4:		//按总分由高到低排序
			sort(&sa);
			break;
		case 5:		//将学生成绩和单科成绩分析写入文件stuscore.out
			filewrite(&sa);
			break;
		case 6:		//退出
			printf("\n\t\t\t      欢迎下次使用！\n\n");
			system("pause");
			exit(0);
			break;
		default:
			printf("输入有误，请重新输入！！");
			system("pause");
			system("cls");
			break;
		}
	}

}

//菜单显示
void list()
{
	printf("\t\t  ************************************\n");
	printf("\t\t  *     欢迎使用学生成绩管理系统     *\n");
	printf("\t\t  *         1、读入学生成绩          *\n");
	printf("\t\t  *         2、个人成绩分析          *\n");
	printf("\t\t  *         3、单科成绩分析          *\n");
	printf("\t\t  *         4、学生成绩排序          *\n");
	printf("\t\t  *         5、生成成绩文件          *\n");
	printf("\t\t  *         6、结束                  *\n");
	printf("\t\t  ************************************\n");
	printf("\t\t              请选择1~6：");
}

//1、读入学生成绩
void fileread(StuArr *sa)
{
	FILE * fp = NULL;
	int i;
	char buf[BUFSIZE];

	//打开文件
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

	//关闭文件
	fclose(fp);

}

//2、个人成绩分析
void paverage(StuArr *sa)
{
	int i;
	FILE * fp = NULL;
	char buf[BUFSIZE];

	//重新录入数据
	//打开文件
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
	//关闭文件
	fclose(fp);
	//计算总分平均分
	for (i = 0; i < NUM; i++)
	{
		sa->ss[i].m_Sum = sa->ss[i].m_Math + sa->ss[i].m_Physics + sa->ss[i].m_English + sa->ss[i].m_Computer;
		sa->ss[i].m_Average = sa->ss[i].m_Sum / 4.0;
	}

	printf("\t\t\t  各学生成绩统计分析如下：\n\n");
	printf("       学号           姓名    数学    物理    英语  计算机    总分  平均成绩");
	for (i = 0; i < NUM; i++)
	{
		printf("\n%s%15s%8d%8d%8d%8d%8d%8.2f", sa->ss[i].m_Id, sa->ss[i].m_Name, sa->ss[i].m_Math, sa->ss[i].m_Physics, sa->ss[i].m_English, sa->ss[i].m_Computer, sa->ss[i].m_Sum, sa->ss[i].m_Average);
	}
	printf("\n");
	printf("\n\t\t  各学生成绩分析完毕，请选择其他操作！\n\n");

}

//3、单科成绩分析
void count(StuArr *sa)
{
	int i;
	int math[NUM], physics[NUM], English[NUM], computer[NUM];

	//初始化数据
	sj.m_cFailNum = sj.m_cFineNum = sj.m_cGoodNum = sj.m_cPassNum = sj.m_cSum = 0;
	sj.m_eFailNum = sj.m_eFineNum = sj.m_eGoodNum = sj.m_ePassNum = sj.m_eSum = 0;
	sj.m_mFailNum = sj.m_mFineNum = sj.m_mGoodNum = sj.m_mPassNum = sj.m_mSum = 0;
	sj.m_phyFailNum = sj.m_phyFineNum = sj.m_phyGoodNum = sj.m_phyPassNum = sj.m_phySum = 0;
	
	//循环遍历Student结构体数组,将单科成绩存入对应单科数组
	for (i = 0; i < NUM; i++)
	{
		math[i] = sa->ss[i].m_Math;
		physics[i] = sa->ss[i].m_Physics;
		English[i] = sa->ss[i].m_English;
		computer[i] = sa->ss[i].m_Computer;
	}

	//遍历数学数组
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

	//遍历物理数组
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

	//遍历英语数组
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

	//遍历计算机数组
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

	printf("\t\t\t  单科成绩统计分析如下：\n\n");
	printf("课 程    最高分    最低分    平均分    不及格   及格   良好    优秀\n");
	printf("数 学\t%5d%10d%12.2f%7d%8d%8d%8d\n", sj.m_mMax, sj.m_mMin, sj.m_mAvr, sj.m_mFailNum, sj.m_mPassNum, sj.m_mGoodNum, sj.m_mFineNum);
	printf("物 理\t%5d%10d%12.2f%7d%8d%8d%8d\n", sj.m_phyMax, sj.m_phyMin, sj.m_phyAvr, sj.m_phyFailNum, sj.m_phyPassNum, sj.m_phyGoodNum, sj.m_phyFineNum);
	printf("英 语\t%5d%10d%12.2f%7d%8d%8d%8d\n", sj.m_eMax, sj.m_eMin, sj.m_eAvr, sj.m_eFailNum, sj.m_ePassNum, sj.m_eGoodNum, sj.m_eFineNum);
	printf("计算机\t%5d%10d%12.2f%7d%8d%8d%8d\n", sj.m_cMax, sj.m_cMin, sj.m_cAvr, sj.m_cFailNum, sj.m_cPassNum, sj.m_cGoodNum, sj.m_cFineNum);
	
	printf("\n\n\t\t  单科成绩分析完毕，请选择其他操作！\n\n");
}

//4、总分由高到低排序
void sort(StuArr *sa)
{
	int i,j;
	Student temp;

	//计算总分平均分	
	for (i = 0; i < NUM; i++)
	{
		sa->ss[i].m_Sum = sa->ss[i].m_Math + sa->ss[i].m_Physics + sa->ss[i].m_English + sa->ss[i].m_Computer;
		sa->ss[i].m_Average = sa->ss[i].m_Sum / 4.0;
	}

	//选择排序
	for (i = 0; i < NUM; i++)
	{
		for (j = i + 1; j < NUM + 1; j++)
			if (sa->ss[i].m_Sum < sa->ss[j].m_Sum)//进行比较
			//比较后进行交换
			{
				temp = sa->ss[i];
				sa->ss[i] = sa->ss[j];
				sa->ss[j] = temp;
			}
	}

	//输出排序过后的结果
	printf("\t\t\t  各学生成绩统排序如下：\n\n");
	printf("       学号           姓名    数学    物理    英语  计算机    总分  平均成绩   名次");
	for (i = 0; i < NUM; i++)
	{
		printf("\n%s%15s%8d%8d%8d%8d%8d%8.2f%8d", sa->ss[i].m_Id, sa->ss[i].m_Name, 
			sa->ss[i].m_Math, sa->ss[i].m_Physics, sa->ss[i].m_English, 
			sa->ss[i].m_Computer, sa->ss[i].m_Sum, sa->ss[i].m_Average, i + 1 );
	}
	printf("\n");
}

//5、生成成绩文件
void filewrite(StuArr *sa)
{
	FILE * fp = NULL;
	int i, j;
	Student temp;

	//打开文件
	if ((fp = fopen("stuscore.out", "w")) == NULL) {
		printf("文件打开失败\n");
		exit(0);
	}

	//计算总分平均分	
	for (i = 0; i < NUM; i++)
	{
		sa->ss[i].m_Sum = sa->ss[i].m_Math + sa->ss[i].m_Physics + sa->ss[i].m_English + sa->ss[i].m_Computer;
		sa->ss[i].m_Average = sa->ss[i].m_Sum / 4.0;
	}
	//选择排序
	for (i = 0; i < NUM; i++)
	{
		for (j = i + 1; j < NUM + 1; j++)
			if (sa->ss[i].m_Sum < sa->ss[j].m_Sum)//进行比较
			//比较后进行交换
			{
				temp = sa->ss[i];
				sa->ss[i] = sa->ss[j];
				sa->ss[j] = temp;
			}
	}

	fprintf(fp, "       学号        姓名    数学    物理    英语  计算机    总分  平均成绩    名次");
	for (i = 0; i < NUM; i++)
	{
		fprintf(fp, "\n%s%12s%8d%8d%8d%8d%8d%10.2f%8d", sa->ss[i].m_Id, sa->ss[i].m_Name, 
			sa->ss[i].m_Math, sa->ss[i].m_Physics, sa->ss[i].m_English, 
			sa->ss[i].m_Computer, sa->ss[i].m_Sum, sa->ss[i].m_Average, i + 1);
	}

	fprintf(fp, "\n\n     单科成绩统计结果如下：\n");
	fprintf(fp, "课 程   最高分   最低分  平均分   不及格  及格   良好   优秀\n");
	fprintf(fp, "数 学\t%4d%9d%10.2f%7d%7d%7d%7d\n", sj.m_mMax, sj.m_mMin, sj.m_mAvr, sj.m_mFailNum, sj.m_mPassNum, sj.m_mGoodNum, sj.m_mFineNum);
	fprintf(fp, "物 理\t%4d%9d%10.2f%7d%7d%7d%7d\n", sj.m_phyMax, sj.m_phyMin, sj.m_phyAvr, sj.m_phyFailNum, sj.m_phyPassNum, sj.m_phyGoodNum, sj.m_phyFineNum);
	fprintf(fp, "英 语\t%4d%9d%10.2f%7d%7d%7d%7d\n", sj.m_eMax, sj.m_eMin, sj.m_eAvr, sj.m_eFailNum, sj.m_ePassNum, sj.m_eGoodNum, sj.m_eFineNum);
	fprintf(fp, "计算机\t%4d%9d%10.2f%7d%7d%7d%7d\n", sj.m_cMax, sj.m_cMin, sj.m_cAvr, sj.m_cFailNum, sj.m_cPassNum, sj.m_cGoodNum, sj.m_cFineNum);


	//关闭文件
	fclose(fp);
	printf("\n\t\t  已将成绩输出到文件，请选择其他操作！\n\n");
}