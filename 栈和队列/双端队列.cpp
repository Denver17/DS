#include<iostream>
using namespace std;

//定义结点类型
typedef struct QNode
{
    int data;                   //数据域
    struct QNode *next;         //指针域
}QNode;

//定义双端队列
typedef struct
{
    QNode *end_1;               //双端队列存在两个指针
    QNode *end_2;
}double_queue;

//队列初始化
void init_queue(double_queue *&dq)
{
    dq=(double_queue*)malloc(sizeof(double_queue));     //一开始并没有写这句，导致代码运行不出结果
    dq->end_1=dq->end_2=NULL;
}

//判断队列是否为空
int is_queue_empty(double_queue *dq)
{
    if(dq->end_1==NULL||dq->end_2==NULL)
        return 1;
    else
        return 0;
}

//左端入队
void en_queue_l(double_queue *&dq,int x)
{
    QNode *p;
    p=(QNode*)malloc(sizeof(QNode));
    p->data=x;
    if(dq->end_1==NULL)            //若队列为空
        dq->end_1=dq->end_2=p;
    else
    {
        //类似于头插法
        p->next=dq->end_1;
        dq->end_1=p;
    }
}

//右端入队
void en_queue_r(double_queue *&dq,int x)
{
    QNode *p;
    p=(QNode*)malloc(sizeof(QNode));
    p->data=x;
    if(dq->end_2==NULL)             //若队列为空
        dq->end_1=dq->end_2=p;
    else
    {
        //将新结点加入队尾
        dq->end_2->next=p;
        dq->end_2=p;
    }
}


//左端出队
int de_queue_l(double_queue *&dq,int &x)
{
    QNode* p;
    if(dq->end_1==NULL)             //队列为空，不允许进行出队操作
        return 0;
    else                            //队列不为空，使p指向最左端的元素
        p=dq->end_1;
    if(dq->end_1==dq->end_2)        //若队列中仅剩最后一个元素
        dq->end_1=dq->end_2=NULL;
    else                            //队列中有多个元素，只需修改end_1指针
        dq->end_1=p->next;
    x=p->data;
    free(p);
    return 1;
}


//右端出队
int de_queue_r(double_queue *&dq,int &x)
{
    QNode* p;
    QNode* temp;                    //用于寻找end_2指针指向结点的前一个结点
    if(dq->end_2==NULL)             //队列为空，不能执行出队操作
        return 0;
    else
    {
        p=dq->end_2;
        temp=dq->end_1;             //temp指针从队首结点开始查找
    }
    if(dq->end_1==dq->end_2)
        dq->end_1=dq->end_2=NULL;
    else
    {
        while(temp->next!=p)        //循环查找，直到找到队列的倒数第二个结点
            temp=temp->next;
        dq->end_2=temp;             //令end_2指向该结点
    }
    //dq->end_2=p->next;
    x=p->data;
    free(p);
    return 1;
}



int main()
{
    double_queue* dq;

    
    //初始化队列
    init_queue(dq);

    //判断队列是否为空
    cout<<endl<<"after en_queue_l() "<<endl;
    if(1==is_queue_empty(dq))
        cout<<endl<<"the queue is empty "<<endl;
    else
        cout<<endl<<"the queue is not empty "<<endl;


    //入队操作
    en_queue_l(dq,1111);

    //判断队列是否为空
    cout<<endl<<"after en_queue_l() "<<endl;
    if(1==is_queue_empty(dq))
        cout<<endl<<"the queue is empty "<<endl;
    else
        cout<<endl<<"the queue is not empty "<<endl;

    en_queue_r(dq,2222);
    en_queue_l(dq,3333);
    en_queue_r(dq,4444);
    en_queue_l(dq,5555);

    int x;

    de_queue_l(dq,x);
    cout<<endl<<"the left head of the queue is "<<endl;
    cout<<x;

    de_queue_l(dq,x);
    cout<<endl<<"the left head of the queue is "<<endl;
    cout<<x;

    de_queue_r(dq,x);
    cout<<endl<<"the right head of the queue is "<<endl;
    cout<<x;

    de_queue_l(dq,x);
    cout<<endl<<"the left head of the queue is "<<endl;
    cout<<x;

    de_queue_r(dq,x);
    cout<<endl<<"the right head of the queue is "<<endl;
    cout<<x;

    return 0;
}
