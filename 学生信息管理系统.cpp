#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct  {  /*通讯录结点类型*/
  char name[10];  /*姓名*/
  char id[13]; /*学号*/
  int math;  //数学成绩 
  int English;   //英语成绩 
  int c;    //C语言成绩 
}ElemType;
#define  MaxSize 100
typedef struct 
{	ElemType data[MaxSize];
   	int length;
}SqList;
void InitList(SqList *&L)
{
   L=(SqList *)malloc(sizeof(SqList)); 
   L->length=0;
}   
void CreateList(SqList *L,ElemType a[],int n) 
{
	int i;
	for (i=0;i<n;i++)
	L->data[i]=a[i];
	L->length=n;
}
void DestroyList(SqList *&L)
    {
          free(L);
    }
int ListEmpty(SqList *L)
    {
	return(L->length==0);
    }
int ListLength(SqList *L)
 {
	return(L->length);
 }
void ListTraverse(SqList *L)
{
	int i;
	if (ListEmpty(L)==1) return;
	for (i=0;i<L->length;i++){
		printf("%s  %s  %d  %d  %d\n",L->data[i].id,L->data[i].name,L->data[i].math,L->data[i].English,L->data[i].c);
	}
		
	printf("\n");
} 
int GetElem(SqList *L,int i,ElemType &e)
   {
	if (i<1 || i>L->length)  return 0;
	e=L->data[i-1];
	return 1;
   }
int ListInsert(SqList *&L,int i,ElemType e)
  {    int j;
        if (i<1 || i>L->length+1)	return 0;
        i--;  
        for (j=L->length-1;j>=i;j--)
          L->data[j+1]=L->data[j]; 
        L->data[i]=e;
        L->length++;    
        return 1;
  }
/*int ListDelete(SqList *&L,char,ElemType *e)
{   int j;
     if (i<1 || i>L->length)	return 0;
     i--;	   
     *e=L->data[i];
     for (j=i;j<L->length-1;j++) L->data[j]=L->data[j+1];            
     L->length--;	
     return 1;
}*/

int ListDelete(SqList *&L,char id[])

{   
	for(int i = 0;i < L->length;i++)
	{
		if(strcmp(id,L->data[i].id)==0)
		{
			for (int j=i;j<L->length-1;j++) 
				L->data[j]=L->data[j+1];            
			L->length--;
			printf("成功删除\n");
			return 1;
		}
		
	}
}
    


