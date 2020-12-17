#include<iostream> 
#include <malloc.h>
#include <stdio.h>
#define MAXNUM 3         /*��������*/
#define price 0.05      /*ÿ��ÿ���ӷ���*/
typedef struct time
{
    int hour;
    int min;
}Time;                    /*ʱ����*/
typedef struct node
{
    char num[10];         /*���ƺ�*/
    Time reach;			//����ʱ�� 
    Time leave;			//�뿪ʱ�� 
}CarNode;                     /*������Ϣ���*/


typedef struct NODE			//˳��ջ 
{
    CarNode *stack[MAXNUM+1];
    int top;
}SeqStackCar;                          /*ģ�⳵վ*/


typedef struct car     //����   �������ݽ�� QueueNode
{
    CarNode *data;
    struct car *next;
}QueueNode;

typedef struct Node		//��������ͷ��� LinkQueueCar
{
    QueueNode *head;
    QueueNode *rear;
}LinkQueueCar;                       /*ģ��ͨ��*/


//��ʼ��ջ  
void StackInit(SeqStackCar *s)
{
	s->top=0;
	for(int i=0;i<=MAXNUM;i++)   //ջδ��ʱ���Ͱѵ���ĳ�����ջ����  
		s->stack[s->top]=NULL;
} 

//��ʼ������		��ջ���������ӽ����� 
int QueueInit(LinkQueueCar *q)
{
	q->head=(QueueNode *)malloc(sizeof(QueueNode));
	//q->head=q->rear=NULL;
	if(q->head!=NULL)
	{
		q->head->next=NULL;
		q->rear=q->head;
		return true;
	}
	else return false;
}


//�շ� 
void Print(CarNode *p,int room)	
{
	int rh,rm,lh,lm;
	printf("\n�����뿪��ʱ��:/**:**/");
	scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
	printf("\n�뿪�����ĳ��ƺ�Ϊ");
	puts(p->num);
	printf("\n�䵽��ʱ��Ϊ��%d:%d",p->reach.hour,p->reach.min);
	printf("\n�뿪ʱ��Ϊ��%d:%d",p->leave.hour,p->leave.min);
	rh=p->reach.hour;
	rm=p->reach.min;
	lh=p->leave.hour;
	lm=p->leave.min;
	printf("\nӦ������Ϊ:%.2fԪ\n",((lh-rh)*60+(lm-rm))*price);		//�˴������� ����23��20���1��15�뿪 Ǯ��Ϊ�� 
	free(p);
}



int Arrival(SeqStackCar *Enter,LinkQueueCar *W) /*��������*/ 
{ 
    CarNode *p;
    QueueNode *t;
    p=(CarNode *)malloc(sizeof(CarNode));
    _flushall();		//��������� 
    printf("\n�����복�ƺ�(��:��A1234):");
	//getchar();
    gets(p->num);
    if(Enter->top<MAXNUM) /*����δ������������*/
    {
        Enter->top++;
        printf("\n�����ڳ�����%dλ��.",Enter->top);
        printf("\n�����뵽��ʱ��:/**:**/");
        scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
        Enter->stack[Enter->top]=p;
        return true;
    }
    else /*�����������������*/
    { 
        printf("\n�ó����ڱ���ȴ�!");
        t=(QueueNode *)malloc(sizeof(QueueNode));
        t->data=p;
        t->next=NULL; 
        W->rear->next=t;
        W->rear=t;
        return true;
    }
}



