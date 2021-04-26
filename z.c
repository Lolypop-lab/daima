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

node *input()  //输入函数
{
    node *head=(node *)malloc(LEN),*p1=0,*p2=head;
	head->next=0;
	int n;
	printf("请输入学生人数\n");
	scanf("%d",&n);
	printf("请输入学生的学号姓名和各科成绩\n");
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
void xs(node *head) //显示函数
{
    node *p1=head->next;
	while(p1)
	{
		printf("%ld %s %.1f %.1f %.1f %.1f %.1f %.1f %.1f %.1f\n",p1->num,p1->name,p1->score[0],p1->score[1],p1->score[2],p1->score[3],p1->score[4],p1->score[5],p1->zscore,p1->ave);
		p1=p1->next;
	}
	system("pause");
}
void xg(node *head)   //修改函数
{
     printf("请输入所修改学生的学号\n");
	 long num;
	 scanf("%ld",&num);
	 node *p1=head->next;
	 while(p1)
	 {
		    int  i;
			float score;
	     if(p1->num==num)
		 {
		     printf("请输入学生所修改科目和成绩\n");
			 printf("* * * * * *菜单* * * * * *\n");
            printf("*       1. 语文          *\n");
            printf("*       2. 数学          *\n");
            printf("*       3. 英语          *\n");
            printf("*       4. 物理          *\n");
            printf("*       5. 化学          *\n");
            printf("*       6. 生物          *\n");
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
void find(node *head) //查找
{
     printf("请输入所查找的学生姓名\n");
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
void add(node *head)//添加
{
    node *p1=head->next,*p=0;
	while(p1->next!=0)
	{
	   p1=p1->next;
	}
	printf("请输入添加的学生的学号姓名和成绩\n");
    p=(node*)malloc(LEN);
	scanf("%ld %s %f %f %f %f %f %f",&p->num,p->name,&p->score[0],&p->score[1],&p->score[2],&p->score[3],&p->score[4],&p->score[5]);
	aver(p);
	p->next=0;
	p1->next=p;
}
void dele (node*head)
{
	 node *p1=head->next,*p2=head,*p=0;
	 printf("请输入的学生姓名\n");
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
        	system("cls");  //清屏幕
            printf("* * * * * *菜单* * * * * *\n");
            printf("*       a. 输入          *\n");
            printf("*       b. 显示          *\n");
            printf("*       c. 修改          *\n");
            printf("*       d. 查找          *\n");
            printf("*       e. 添加          *\n");
            printf("*       f. 删除          *\n");
			printf("*       g. 退出          *\n");
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


