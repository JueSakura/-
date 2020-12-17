#include<iostream> 
#include <malloc.h>
#include <stdio.h>
#define MAXNUM 3         /*车库容量*/
#define price 0.05      /*每车每分钟费用*/
typedef struct time
{
    int hour;
    int min;
}Time;                    /*时间结点*/
typedef struct node
{
    char num[10];         /*车牌号*/
    Time reach;			//到达时间 
    Time leave;			//离开时间 
}CarNode;                     /*车辆信息结点*/


typedef struct NODE			//顺序栈 
{
    CarNode *stack[MAXNUM+1];
    int top;
}SeqStackCar;                          /*模拟车站*/


typedef struct car     //链队   声明数据结点 QueueNode
{
    CarNode *data;
    struct car *next;
}QueueNode;

typedef struct Node		//声明链队头结点 LinkQueueCar
{
    QueueNode *head;
    QueueNode *rear;
}LinkQueueCar;                       /*模拟通道*/


//初始化栈  
void StackInit(SeqStackCar *s)
{
	s->top=0;
	for(int i=0;i<=MAXNUM;i++)   //栈未满时，就把到达的车辆进栈函数  
		s->stack[s->top]=NULL;
} 

//初始化队列		当栈满，车辆从进入便道 
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


//收费 
void Print(CarNode *p,int room)	
{
	int rh,rm,lh,lm;
	printf("\n车辆离开的时间:/**:**/");
	scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
	printf("\n离开车辆的车牌号为");
	puts(p->num);
	printf("\n其到达时间为：%d:%d",p->reach.hour,p->reach.min);
	printf("\n离开时间为：%d:%d",p->leave.hour,p->leave.min);
	rh=p->reach.hour;
	rm=p->reach.min;
	lh=p->leave.hour;
	lm=p->leave.min;
	printf("\n应交费用为:%.2f元\n",((lh-rh)*60+(lm-rm))*price);		//此处有问题 例：23：20到达，1：15离开 钱数为负 
	free(p);
}



int Arrival(SeqStackCar *Enter,LinkQueueCar *W) /*车辆到达*/ 
{ 
    CarNode *p;
    QueueNode *t;
    p=(CarNode *)malloc(sizeof(CarNode));
    _flushall();		//清除缓冲区 
    printf("\n请输入车牌号(例:京A1234):");
	//getchar();
    gets(p->num);
    if(Enter->top<MAXNUM) /*车场未满，车进车场*/
    {
        Enter->top++;
        printf("\n车辆在车场第%d位置.",Enter->top);
        printf("\n请输入到达时间:/**:**/");
        scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
        Enter->stack[Enter->top]=p;
        return true;
    }
    else /*车场已满，车进便道*/
    { 
        printf("\n该车须在便道等待!");
        t=(QueueNode *)malloc(sizeof(QueueNode));
        t->data=p;
        t->next=NULL; 
        W->rear->next=t;
        W->rear=t;
        return true;
    }
}