void Leave(SeqStackCar *Enter,SeqStackCar *Temp,LinkQueueCar *W)/*�����뿪*/
{ 
    int room,j=1;		//room����¼Ҫ�뿪�ĳ���λ�� 
    CarNode *p,*t;
    QueueNode *q;
    /*�жϳ������Ƿ��г�*/
    if(Enter->top>0) /*�г�*/ 	//�ж�ջ���������Ƿ�Ϊ�� 
    { 
        while(j) /*�����뿪��������Ϣ*/ 		//ȷ�����복��λ����ȷ 
        {
            printf("\n�����복�ڳ�����λ��/1--%d/��",Enter->top);
            scanf("%d",&room);
            if(room>=1&&room<=Enter->top) break;
        }
        
        while(Enter->top>room) /*�����뿪*/		//��Ҫɾ�ĳ�ǰ��ĳ�������������ʱջ 
        {
            Temp->top++;
            Temp->stack[Temp->top]=Enter->stack[Enter->top];
            Enter->stack[Enter->top]=NULL;
            Enter->top--;
        } 
        p=Enter->stack[Enter->top];			//��Ҫɾ�ĳ�����㸳��p 
        Enter->stack[Enter->top]=NULL;
        Enter->top--;
        while(Temp->top>=1)					//����ʱջ�ĳ��Ž�ͣ���� 
        {
            Enter->top++;
            Enter->stack[Enter->top]=Temp->stack[Temp->top];
            Temp->stack[Temp->top]=NULL;
            Temp->top--;
        }
        Print(p,room);			//����������շѺ��� 
        
        /*�ж�ͨ�����Ƿ��г�����վ�Ƿ�����*/
        if((W->head!=W->rear)&&Enter->top<MAXNUM) /*����ĳ������복��*/		//���н�ջ�ͳ����в��� 
        //���������г����ͽ���Ž����� 
		{ 
            q=W->head->next;
            t=q->data;
            Enter->top++;
            printf("\n�����%s�ų����복����%dλ��.",t->num,Enter->top);
            printf("\n���������ڵ�ʱ��/**:**/:");
            scanf("%d:%d",&(t->reach.hour),&(t->reach.min));
            W->head->next=q->next;
            if(q==W->rear) W->rear=W->head;
            Enter->stack[Enter->top]=t;
            free(q);
        }
        else 
			printf("\n�����û�г�.\n\n");
    }
    else 
		printf("\n������û�г�."); /*û��*/ 
}



void List1(SeqStackCar *S) /*�б���ʾ������Ϣ*/
{ 
    int i;
    if(S->top>0) /*�жϳ�վ���Ƿ��г�*/
    {
        printf("\n����:");
        printf("\nλ��   ����ʱ��  ���ƺ�\n");
        for(i=1;i<=S->top;i++)
        {
            printf(" %d \t",i);
            printf("%d:%d \t",S->stack[i]->reach.hour,S->stack[i]->reach.min);
            puts(S->stack[i]->num);
        }
    }
    else 
		printf("\n������û�г�");
}
void List2(LinkQueueCar *W) /*�б���ʾ�����Ϣ*/
{ 
    QueueNode *p;
    p=W->head->next;
    if(W->head!=W->rear) /*�ж�ͨ�����Ƿ��г�*/
    {
        printf("\n�ȴ������ĺ���Ϊ:\n");
        while(p!=NULL)
        {
            puts(p->data->num);
            p=p->next;
        }
    }
    else 
		printf("\n�����û�г�.");
}

void List(SeqStackCar S,LinkQueueCar W)
{
    int flag,tag;
    flag=1;
    while(flag)
    {
        printf("\n��ѡ�� 1|2|3:");
        printf("\n1.����\n2.���\n3.����\n");
        while(1)
        { 
            scanf("%d",&tag);
            if(tag>=1||tag<=3) break;
            else printf("\n��ѡ�� 1|2|3:");
        }
        switch(tag)
        {
            case 1:/*�б���ʾ������Ϣ*/
				List1(&S);
				break; 
            case 2:/*�б���ʾ�����Ϣ*/
				List2(&W);
				break; 
            case 3:/*�б���ʾ�����Ϣ*/
				flag=0;
				break;
            default:
				break;
        }
    }
}



int main()
{
    SeqStackCar Enter,Temp;
    LinkQueueCar Wait;
    int ch,j=1;
    StackInit(&Enter); /*��ʼ����վ*/ 
    StackInit(&Temp); /*��ʼ����·����ʱջ*/
    QueueInit(&Wait); /*��ʼ��ͨ��*/
    while(j)    
    { 
    	printf("\n����һ��ͣ��������ϵͳ_(:�١���)_\nThis is a parking lot management system\n") ;
        printf("\n1. ��������");
        printf(" 2. �����뿪");
        printf(" 3. �б���ʾ");
        printf(" 4. �˳�ϵͳ\n");
        while(j)
        {
            scanf("%d",&ch);
            if(ch>=1&&ch<=4)
				break;
            else 
				printf("\n��ѡ�� 1|2|3|4.");
        }
        switch(ch)
        { 
            case 1:/*��������*/
				Arrival(&Enter,&Wait);
				break; 
            case 2: /*�����뿪*/
				Leave(&Enter,&Temp,&Wait);
				break;
            case 3: /*�б��ӡ��Ϣ*/
				List(Enter,Wait);
				break;
            case 4:/*�˳�������*/
				 j=0;
            default: 
				break;
        } 
    }
}


