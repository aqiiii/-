#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 30    		//����������� 
int ave (int score[],int n);					//ƽ���ֺ��� 
int sort (int score[],int num[],int n);			//�������� 
int resort (int score[],int num[],int n);		//������������ 
int numsort (int score[],int num[],int n);		//ѧ�������� 
int statistic (int score[],int num[],int n);	//ͳ�ƺ��� 
int swap(int *x,int *y);    					//�������� 
main()
{
	int n=13,i,choice,choice1,k,nu,temp=0;
	int num[n]={5,3,1,4,2,13,9,6,7,10,8,12,11};       //ѧ�� 
	int score[n]={67,88,93,72,55,100,92,88,54,60,73,75,86};     //���� 
	do{
		system("cls");
		printf("\t\t\t��ӭ����ѧ���ɼ�����ϵͳ����\n");
		printf("\t1������ѧ�źͳɼ�\t\t\t");
		printf("\t5����ѧ����С�����ų��ɼ���\n"); 
		printf("\t2������γ̵��ֺܷ�ƽ����\t\t");
		printf("\t6����ѧ�Ų�ѯѧ���������俼�Գɼ�\n"); 
		printf("\t3�����ɼ��ɵ͵����ų��ɼ���\t\t"); 
		printf("\t7���ɼ�ͳ�����ݷ���\n");
		printf("\t4�����ɼ��ɸߵ����ų��ɼ���\t\t"); 
		printf("\t8�������б�\n");
		printf("\t0���˳�\n");
		printf("\n������ѡ�");
		scanf("%d",&choice);					//ѡ�� 
		if (choice==1)
		{
			printf("������¼��ѧ������:");
			scanf("%d",&n); 
			for(i=0;i<n;i++)
			{
				printf("������ѧ��:");
				scanf("%d",&num[i]);
				printf("�������ѧ���ɼ�:");
				scanf("%d",&score[i]); 
			}
			printf("�ɼ��Ѿ�¼�룡");
			temp=1;
		}
		else if (choice==2)
		{
			printf("�ÿ�ƽ���ɼ�Ϊ��%d",ave(score,n)); 
			printf("����0����");
			scanf("%d",&choice1);
			if(choice1==0)
				temp=1;
		}
		else if (choice==3)
		{
			sort(score,num,n);
			for(i=0;i<n;i++)
			{
				printf("ѧ�ţ�%d\t\t�ɼ���%d\n",num[i],score[i]);
			}
			printf("����0����");
			scanf("%d",&choice1);
			if(choice1==0)
				temp=1;
			 
		}
		else if (choice==4)
		{
			resort(score,num,n);
			for(i=0;i<n;i++)
			{
				printf("ѧ�ţ�%d\t\t�ɼ���%d\n",num[i],score[i]);
			}
			printf("����0����");
			scanf("%d",&choice1);
			if(choice1==0)
				temp=1;
		}
		else if (choice==5)
		{
			numsort(score,num,n);
			for(i=0;i<n;i++)
			{
				printf("ѧ�ţ�%d\t\t�ɼ���%d\n",num[i],score[i]);
			}
			printf("����0����");
			scanf("%d",&choice1);
			if(choice1==0)
				temp=1;
		}
		else if (choice==6)
		{
			resort (score,num,n);
			printf("����������ѯѧ����ѧ�ţ�");
			scanf("%d",&nu);
			for(i=0;i<n;i++)
			{
				if(num[i]==nu)
				{
					k=i;
					break;
				}
			}	 
			printf("��ѧ���ĳɼ��ǣ�%d�����ǣ�%d",score[k],k+1);
			printf("\n����0����");
			scanf("%d",&choice1);
			if(choice1==0)
				temp=1;
		}
		else if (choice==7)
		{
			statistic(score,num,n);
			printf("\n����0����");
			scanf("%d",&choice1);
			if(choice1==0)
				temp=1;
		}
		else if (choice==8)
		{
			for(i=0;i<n;i++)
			{
				printf("ѧ�ţ�%d\t\t�ɼ���%d\n",num[i],score[i]);
			}
			printf("����0����");
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
			printf("�������룡��");
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
		printf("\t����(100~90)��\n");
		for(i=0;i<a;i++)
			printf("\tѧ�ţ�%d�ɼ���%d\n",a_n[i],A[i]);
		printf("\n\t��%d��\n",a);
		printf("\t����(90~80)��\n");
		for(i=0;i<b;i++)
			printf("\tѧ�ţ�%d�ɼ���%d\n",b_n[i],B[i]);
		printf("\n\t��%d��\n",b);
		printf("\t�е�(80~70)��\n");
		for(i=0;i<c;i++)
			printf("\tѧ�ţ�%d�ɼ���%d\n",c_n[i],C[i]);
		printf("\n\t��%d��\n",c);
		printf("\t����(70~60)��\n");
		for(i=0;i<d;i++)
			printf("\tѧ�ţ�%d�ɼ���%d\n",d_n[i],D[i]);
		printf("\n\t��%d��\n",d);
		printf("\t������(60~)��\t\n");
		for(i=0;i<e;i++)
			printf("\tѧ�ţ�%d�ɼ���%d\n",e_n[i],E[i]);
		printf("\n\t��%d��\n",e);			
}
 

