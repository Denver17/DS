#include<iostream>
using namespace std;

//链栈的定义
typedef struct LNode
{
    int data;               //数据域
    struct LNode *next;     //指针域
}LNode;                     //链栈结点定义


//初始化栈
void init_stack(LNode*&lst) //lst会发生改变，使用引用型
{
    lst=(LNode*)malloc(sizeof(LNode));  //创造一个头结点
    lst->next=NULL;
}

//判断栈是否为空
int is_stack_empty(LNode *lst)
{
    if(lst->next==NULL)
        return 1;
    else
        return 0;
}


//进栈代码
//以队尾作为栈底
void push(LNode *lst,int x)             //lst本身并不改变，改变的只是其后的元素，因此不加引用符号
{
    LNode* p;                           
    p=(LNode*)malloc(sizeof(LNode));    //为进栈元素申请结点空间
    p->next=NULL;                       //良好的习惯

    //头插法
    p->data=x;
    p->next=lst->next;
    lst->next=p;
}

//出栈代码
//以队头作为栈顶
int pop(LNode *lst,int &x)             //pop()同理，但x要加
{
    LNode* p;
    if(lst->next==NULL)                 //栈空时无法出栈
        return 0;
    else
    {
        //删除队头元素
        p=lst->next;
        x=p->data;
        lst->next=p->next;
        free(p);
    }
    return 1;
}


int main()
{
    LNode* st;

    init_stack(st);             //对栈进行初始化
    
    cout<<endl<<"before push: "<<endl;
    if(is_stack_empty(st)==1)   //判断栈是否为空
        cout<<"the stack is empty! "<<endl;
    else
        cout<<"the stack is not empty! "<<endl;

    push(st,100);
    push(st,90);
    push(st,76);
    push(st,130);

    cout<<endl<<"after push: "<<endl;
    if(is_stack_empty(st)==1)   //判断栈是否为空
        cout<<"the stack is empty! "<<endl;
    else
        cout<<"the stack is not empty! "<<endl;
    
    int x;

    pop(st,x);
    cout<<"the value of the top is "<<endl;
    cout<<x<<endl;

    pop(st,x);
    cout<<"the value of the top is "<<endl;
    cout<<x<<endl;

    pop(st,x);
    cout<<"the value of the top is "<<endl;
    cout<<x<<endl;

    pop(st,x);
    cout<<"the value of the top is "<<endl;
    cout<<x<<endl;
    

    return 0;
}
