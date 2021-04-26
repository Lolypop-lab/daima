#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(node)
typedef struct data
{
	long num;
    char name[20];
    float score[6];
	float zscore;
    float ave;
	struct data *next;
}node;  

node *input()  //���뺯��
{
    node *head=(node *)malloc(LEN),*p1=0,*p2=head;
	head->next=0;
	int n;
	printf("������ѧ������\n");
	scanf("%d",&n);
	printf("������ѧ����ѧ�������͸��Ƴɼ�\n");
    for(int i=0;i<n;i++)
	{
	    p1=(node*)malloc(LEN);
		scanf("%ld %s %f %f %f %f %f %f",&p1->num,p1->name,&p1->score[0],&p1->score[1],&p1->score[2],&p1->score[3],&p1->score[4],&p1->score[5]);
		 p1->zscore=0;
		 for(int j=0;j<6;j++)
		{
		    p1->zscore+=p1->score[j];
		}
		p1->ave=p1->zscore/6;
		p1->next=0;
		p2->next=p1;
		p2=p1;
	}
	return head;
}
void aver(node *p)
{   
	p->zscore=0;
	p->ave=0;
    for(int j=0;j<6;j++)
		{
		    p->zscore+=p->score[j];
		}
		p->ave=p->zscore/6;
}
void xs(node *head) //��ʾ����
{
    node *p1=head->next;
	while(p1)
	{
		printf("%ld %s %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n",p1->num,p1->name,p1->score[0],p1->score[1],p1->score[2],p1->score[3],p1->score[4],p1->score[5],p1->zscore,p1->ave);
		p1=p1->next;
	}
	system("pause");
}
void xg(node *head)   //�޸ĺ���
{
     printf("���������޸�ѧ����ѧ��\n");
	 long num;
	 scanf("%ld",&num);
	 node *p1=head->next;
	 while(p1)
	 {
		    int  i;
			float score;
	     if(p1->num==num)
		 {
		     printf("������ѧ�����޸Ŀ�Ŀ�ͳɼ�\n");
			 printf("* * * * * *�˵�* * * * * *\n");
            printf("*       1. ����          *\n");
            printf("*       2. ��ѧ          *\n");
            printf("*       3. Ӣ��          *\n");
            printf("*       4. ����          *\n");
            printf("*       5. ��ѧ          *\n");
            printf("*       6. ����          *\n");
            printf("    Please select a to f    *\n");
            printf("* * * * * * * * * * * * * *\n");
			scanf("%d %f",&i,&score);
			 if(i==1)
             { p1->score[0]=score;
			   aver(p1);
					break;
			 }
			 else if(i==2)
			 {
			       p1->score[1]=score;
				   aver(p1);
					break;
			 } else if(i==3)
			 {
			       p1->score[2]=score;
				   aver(p1);
					break;
			 } else if(i==4)
			 {
			       p1->score[3]=score;
					break;
			 } else if(i==5)
			 {
			       p1->score[4]=score;
				   aver(p1);
					break;
			 } else if(i==6)
			 {
			       p1->score[5]=score;
				   aver(p1);
					break;
			 } 
 
		 }
		 p1=p1->next;
	 }
}
void find(node *head) //����
{
     printf("�����������ҵ�ѧ������\n");
	 char   name[10];
	 scanf("%s",name);
	 node *p1=head->next;
	 while(p1)
	 {
		 if(strcmp(p1->name,name)==0)
		 {
		    printf("%ld %s %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n",p1->num,p1->name,p1->score[0],p1->score[1],p1->score[2],p1->score[3],p1->score[4],p1->score[5],p1->zscore,p1->ave);
		    break;
		 }
		 p1=p1->next;
	 }
	 system("pause");
}
void add(node *head)//���
{
    node *p1=head->next,*p=0;
	while(p1->next!=0)
	{
	   p1=p1->next;
	}
	printf("��������ӵ�ѧ����ѧ�������ͳɼ�\n");
    p=(node*)malloc(LEN);
	scanf("%ld %s %f %f %f %f %f %f",&p->num,p->name,&p->score[0],&p->score[1],&p->score[2],&p->score[3],&p->score[4],&p->score[5]);
	aver(p);
	p->next=0;
	p1->next=p;
}
void dele (node*head)
{
	 node *p1=head->next,*p2=head,*p=0;
	 printf("�������ѧ������\n");
	 char   name[10];
	 scanf("%s",name);
	while(p1!=0)
	{     
		     if(strcmp(p1->name,name)==0)
			{
			    p2->next=p1->next;
				free(p1);
				p1=0;
				break;
			}
			else
			{
			  p2=p1;
			  p1=p1->next;
			}
	}
}
void tui(node*head)
{
	node *p=head->next,*p1=0;
	  while(p)
	  { 
		  p->zscore=0;
          p->ave=0;
	    for(int j=0;j<6;j++)
		{
		    p->zscore+=p->score[j];
		}
		p->ave=p->zscore/6;
		p=p->next;
	  }
	  FILE *p3;
	if((p3=fopen("1.txt","w"))==NULL)
	{
	   printf("cannot open this  file\n");
	}
	p1=head->next;
	while(p1)
	{
		   
		   fprintf(p3,"%ld %s %.1f %.1f %.1f %.1f %.1f\n",p1->num,p1->name,p1->score[0],p1->score[1],p1->score[2],p1->score[3],p1->score[4],p1->zscore,p1->ave);
	       p1=p1->next;
	}
    if(fclose(p3))
	{
	   printf("cannot close this  file\n");
	   exit(0);
	}
}
int main()
{
      char i;
	  node *head=0,*p1=0;
      for( ; ;)     
      {
        	system("cls");  //����Ļ
            printf("* * * * * *�˵�* * * * * *\n");
            printf("*       a. ����          *\n");
            printf("*       b. ��ʾ          *\n");
            printf("*       c. �޸�          *\n");
            printf("*       d. ����          *\n");
            printf("*       e. ���          *\n");
            printf("*       f. ɾ��          *\n");
			printf("*       g. �˳�          *\n");
            printf("    Please select a to g    *\n");
            printf("* * * * * * * * * * * * * *\n");
            i=getchar();
            if(i=='g') break;
            else switch(i)
            {
                case 'a': head=input();break;
                case 'b': xs(head) ;break;
                case 'c': xg(head);break;
                case 'd': find(head);break;
                case 'e': add(head); break;
			    case 'f': dele(head); break;
            }
      }
	tui(head);
    return  0;
}


