#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
struct GOODS
{
	char name[50];					//货物名称 
	int num;                        //货物编号 
	float price;					//货物价格 
	int amount;						//货物数量 
}goods[100]; 
int  s=0 ;							//货物总数 

//入库函数 
void input() 
{ 
	int i=0; 					
	char c; 					
	while(1) 
	{ 
		system("cls"); 
		printf("物品%d\n",++s); 
		printf("请输入物品编号:"); 
		scanf("%d",&goods[i].num); 
		printf("请输入物品名称:");
		scanf("%s",&goods[i].name);
		printf("请输入物品价格:");
		scanf("%f",&goods[i].price);
		printf("请输入物品数量:");
		scanf("%d",&goods[i].amount);
		printf("是否继续入库(Y/N):");
		fflush(stdin); 
		scanf("%c",&c); 
		i++;
		if(c=='N'||c=='n') 
		break;	 	
	} 	
}
//出库函数
void output() 
{ 
	int a,b,c,i; 
	char d; 
	char _name[20]; 
	while(1) 
	{ 
		system("cls");  
		printf("\t\t1.按编号出库\n");
		printf("\t\t2.按名称出库\n");
		printf("\t\t请选择："); 
		scanf("%d",&a);
		if(a==1)
		{
			printf("请输入出货货物的编号：");
			scanf("%d",&b);
			printf("\n");
			for(i=0;i<s;i++)
			{
				
				if(goods[i].amount>0&&i==b)
				{
					printf("请输入出货量：");
					scanf("%d",&c);
					if(c>goods[i].amount)
					printf("货物不足\n");
					else
					{
					goods[i].amount-=c;
					printf("编号为%d的货物成功出货！\n货物剩余%d\n",goods[i].num,goods[i].amount);
					}	
				}	
			}
			
		}
		if(a==2)
		{
			printf("请输入出货货物的名称："); 
			scanf("%s",&_name);
			printf("\n");
			for(i=0;i<s;i++)
			{
				if(strcmp(goods[i].name,_name)==0||goods[i].amount>0)
				{
					printf("请输入出货量：");
					fflush(stdin);
					scanf("%d",&c);
					if(c>goods[i].amount)
					printf("货物不足\n");
					else
					{
						goods[i].amount-=c;
						printf("名称为%s的货物成功出货！\n货物剩余%d\n",goods[i].name,goods[i].amount);
					}
			}
			else 
			{
				printf("请重新选择\n");
			} 
			}
			
		}
		else if(a==0)
		break;
		printf("是否继续出库(Y/N):"); 
		fflush(stdin);
		scanf("%c",&d); 
		if(d=='N'||d=='n') break; 
	} 
}

void current()
{
	int a;system("cls");
	printf("\t\t1、货物入库\n");
	printf("\t\t2、货物出库\n");
	printf("\t\t0、返回\n");
	printf("\t\t请选择：");
	scanf("%d",&a);
	if(a==1)
	{
		input();
	}
	else if(a==2)
	{
		output();
	}
}
//查找货物 
void search() 
{ 
	int i,a,b; 
	char c; 
	char _name[20]; 
	while(1) 
	{ 
		system("cls"); 
		
		printf("请输入需要查询货物的名称:"); 
		scanf("%s",&_name); 
		printf("\n"); 
		for(i=0;i<s;i++) 
		{ 
			if(strcmp(_name,goods[i].name)==0)
			break; 
		} 
		if(i<s) 
		printf("\n名称：%s\n数量：%d\n",goods[i].name,goods[i].amount); 
		else 
		printf("未找到此名称\n"); 
		
		system("pause");
		printf("是否继续查找(Y/N): "); 
		fflush(stdin);
		scanf("%c",&c); 
		if(c=='N'||c=='n') break; 
	}
}


