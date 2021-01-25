#include<iostream>
using namespace std;

#define max_size 10

typedef struct
{
    int data[max_size];
    int front;                      //队首指针
    int rear;                       //队尾指针
}sq_queue;                          //顺序队类型定义

//队列初始化
void init_queue(sq_queue &qu)
{
    qu.front=qu.rear=0;             //队首指针与队尾指针重合，且指向0
}

//判断队列是否为空
int is_queue_empty(sq_queue qu)
{
    if(qu.front==qu.rear)           //无论队首指针与队尾指针的位置如何，只要二者重合，就表示队列为空
        return 1;
    else
        return 0;
}

//进队算法
int en_queue(sq_queue &qu,int x)
{
    //判断队列是否已满
    //队尾指针与队首指针仅差一个“距离”
    if((qu.rear+1)%max_size==qu.front)      
        return 0;
    //队尾指针指向上一次入队的元素
    //因此先移动指针，再加入元素
    qu.rear=(qu.rear+1)%max_size;  
    qu.data[qu.rear]=x;             //先移动指针，再存入元素
    return 1; 
}

//出队算法
int de_queue(sq_queue &qu,int &x)
{
    if(qu.front==qu.rear)           //队列为空，无法执行出队操作
        return 0;
    //front指针指向的是上一次出队的元素（已不在队列中）
    //因此需要先移动指针，再进行取出元素
    qu.front=(qu.front+1)%max_size;
    x=qu.data[qu.front];
    return 1;
}



int main()
{   
    sq_queue qu;

    init_queue(qu);                 //队列初始化

    //判断队列是否为空
    cout<<endl<<"before en_queue(): "<<endl;
    if(is_queue_empty(qu)==1)
        cout<<endl<<"the queue is empty! "<<endl;
    else
        cout<<endl<<"the queue is not empty! "<<endl;

    //入队操作
    en_queue(qu,999);
    en_queue(qu,888);
    en_queue(qu,666);
    en_queue(qu,233);

    //判断队列是否为空
    cout<<endl<<"after en_queue(): "<<endl;
    if(is_queue_empty(qu)==1)
        cout<<endl<<"the queue is empty! "<<endl;
    else
        cout<<endl<<"the queue is not empty! "<<endl;

    //出队操作
    int x;

    de_queue(qu,x);
    cout<<endl<<"the head of the queue is :"<<endl;
    cout<<x<<endl;

    de_queue(qu,x);
    cout<<endl<<"the head of the queue is :"<<endl;
    cout<<x<<endl;

    de_queue(qu,x);
    cout<<endl<<"the head of the queue is :"<<endl;
    cout<<x<<endl;

    de_queue(qu,x);
    cout<<endl<<"the head of the queue is :"<<endl;
    cout<<x<<endl;

    return 0;
}