int main(){
	SqList *L;   int sel,len=1;
	ElemType p; 
	ElemType a[100];
	InitList(L); 	
	//CreateList(L,a,3);
	bool flag=true;
	while(flag){
		printf("\t\t——————————————————\n") ;
		printf("\t\t\t★学生信息管理系统★\n\n");
		printf("\t\t\t1.输入学生记录\n");
		printf("\t\t\t2.显示学生记录\n");
		printf("\t\t\t3.学生成绩的计算\n");
		printf("\t\t\t4.增加学生记录\n"); 
		printf("\t\t\t5.删除学生记录\n");
		printf("\t\t\t6.查找学生记录\n");
		printf("\t\t\t7.修改学生记录\n"); 
		printf("\t\t\t8.对学生记录排序\n");
		printf("\t\t\t0.退出\n");
		printf("\t\t——————————————————\n") ;
		printf("请选择操作：");
		scanf("%d",&sel);
		switch(sel)
		{
			case 0:  flag=false; break;
			case 1:   while(1)
			{
					 printf("请依次输入学生学号、学生姓名、数学成绩、英语成绩、C语言成绩:\n");
			         scanf("%s",p.id);
			         if(strcmp(p.id,"0")==0)
			         break;
					 scanf("%s %d %d %d",p.name,&p.math,&p.English,&p.c);
			         ListInsert(L,len,p);
			         len++;
			     }
			break;
			case 2:
			printf("显示数据：\n");
			ListTraverse(L);
			break;
			case 3:
				printf("1. 计算总分   2.计算平均分\n");
				printf("请选择：");
				int num;
				scanf("%d",&num);
				if(num==1)
				{
					printf("1.数学总分\t2.英语总分\t3.C语言总分\n");
					printf("请选择：");
					int all;
					scanf("%d",&all);
					if(all==1)
					{
						int mathall=0;
						for (int i=0;i<L->length;i++)
						{
							mathall= mathall + L->data[i].math;	
						}
						printf("数学总分为：%d\n\n",mathall);
					}
					if(all==2)
					{
						int englishall=0;
						for (int i=0;i<L->length;i++)
						{
							englishall= englishall + L->data[i].English;	
						}
						printf("英语总分为：%d\n\n",englishall);
					}
					if(all==3)
					{
						int call=0;
						for (int i=0;i<L->length;i++)
						{
							call= call + L->data[i].c;	
						}
						printf("C语言总分为：%d\n\n",call);
					}
				} 
				if(num==2)
				{
					printf("1.数学平均分\t2.英语平均分\t3.C语言平均分\n");
					printf("请选择：");
					int pingjun;
					scanf("%d",&pingjun);
					if(pingjun==1)
					{
						int mathall=0;
						int mathpingjun;
						for (int i=0;i<L->length;i++)
						{
							mathall= mathall + L->data[i].math;	
						}
						mathpingjun=mathall/L->length;
						printf("数学平均分为：%d\n\n",mathpingjun);
					}
					if(pingjun==2)
					{
						int englishall=0;
						int englishpingjun;
						for (int i=0;i<L->length;i++)
						{
							englishall= englishall + L->data[i].English;	
						}
						englishpingjun=englishall/L->length;
						printf("英语平均分为：%d\n\n",englishpingjun);
					}
					if(pingjun==3)
					{
						int call=0;
						int cpingjun;
						for (int i=0;i<L->length;i++)
						{
							call= call + L->data[i].c;	
						}
						cpingjun= call/L->length;
						printf("C语言平均分为：%d\n\n",cpingjun);
					}
				}
			break;
			case 4:
					int postive;
					printf("请选择插入位置：");
					scanf("%d",&postive);
					printf("请依次输入学生学号、学生姓名、数学成绩、英语成绩、C语言成绩:\n");
			        scanf("%s %s %d %d %d",p.id,p.name,&p.math,&p.English,&p.c);
			        ListInsert(L,postive,p);
			        //按顺序插入ListInsert(L,ListLength(L)+1,p);
				    break;
			case 5: 
					printf("请输入您要删除的学生信息学号：\n");
					char x[10];
					scanf("%s",x);
					ListDelete(L,x);
			        break;
			case 6:
					printf("请输入您要查找的学生信息学号：\n");
					char id[10];
					scanf("%s",id);
					for(int i=0;i<L->length;i++)
					{
						if(strcmp(id,L->data[i].id)==0)
						{
							printf("您查找的学生信息为：\n");
					    	printf("%s  %s  %d  %d  %d\n\n",L->data[i].id,L->data[i].name,L->data[i].math,L->data[i].English,L->data[i].c);
						}
					}
					break;
			case 7:
					printf("请输入您要修改的学生信息学号：\n");
					char id2[10];
					scanf("%s",id2);
					for(int i=0;i<L->length;i++)
					{
						if(strcmp(id2,L->data[i].id)==0)
						{
							printf("请选择您要修改的信息\n");
							printf("1.学生姓名\t2.数学成绩\t3.英语成绩\t4.C语言成绩\n");
							int cho; 
							scanf("%d",&cho);
							if(cho==1)
							{
							char changename[10];
							printf("请输入您要修改的学生姓名");
							scanf("%s",changename);
							strcpy(L->data[i].name,changename);
							printf("修改完成\n");
							}
							if(cho==2)
							{
							int changemath;
							printf("请输入您要修改的数学成绩");
							scanf("%d",&changemath);
							L->data[i].math=changemath;
							printf("修改完成\n");
							}
							if(cho==3)
							{
							int changeEnglish;
							printf("请输入您要修改的英语成绩");
							scanf("%d",&changeEnglish);
							L->data[i].English=changeEnglish;
							printf("修改完成\n");
							}
							if(cho==4)
							{
							int changec;
							printf("请输入您要修改的C语言成绩");
							scanf("%d",&changec);
							L->data[i].c=changec;
							printf("修改完成\n");
							}
						} 
					}
				break;
					 
			case 8:  
			printf("按平均分进行排序：\n");
			printf("请选择排序的方式\n");
			printf("1.升序\t2.降序\n") ;
			printf("请选择：");
			int chop;
			scanf("%d",&chop);
			if(chop==1)
			{ 
			int i,j,t;
			char a[100];
			//(L->data[i].math+L->data[i].English+L->data[i].c)/3;
			for(i=0;i<L->length;i++)
			{
				a[i]=(L->data[i].math+L->data[i].English+L->data[i].c)/3;
			}
			for (j=0;j<L->length-1;j++)
				for(i=0;i<L->length-1-j;i++)
					if( a[i]>a[i+1])
					{
						t=L->data[i].math;
						L->data[i].math=L->data[i+1].math;
						L->data[i+1].math=t;
						
						char p[]={'a'};
						strcpy(p,L->data[i].id);
						//t=L->data[i].id;
						strcpy(L->data[i].id,L->data[i+1].id);
						//L->data[i].id=L->data[i+1].id;
						strcpy(L->data[i+1].id,p);
						//L->data[i+1].id=t;
						
						strcpy(p,L->data[i].name);
						strcpy(L->data[i].name,L->data[i+1].name);
						strcpy(L->data[i+1].name,p);
						
						t=L->data[i].English;
						L->data[i].English=L->data[i+1].English;
						L->data[i+1].English=t;
						
						t=L->data[i].c;
						L->data[i].c=L->data[i+1].c;
						L->data[i+1].c=t;	
					}
			for(i=0;i<L->length;i++)
			printf("%s  %s  %d  %d  %d\n",L->data[i].id,L->data[i].name,L->data[i].math,L->data[i].English,L->data[i].c);
			}
			if(chop==2)
			{
			int i,j,t;
			/*ElemType t;   当t定义为 ElemType  则后面可以直接用下方法 ，不用每个成绩都交换 
			for(i=0;i<L->length;i++)
			{
				a[i]=(L->data[i].math+L->data[i].English+L->data[i].c)/3;
			}
			for (j=0;j<L->length-1;j++)
				for(i=0;i<L->length-1-j;i++)
					if( a[i]<a[i+1])
					{
						t=L->data[i];
						L->data[i]=L->data[i+1];
						L->data[i+1]=t;
					
					}
			for(i=0;i<L->length;i++)
			*/  
			char a[100];
			//(L->data[i].math+L->data[i].English+L->data[i].c)/3;
			for(i=0;i<L->length;i++)
			{
				a[i]=(L->data[i].math+L->data[i].English+L->data[i].c)/3;
			}
			for (j=0;j<L->length-1;j++)
				for(i=0;i<L->length-1-j;i++)
					if( a[i]<a[i+1])
					{
						t=L->data[i].math;
						L->data[i].math=L->data[i+1].math;
						L->data[i+1].math=t;
						
						char p[]={'a'};
						strcpy(p,L->data[i].id);
						//t=L->data[i].id;
						strcpy(L->data[i].id,L->data[i+1].id);
						//L->data[i].id=L->data[i+1].id;
						strcpy(L->data[i+1].id,p);
						//L->data[i+1].id=t;
						
						strcpy(p,L->data[i].name);
						strcpy(L->data[i].name,L->data[i+1].name);
						strcpy(L->data[i+1].name,p);
						
						t=L->data[i].English;
						L->data[i].English=L->data[i+1].English;
						L->data[i+1].English=t;
						
						t=L->data[i].c;
						L->data[i].c=L->data[i+1].c;
						L->data[i+1].c=t;	
					}
			for(i=0;i<L->length;i++)
			printf("%s  %s  %d  %d  %d\n",L->data[i].id,L->data[i].name,L->data[i].math,L->data[i].English,L->data[i].c);	
			}
			break;
					
		}
	} 

}

