#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct  {  /*ͨѶ¼�������*/
  char name[10];  /*����*/
  char id[13]; /*ѧ��*/
  int math;  //��ѧ�ɼ� 
  int English;   //Ӣ��ɼ� 
  int c;    //C���Գɼ� 
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
			printf("�ɹ�ɾ��\n");
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
		printf("\t\t������������������������������������\n") ;
		printf("\t\t\t��ѧ����Ϣ����ϵͳ��\n\n");
		printf("\t\t\t1.����ѧ����¼\n");
		printf("\t\t\t2.��ʾѧ����¼\n");
		printf("\t\t\t3.ѧ���ɼ��ļ���\n");
		printf("\t\t\t4.����ѧ����¼\n"); 
		printf("\t\t\t5.ɾ��ѧ����¼\n");
		printf("\t\t\t6.����ѧ����¼\n");
		printf("\t\t\t7.�޸�ѧ����¼\n"); 
		printf("\t\t\t8.��ѧ����¼����\n");
		printf("\t\t\t0.�˳�\n");
		printf("\t\t������������������������������������\n") ;
		printf("��ѡ�������");
		scanf("%d",&sel);
		switch(sel)
		{
			case 0:  flag=false; break;
			case 1:   while(1)
			{
					 printf("����������ѧ��ѧ�š�ѧ����������ѧ�ɼ���Ӣ��ɼ���C���Գɼ�:\n");
			         scanf("%s",p.id);
			         if(strcmp(p.id,"0")==0)
			         break;
					 scanf("%s %d %d %d",p.name,&p.math,&p.English,&p.c);
			         ListInsert(L,len,p);
			         len++;
			     }
			break;
			case 2:
			printf("��ʾ���ݣ�\n");
			ListTraverse(L);
			break;
			case 3:
				printf("1. �����ܷ�   2.����ƽ����\n");
				printf("��ѡ��");
				int num;
				scanf("%d",&num);
				if(num==1)
				{
					printf("1.��ѧ�ܷ�\t2.Ӣ���ܷ�\t3.C�����ܷ�\n");
					printf("��ѡ��");
					int all;
					scanf("%d",&all);
					if(all==1)
					{
						int mathall=0;
						for (int i=0;i<L->length;i++)
						{
							mathall= mathall + L->data[i].math;	
						}
						printf("��ѧ�ܷ�Ϊ��%d\n\n",mathall);
					}
					if(all==2)
					{
						int englishall=0;
						for (int i=0;i<L->length;i++)
						{
							englishall= englishall + L->data[i].English;	
						}
						printf("Ӣ���ܷ�Ϊ��%d\n\n",englishall);
					}
					if(all==3)
					{
						int call=0;
						for (int i=0;i<L->length;i++)
						{
							call= call + L->data[i].c;	
						}
						printf("C�����ܷ�Ϊ��%d\n\n",call);
					}
				} 
				if(num==2)
				{
					printf("1.��ѧƽ����\t2.Ӣ��ƽ����\t3.C����ƽ����\n");
					printf("��ѡ��");
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
						printf("��ѧƽ����Ϊ��%d\n\n",mathpingjun);
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
						printf("Ӣ��ƽ����Ϊ��%d\n\n",englishpingjun);
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
						printf("C����ƽ����Ϊ��%d\n\n",cpingjun);
					}
				}
			break;
			case 4:
					int postive;
					printf("��ѡ�����λ�ã�");
					scanf("%d",&postive);
					printf("����������ѧ��ѧ�š�ѧ����������ѧ�ɼ���Ӣ��ɼ���C���Գɼ�:\n");
			        scanf("%s %s %d %d %d",p.id,p.name,&p.math,&p.English,&p.c);
			        ListInsert(L,postive,p);
			        //��˳�����ListInsert(L,ListLength(L)+1,p);
				    break;
			case 5: 
					printf("��������Ҫɾ����ѧ����Ϣѧ�ţ�\n");
					char x[10];
					scanf("%s",x);
					ListDelete(L,x);
			        break;
			case 6:
					printf("��������Ҫ���ҵ�ѧ����Ϣѧ�ţ�\n");
					char id[10];
					scanf("%s",id);
					for(int i=0;i<L->length;i++)
					{
						if(strcmp(id,L->data[i].id)==0)
						{
							printf("�����ҵ�ѧ����ϢΪ��\n");
					    	printf("%s  %s  %d  %d  %d\n\n",L->data[i].id,L->data[i].name,L->data[i].math,L->data[i].English,L->data[i].c);
						}
					}
					break;
			case 7:
					printf("��������Ҫ�޸ĵ�ѧ����Ϣѧ�ţ�\n");
					char id2[10];
					scanf("%s",id2);
					for(int i=0;i<L->length;i++)
					{
						if(strcmp(id2,L->data[i].id)==0)
						{
							printf("��ѡ����Ҫ�޸ĵ���Ϣ\n");
							printf("1.ѧ������\t2.��ѧ�ɼ�\t3.Ӣ��ɼ�\t4.C���Գɼ�\n");
							int cho; 
							scanf("%d",&cho);
							if(cho==1)
							{
							char changename[10];
							printf("��������Ҫ�޸ĵ�ѧ������");
							scanf("%s",changename);
							strcpy(L->data[i].name,changename);
							printf("�޸����\n");
							}
							if(cho==2)
							{
							int changemath;
							printf("��������Ҫ�޸ĵ���ѧ�ɼ�");
							scanf("%d",&changemath);
							L->data[i].math=changemath;
							printf("�޸����\n");
							}
							if(cho==3)
							{
							int changeEnglish;
							printf("��������Ҫ�޸ĵ�Ӣ��ɼ�");
							scanf("%d",&changeEnglish);
							L->data[i].English=changeEnglish;
							printf("�޸����\n");
							}
							if(cho==4)
							{
							int changec;
							printf("��������Ҫ�޸ĵ�C���Գɼ�");
							scanf("%d",&changec);
							L->data[i].c=changec;
							printf("�޸����\n");
							}
						} 
					}
				break;
					 
			case 8:  
			printf("��ƽ���ֽ�������\n");
			printf("��ѡ������ķ�ʽ\n");
			printf("1.����\t2.����\n") ;
			printf("��ѡ��");
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
			/*ElemType t;   ��t����Ϊ ElemType  ��������ֱ�����·��� ������ÿ���ɼ������� 
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