//库存显示 
void show ()
{
	int i ;
	system("cls");
	printf("\t编号\t名称\t价格\t数量\n");
	for(i=0;i<s;i++)
	{
		printf("\t%d\t%s\t%.2f\t%d\n",goods[i].num,goods[i].name,goods[i].price,goods[i].amount);
	}
	printf("\n");
	printf("按回车键返回");
	system("pause");
} 
//打开文件
void open()
{
	FILE *fp;
	int i;
	char file[50];
	char c;
	
	system("cls");
	printf("输入打开的文件名：\n");
	scanf("%s",file);
	if((fp=fopen("goods.out","w+"))==NULL)
	{
		printf("打开文件失败!\n");
		exit(0);
	}
	if(fread(&s,sizeof(int),1,fp)!=1)
	{
		if(feof(fp))
		{
			fclose(fp);
			return;
		}
		printf("文件读取错误!\n");
	}
	for(i=0;i<s;i++)
	{
		if(fread(&goods[i],sizeof(struct GOODS),1,fp)!=1)
		{
			if(feof(fp))
			{
				fclose(fp);
				return;
			}
			printf("文件读取错误！\n");
		}
	}
	fclose(fp);
	printf("打开文件成功！\n");
	printf("按回车键返回！");
	c=getchar();c=getchar(); 
	 
} 
//保存到文件
void save()
{
	FILE *fp;
	int i;
	char c,a;
	char file[50];
	system("cls");
	printf("1、储存\n");
	printf("2、另存为\n");
	printf("0、返回\n");
	printf("请选择：");
	scanf("%d",&a);
	if(a==1)
	{
		if((fp=fopen("goods.out","wb+"))==NULL)
		{
			printf("打开文件失败！\n");
		}
		if(fwrite(&s,sizeof(int),1,fp)!=1)
		{
			printf("写入文件错误！\n");
		}
		for(i=0;i<s;i++)
		{
			if(fwrite(&goods[i],sizeof(struct GOODS),1,fp)!=1)
			{
				printf("写入文件错误！\n");
			}
		}
		fclose(fp);
		printf("保存成功！\n\n");
		printf("按回车键返回！");
		c=getchar();c=getchar();
	}
	else if(a==2)
	{
		printf("\n文件名：");
		scanf("%s",file);
		if((fp=fopen(file,"wb"))==NULL)
		{
			printf("打开文件失败！\n");
		}
		if(fwrite(&s,sizeof(int),1,fp)!=1)
		{
			printf("写入文件错误！\n");
		}
		for(i=0;i<s;i++)
		{
			if(fwrite(&goods[i],sizeof(struct GOODS),1,fp)!=1)
			{
				printf("写入文件错误！\n");}
			}
			fclose(fp);
			printf("保存成功！\n\n");
			printf("按回车键返回！");
			c=getchar();c=getchar();
	}
}
//主菜单界面 
void mainmenu()
{
	int  a ; 
	while(1) 
	{ 
		
		system("cls"); 
		printf("\t\t\t\t     谢谢使用仓库管理系统！\n"); 
		printf("\t\t\t\t* * * * * * * * * * * * * * * * \n"); 
		printf("\t\t\t\t*    1、货物入库和出库        * \n"); 
		printf("\t\t\t\t*    2、查找货物表            * \n"); 
		printf("\t\t\t\t*    3、显示仓库货物表        * \n"); 
		printf("\t\t\t\t*    4、保存到文件            * \n"); 
		printf("\t\t\t\t*    5、打开文件              * \n"); 
		printf("\t\t\t\t*    6、退出                  * \n");
		printf("\t\t\t\t* * * * * * * * * * * * * * * * \n"); 
		
		printf("\t\t\t\t请选择："); 
		scanf("%d",&a); 
		switch(a) 
		{ 
			case 1:current();
				break; 
			case 2:search();
				break; 
			case 3:show();
				break; 
			case 4:save();
				break; 
			case 5:open();
				break;
			case 6:exit(0); 
				break;
			default:printf("请选择正确的序号！\n");
			printf("\n");
		}
	}  
}
int main ()
{
	mainmenu();	
	return 0;
}