void Leave(SeqStackCar *Enter,SeqStackCar *Temp,LinkQueueCar *W)/*车辆离开*/
{ 
    int room,j=1;		//room：记录要离开的车辆位置 
    CarNode *p,*t;
    QueueNode *q;
    /*判断车场内是否有车*/
    if(Enter->top>0) /*有车*/ 	//判断栈（车场）是否为空 
    { 
        while(j) /*输入离开车辆的信息*/ 		//确保输入车辆位置正确 
        {
            printf("\n请输入车在车场的位置/1--%d/：",Enter->top);
            scanf("%d",&room);
            if(room>=1&&room<=Enter->top) break;
        }
        
        while(Enter->top>room) /*车辆离开*/		//把要删的车前面的车开出，进入临时栈 
        {
            Temp->top++;
            Temp->stack[Temp->top]=Enter->stack[Enter->top];
            Enter->stack[Enter->top]=NULL;
            Enter->top--;
        } 
        p=Enter->stack[Enter->top];			//把要删的车辆结点赋给p 
        Enter->stack[Enter->top]=NULL;
        Enter->top--;
        while(Temp->top>=1)					//把临时栈的车放进停车场 
        {
            Enter->top++;
            Enter->stack[Enter->top]=Temp->stack[Temp->top];
            Temp->stack[Temp->top]=NULL;
            Temp->top--;
        }
        Print(p,room);			//调用上面的收费函数 
        
        /*判断通道上是否有车及车站是否已满*/
        if((W->head!=W->rear)&&Enter->top<MAXNUM) /*便道的车辆进入车场*/		//进行进栈和出队列操作 
        //如果便道上有车，就将其放进车场 
		{ 
            q=W->head->next;
            t=q->data;
            Enter->top++;
            printf("\n便道的%s号车进入车场第%d位置.",t->num,Enter->top);
            printf("\n请输入现在的时间/**:**/:");
            scanf("%d:%d",&(t->reach.hour),&(t->reach.min));
            W->head->next=q->next;
            if(q==W->rear) W->rear=W->head;
            Enter->stack[Enter->top]=t;
            free(q);
        }
        else 
			printf("\n便道里没有车.\n\n");
    }
    else 
		printf("\n车场里没有车."); /*没车*/ 
}



void List1(SeqStackCar *S) /*列表显示车场信息*/
{ 
    int i;
    if(S->top>0) /*判断车站内是否有车*/
    {
        printf("\n车场:");
        printf("\n位置   到达时间  车牌号\n");
        for(i=1;i<=S->top;i++)
        {
            printf(" %d \t",i);
            printf("%d:%d \t",S->stack[i]->reach.hour,S->stack[i]->reach.min);
            puts(S->stack[i]->num);
        }
    }
    else 
		printf("\n车场里没有车");
}
void List2(LinkQueueCar *W) /*列表显示便道信息*/
{ 
    QueueNode *p;
    p=W->head->next;
    if(W->head!=W->rear) /*判断通道上是否有车*/
    {
        printf("\n等待车辆的号码为:\n");
        while(p!=NULL)
        {
            puts(p->data->num);
            p=p->next;
        }
    }
    else 
		printf("\n便道里没有车.");
}

void List(SeqStackCar S,LinkQueueCar W)
{
    int flag,tag;
    flag=1;
    while(flag)
    {
        printf("\n请选择 1|2|3:");
        printf("\n1.车场\n2.便道\n3.返回\n");
        while(1)
        { 
            scanf("%d",&tag);
            if(tag>=1||tag<=3) break;
            else printf("\n请选择 1|2|3:");
        }
        switch(tag)
        {
            case 1:/*列表显示车场信息*/
				List1(&S);
				break; 
            case 2:/*列表显示便道信息*/
				List2(&W);
				break; 
            case 3:/*列表显示便道信息*/
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
    StackInit(&Enter); /*初始化车站*/ 
    StackInit(&Temp); /*初始化让路的临时栈*/
    QueueInit(&Wait); /*初始化通道*/
    while(j)    
    { 
    	printf("\n这是一个停车场管理系统_(:з」∠)_\nThis is a parking lot management system\n") ;
        printf("\n1. 车辆到达");
        printf(" 2. 车辆离开");
        printf(" 3. 列表显示");
        printf(" 4. 退出系统\n");
        while(j)
        {
            scanf("%d",&ch);
            if(ch>=1&&ch<=4)
				break;
            else 
				printf("\n请选择： 1|2|3|4.");
        }
        switch(ch)
        { 
            case 1:/*车辆到达*/
				Arrival(&Enter,&Wait);
				break; 
            case 2: /*车辆离开*/
				Leave(&Enter,&Temp,&Wait);
				break;
            case 3: /*列表打印信息*/
				List(Enter,Wait);
				break;
            case 4:/*退出主程序*/
				 j=0;
            default: 
				break;
        } 
    }
}


