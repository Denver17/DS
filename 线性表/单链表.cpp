
#include<iostream>
using namespace std;

//单链表结点定义
typedef struct LNode
{
    int data;               //data存放数据域
    struct LNode *next;     //指向后继结点的指针
}LNode;                     //定义单链表结点类型

//尾插法建立链表
//需要将数组a的元素放到链表中，n为数组a的规模
void create_list_r(LNode *&C,int a[],int n)     //需要修改C，因此使用引用类型
{
    LNode *s,*r;                                //s用来指向新申请的结点，r始终指向C的终端结点
    int i;
    C=(LNode *)malloc(sizeof(LNode));           //申请C的头结点空间
    C->next=NULL;
    r=C;                                        //r指向头结点，因为此时头结点就是终端结点
    for(i=0;i<n;i++)
    {
        s=(LNode *) malloc(sizeof(LNode));      //s指向新申请的结点
        s->data=a[i];                           //存放数据
        r->next=s;                              //尾插法将s放到链表尾
        r=r->next;                              //r需要指向链表的终端结点
    }
    r->next=NULL;
}


//头插法建立链表
void create_list_f(LNode *&C,int a[],int n)
{
    LNode *s;
    int i;
    C=(LNode *)malloc(sizeof(LNode));
    C->next=NULL;
    for(i=0;i<n;i++)
    {
        s=(LNode *)malloc(sizeof(LNode));
        s->data=a[i];
        //头插法关键步骤
        s->next=C->next;    //插入结点的next指向C的开始结点
        C->next=s;          //C的开始结点指向s
    }
}



int main()
{
    LNode *C;
    int a[10]={1,2,3,4,5,6,7,8,9,10};

    //尾插法建立链表
    create_list_r(C,a,10);
    LNode *temp;
    temp=C;
    cout<<"尾插法建立链表："<<endl;
    while(temp!=NULL)
    {
        if(temp!=C)
            cout<<"value "<<temp->data<<endl;
        temp=temp->next;
    }


    LNode *M;
    int b[10]={10,9,8,7,6,5,4,3,2,1};
    //create_list_f(M,b,10);
    create_list_f(M,a,10);
    temp=M;
    cout<<"头插法建立链表："<<endl;
    while(temp!=NULL)
    {
        if(temp!=M)
            cout<<"value "<<temp->data<<endl;
        temp=temp->next;
    }



    return 0;
}