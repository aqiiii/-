#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 30    		//最高人数限制 
int ave (int score[],int n);					//平均分函数 
int sort (int score[],int num[],int n);			//分数排序 
int resort (int score[],int num[],int n);		//分数反向排序 
int numsort (int score[],int num[],int n);		//学号排序函数 
int statistic (int score[],int num[],int n);	//统计函数 
int swap(int *x,int *y);    					//交换函数 
main()
{
	int n=13,i,choice,choice1,k,nu,temp=0;
	int num[n]={5,3,1,4,2,13,9,6,7,10,8,12,11};       //学号 
	int score[n]={67,88,93,72,55,100,92,88,54,60,73,75,86};     //分数 
	do{
		system("cls");
		printf("\t\t\t欢迎来到学生成绩管理系统！！\n");
		printf("\t1，输入学号和成绩\t\t\t");
		printf("\t5，按学号由小到大排出成绩表\n"); 
		printf("\t2，计算课程的总分和平均分\t\t");
		printf("\t6，按学号查询学生排名及其考试成绩\n"); 
		printf("\t3，按成绩由低到高排出成绩表\t\t"); 
		printf("\t7，成绩统计数据分析\n");
		printf("\t4，按成绩由高到低排出成绩表\t\t"); 
		printf("\t8，数据列表\n");
		printf("\t0，退出\n");
		printf("\n请输入选项：");
		scanf("%d",&choice);					//选择 
		if (choice==1)
		{
			printf("请输入录入学生人数:");
			scanf("%d",&n); 
			for(i=0;i<n;i++)
			{
				printf("请输入学号:");
				scanf("%d",&num[i]);
				printf("请输入该学生成绩:");
				scanf("%d",&score[i]); 
			}
			printf("成绩已经录入！");
			temp=1;
		}
		else if (choice==2)
		{
			printf("该科平均成绩为：%d",ave(score,n)); 
			printf("输入0返回");
			scanf("%d",&choice1);
			if(choice1==0)
				temp=1;
		}
		else if (choice==3)
		{
			sort(score,num,n);
			for(i=0;i<n;i++)
			{
				printf("学号：%d\t\t成绩：%d\n",num[i],score[i]);
			}
			printf("输入0返回");
			scanf("%d",&choice1);
			if(choice1==0)
				temp=1;
			 
		}
		else if (choice==4)
		{
			resort(score,num,n);
			for(i=0;i<n;i++)
			{
				printf("学号：%d\t\t成绩：%d\n",num[i],score[i]);
			}
			printf("输入0返回");
			scanf("%d",&choice1);
			if(choice1==0)
				temp=1;
		}
		else if (choice==5)
		{
			numsort(score,num,n);
			for(i=0;i<n;i++)
			{
				printf("学号：%d\t\t成绩：%d\n",num[i],score[i]);
			}
			printf("输入0返回");
			scanf("%d",&choice1);
			if(choice1==0)
				temp=1;
		}
		else if (choice==6)
		{
			resort (score,num,n);
			printf("请输入所查询学生的学号：");
			scanf("%d",&nu);
			for(i=0;i<n;i++)
			{
				if(num[i]==nu)
				{
					k=i;
					break;
				}
			}	 
			printf("该学生的成绩是：%d排名是：%d",score[k],k+1);
			printf("\n输入0返回");
			scanf("%d",&choice1);
			if(choice1==0)
				temp=1;
		}
		else if (choice==7)
		{
			statistic(score,num,n);
			printf("\n输入0返回");
			scanf("%d",&choice1);
			if(choice1==0)
				temp=1;
		}
		else if (choice==8)
		{
			for(i=0;i<n;i++)
			{
				printf("学号：%d\t\t成绩：%d\n",num[i],score[i]);
			}
			printf("输入0返回");
			scanf("%d",&choice1);
			if(choice1==0)
				temp=1;
			
		}
		else if (choice==0)
		{
			exit(0);
		}
		else 
		{
			printf("错误输入！！");
			temp=1;
			
		}
	}
	while (temp);
} 
int ave (int score[],int n)
{
	int i,sum=0;
	for (i=0;i<n;i++)
	{
		sum+=score[i];
	}
	return sum/n;
}
int sort(int score[],int num[],int n)
{
	int i,j,k,t;
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(score[j]<score[k])
				k=j;	
		}
		if(k!=i)
			{
				swap(&score[k],&score[i]);
				swap(&num[k],&num[i]);
			}
	}
}
int swap(int *x,int *y)
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}
int resort(int score[],int num[],int n)
{
	int i,j,k,t;
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(score[j]>score[k])
				k=j;	
		}
		if(k!=i)
			{
				swap(&score[k],&score[i]);
				swap(&num[k],&num[i]);
			}
	}
}
int numsort(int score[],int num[],int n)
{
	int i,j,k,t;
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(num[j]<num[k])
				k=j;	
		}
		if(k!=i)
			{
				swap(&score[k],&score[i]);
				swap(&num[k],&num[i]);
			}
	}
}
int statistic(int score[],int num[],int n)
{
	int i,a=0,b=0,c=0,d=0,e=0;
	int A[N],B[N],C[N],D[N],E[N]; 
	int a_n[N],b_n[N],c_n[N],d_n[N],e_n[N];
	for (i=0;i<n;i++)
	{
		if (score[i]<=100&&score[i]>90)      //A
		{
			a++;
				A[a-1]=score[i];
				a_n[a-1]=num[i];
		}
		else if(score[i]<=90&&score[i]>80)		//B
		{
			b++;
				B[b-1]=score[i];
				b_n[b-1]=num[i];
		}
		else if(score[i]<=80&&score[i]>70)		//C
		{
			c++;
				C[c-1]=score[i];
				c_n[c-1]=num[i];
		}
		else if(score[i]<=70&&score[i]>60)		//D
		{
			d++;
				D[d-1]=score[i];
				d_n[d-1]=num[i];
		}
		else 						//E
		{
			e++;
				E[e-1]=score[i];
				e_n[e-1]=num[i];
		}
	}
		printf("\t优秀(100~90)：\n");
		for(i=0;i<a;i++)
			printf("\t学号：%d成绩：%d\n",a_n[i],A[i]);
		printf("\n\t共%d人\n",a);
		printf("\t良好(90~80)：\n");
		for(i=0;i<b;i++)
			printf("\t学号：%d成绩：%d\n",b_n[i],B[i]);
		printf("\n\t共%d人\n",b);
		printf("\t中等(80~70)：\n");
		for(i=0;i<c;i++)
			printf("\t学号：%d成绩：%d\n",c_n[i],C[i]);
		printf("\n\t共%d人\n",c);
		printf("\t及格(70~60)：\n");
		for(i=0;i<d;i++)
			printf("\t学号：%d成绩：%d\n",d_n[i],D[i]);
		printf("\n\t共%d人\n",d);
		printf("\t不及格(60~)：\t\n");
		for(i=0;i<e;i++)
			printf("\t学号：%d成绩：%d\n",e_n[i],E[i]);
		printf("\n\t共%d人\n",e);			
}
 

