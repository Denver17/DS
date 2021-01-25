#include<iostream>
using namespace std;


//队结点类型定义
typedef struct QNode
{
    int data;                   //数据域
    struct QNode *next;         //指针域
}QNode;                         //队结点类型定义


//链队类型定义
typedef struct
{
    QNode *front;               //队首指针
    QNode *rear;                //队尾指针
}li_queue;                      //链队类型定义


//初始化链队
void init_queue(li_queue *&lqu)
{
    lqu=(li_queue*)malloc(sizeof(li_queue));
    lqu->front=lqu->rear=NULL;
}

//判断队列是否为空
int is_queue_empty(li_queue *lqu)
{
    //队首指针或者队尾指针一个为空即可判断队列为空
    if(lqu->front==NULL||lqu->rear==NULL)
        return 1;
    else
        return 0;
}

//入队算法
void en_queue(li_queue *lqu,int x)
{
    QNode *p;
    p=(QNode*)malloc(sizeof(QNode*));
    p->data=x;
    p->next=NULL;
    if(lqu->rear==NULL)                 //若队列为空，则新结点既是队首结点，也是队尾结点
        lqu->rear=lqu->front=p;
    else
    {
        lqu->rear->next=p;              //队尾指针指向的元素的next指向p（将p加入队列中）
        lqu->rear=p;                    //队尾指针指向的元素也变为p
    }
}


//出队算法
int de_queue(li_queue *lqu,int &x)
{
    QNode *p;
    if(lqu->front==NULL)                //队列为空，不能出队
        return 0;
    else
        p=lqu->front;                   //让p指向队首元素

    if(lqu->front==lqu->rear)           //队列中只有一个元素，将队首指针与队尾指针均指向空
        lqu->front=lqu->rear=NULL;
    else    
        lqu->front=p->next;

    x=p->data;
    free(p);
    return 1;
}



int main()
{
    li_queue* lqu;

    //队列初始化
    init_queue(lqu);

    //判断队列是否为空
    cout<<endl<<"before en_queue() "<<endl;
    if(1==is_queue_empty(lqu))
        cout<<endl<<"the queue is empty "<<endl;
    else
        cout<<endl<<"the queue is not empty "<<endl;

    //入队操作
    en_queue(lqu,1001);
    en_queue(lqu,2333);    
    en_queue(lqu,7024);
    en_queue(lqu,10023);

    //判断队列是否为空
    cout<<endl<<"after en_queue() "<<endl;
    if(1==is_queue_empty(lqu))
        cout<<endl<<"the queue is empty "<<endl;
    else
        cout<<endl<<"the queue is not empty "<<endl;

    int x;

    de_queue(lqu,x);
    cout<<endl<<"the head of the queue is "<<endl;
    cout<<x;

    de_queue(lqu,x);
    cout<<endl<<"the head of the queue is "<<endl;
    cout<<x;
    
    de_queue(lqu,x);
    cout<<endl<<"the head of the queue is "<<endl;
    cout<<x;

    de_queue(lqu,x);
    cout<<endl<<"the head of the queue is "<<endl;
    cout<<x;

    return 0;
}
