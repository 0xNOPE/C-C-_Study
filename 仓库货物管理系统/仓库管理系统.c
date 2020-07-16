#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
struct GOODS
{
	char name[50];					//�������� 
	int num;                        //������ 
	float price;					//����۸� 
	int amount;						//�������� 
}goods[100]; 
int  s=0 ;							//�������� 

//��⺯�� 
void input() 
{ 
	int i=0; 					
	char c; 					
	while(1) 
	{ 
		system("cls"); 
		printf("��Ʒ%d\n",++s); 
		printf("��������Ʒ���:"); 
		scanf("%d",&goods[i].num); 
		printf("��������Ʒ����:");
		scanf("%s",&goods[i].name);
		printf("��������Ʒ�۸�:");
		scanf("%f",&goods[i].price);
		printf("��������Ʒ����:");
		scanf("%d",&goods[i].amount);
		printf("�Ƿ�������(Y/N):");
		fflush(stdin); 
		scanf("%c",&c); 
		i++;
		if(c=='N'||c=='n') 
		break;	 	
	} 	
}
//���⺯��
void output() 
{ 
	int a,b,c,i; 
	char d; 
	char _name[20]; 
	while(1) 
	{ 
		system("cls");  
		printf("\t\t1.����ų���\n");
		printf("\t\t2.�����Ƴ���\n");
		printf("\t\t��ѡ��"); 
		scanf("%d",&a);
		if(a==1)
		{
			printf("�������������ı�ţ�");
			scanf("%d",&b);
			printf("\n");
			for(i=0;i<s;i++)
			{
				
				if(goods[i].amount>0&&i==b)
				{
					printf("�������������");
					scanf("%d",&c);
					if(c>goods[i].amount)
					printf("���ﲻ��\n");
					else
					{
					goods[i].amount-=c;
					printf("���Ϊ%d�Ļ���ɹ�������\n����ʣ��%d\n",goods[i].num,goods[i].amount);
					}	
				}	
			}
			
		}
		if(a==2)
		{
			printf("�����������������ƣ�"); 
			scanf("%s",&_name);
			printf("\n");
			for(i=0;i<s;i++)
			{
				if(strcmp(goods[i].name,_name)==0||goods[i].amount>0)
				{
					printf("�������������");
					fflush(stdin);
					scanf("%d",&c);
					if(c>goods[i].amount)
					printf("���ﲻ��\n");
					else
					{
						goods[i].amount-=c;
						printf("����Ϊ%s�Ļ���ɹ�������\n����ʣ��%d\n",goods[i].name,goods[i].amount);
					}
			}
			else 
			{
				printf("������ѡ��\n");
			} 
			}
			
		}
		else if(a==0)
		break;
		printf("�Ƿ��������(Y/N):"); 
		fflush(stdin);
		scanf("%c",&d); 
		if(d=='N'||d=='n') break; 
	} 
}

void current()
{
	int a;system("cls");
	printf("\t\t1���������\n");
	printf("\t\t2���������\n");
	printf("\t\t0������\n");
	printf("\t\t��ѡ��");
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
//���һ��� 
void search() 
{ 
	int i,a,b; 
	char c; 
	char _name[20]; 
	while(1) 
	{ 
		system("cls"); 
		
		printf("��������Ҫ��ѯ���������:"); 
		scanf("%s",&_name); 
		printf("\n"); 
		for(i=0;i<s;i++) 
		{ 
			if(strcmp(_name,goods[i].name)==0)
			break; 
		} 
		if(i<s) 
		printf("\n���ƣ�%s\n������%d\n",goods[i].name,goods[i].amount); 
		else 
		printf("δ�ҵ�������\n"); 
		
		system("pause");
		printf("�Ƿ��������(Y/N): "); 
		fflush(stdin);
		scanf("%c",&c); 
		if(c=='N'||c=='n') break; 
	}
}


//�����ʾ 
void show ()
{
	int i ;
	system("cls");
	printf("\t���\t����\t�۸�\t����\n");
	for(i=0;i<s;i++)
	{
		printf("\t%d\t%s\t%.2f\t%d\n",goods[i].num,goods[i].name,goods[i].price,goods[i].amount);
	}
	printf("\n");
	printf("���س�������");
	system("pause");
} 
//���ļ�
void open()
{
	FILE *fp;
	int i;
	char file[50];
	char c;
	
	system("cls");
	printf("����򿪵��ļ�����\n");
	scanf("%s",file);
	if((fp=fopen("goods.out","w+"))==NULL)
	{
		printf("���ļ�ʧ��!\n");
		exit(0);
	}
	if(fread(&s,sizeof(int),1,fp)!=1)
	{
		if(feof(fp))
		{
			fclose(fp);
			return;
		}
		printf("�ļ���ȡ����!\n");
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
			printf("�ļ���ȡ����\n");
		}
	}
	fclose(fp);
	printf("���ļ��ɹ���\n");
	printf("���س������أ�");
	c=getchar();c=getchar(); 
	 
} 
//���浽�ļ�
void save()
{
	FILE *fp;
	int i;
	char c,a;
	char file[50];
	system("cls");
	printf("1������\n");
	printf("2�����Ϊ\n");
	printf("0������\n");
	printf("��ѡ��");
	scanf("%d",&a);
	if(a==1)
	{
		if((fp=fopen("goods.out","wb+"))==NULL)
		{
			printf("���ļ�ʧ�ܣ�\n");
		}
		if(fwrite(&s,sizeof(int),1,fp)!=1)
		{
			printf("д���ļ�����\n");
		}
		for(i=0;i<s;i++)
		{
			if(fwrite(&goods[i],sizeof(struct GOODS),1,fp)!=1)
			{
				printf("д���ļ�����\n");
			}
		}
		fclose(fp);
		printf("����ɹ���\n\n");
		printf("���س������أ�");
		c=getchar();c=getchar();
	}
	else if(a==2)
	{
		printf("\n�ļ�����");
		scanf("%s",file);
		if((fp=fopen(file,"wb"))==NULL)
		{
			printf("���ļ�ʧ�ܣ�\n");
		}
		if(fwrite(&s,sizeof(int),1,fp)!=1)
		{
			printf("д���ļ�����\n");
		}
		for(i=0;i<s;i++)
		{
			if(fwrite(&goods[i],sizeof(struct GOODS),1,fp)!=1)
			{
				printf("д���ļ�����\n");}
			}
			fclose(fp);
			printf("����ɹ���\n\n");
			printf("���س������أ�");
			c=getchar();c=getchar();
	}
}
//���˵����� 
void mainmenu()
{
	int  a ; 
	while(1) 
	{ 
		
		system("cls"); 
		printf("\t\t\t\t     ллʹ�òֿ����ϵͳ��\n"); 
		printf("\t\t\t\t* * * * * * * * * * * * * * * * \n"); 
		printf("\t\t\t\t*    1���������ͳ���        * \n"); 
		printf("\t\t\t\t*    2�����һ����            * \n"); 
		printf("\t\t\t\t*    3����ʾ�ֿ�����        * \n"); 
		printf("\t\t\t\t*    4�����浽�ļ�            * \n"); 
		printf("\t\t\t\t*    5�����ļ�              * \n"); 
		printf("\t\t\t\t*    6���˳�                  * \n");
		printf("\t\t\t\t* * * * * * * * * * * * * * * * \n"); 
		
		printf("\t\t\t\t��ѡ��"); 
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
			default:printf("��ѡ����ȷ����ţ�\n");
			printf("\n");
		}
	}  
}
int main ()
{
	mainmenu();	
	return 0;
}

