#include<iostream>
using namespace std;

#define max_size 10

typedef struct
{
    int data[max_size];         //共享栈的数据存储空间  
    int top_1;                  //一端的栈顶指针
    int top_2;                  //另一端的栈顶指针
}shared_stack;

//共享栈初始化
void init_stack(shared_stack &st)
{
    st.top_1=-1;               //一端在数组开始的前面
    st.top_2=max_size;         //另一端在数组结束的后面
}

//判断是否为空
int is_stack_empty(shared_stack st)
{
    //只有当两边的指针都指向各自为空的含义时，栈才为空
    if(st.top_1==-1&&st.top_2==max_size)
        return 1;
    else
        return 0;
}

//对栈1进行进栈操作
int push_1(shared_stack &st,int x)
{
    if(st.top_1+1==st.top_2)        //栈已满，不能进行入栈操作
        return 0;
    
    st.top_1++;                     //栈指针先加一
    st.data[st.top_1]=x;            //再加入元素
    return 1;
}

//对栈2进行进栈操作
int push_2(shared_stack &st,int x)
{
    if(st.top_1+1==st.top_2)        //栈已满，不能进行进栈操作
        return 0;
    
    st.top_2--;                     //栈指针先减一
    st.data[st.top_2]=x;            //再加入元素
    return 1;
}

//对栈1进行出栈操作
int pop_1(shared_stack &st,int &x)
{
    if(st.top_1==-1)                //栈1已空，不能进行出栈操作
        return 0;

    x=st.data[st.top_1];            //先将栈中元素赋值给x
    st.top_1--;                     //再移动栈指针
    return 1;
}

//对栈2进行出栈操作
int pop_2(shared_stack &st,int &x)
{
    if(st.top_2==max_size)          //栈2已空，不能进行出栈操作
        return 0;
    
    x=st.data[st.top_2];            //先将栈中元素赋值给x
    st.top_2++;                     //再移动栈指针
    return 1;
}


int main()
{
    shared_stack st;

    //对栈进行初始化
    init_stack(st);

    cout<<endl<<"before push(): "<<endl;
    if(1==is_stack_empty(st))
        cout<<endl<<"the stack is empty "<<endl;
    else
        cout<<endl<<"the stack is not empty "<<endl;


    //入栈操作
    push_1(st,1999);
    cout<<endl<<"after push(): "<<endl;
    if(1==is_stack_empty(st))
        cout<<endl<<"the stack is empty "<<endl;
    else
        cout<<endl<<"the stack is not empty "<<endl;

    push_2(st,7432);
    push_1(st,7923);
    push_2(st,2190);


    //出栈操作
    int x;
    pop_1(st,x);
    cout<<"the value of the top_1 is :"<<endl;
    cout<<x<<endl;

    pop_1(st,x);
    cout<<"the value of the top_1 is :"<<endl;
    cout<<x<<endl;

    pop_2(st,x);
    cout<<"the value of the top_2 is :"<<endl;
    cout<<x<<endl;

    pop_2(st,x);
    cout<<"the value of the top_2 is :"<<endl;
    cout<<x<<endl;


    return 0;
}
