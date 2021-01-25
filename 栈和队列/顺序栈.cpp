#include<iostream>
using namespace std;

#define max_size 10

//顺序栈的定义
typedef struct 
{
    int data[max_size];     //存放栈中的元素
    int top;                //栈顶指针
}sq_stck;                   //顺序栈类型定义



//初始化栈
void init_stack(sq_stck &st)
{
    st.top=-1;              //指针置为-1即可
}

//判断栈空
int is_stack_empty(sq_stck st)
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}

//进栈代码
int push(sq_stck &st,int x)
{
    if(st.top==max_size-1)   //判断栈是否已满
        return 0;
    else
    {
        st.top++;           //初始时栈指针指向-1，因此先+1再赋值
        st.data[st.top]=x;
    }
    return 1;
}

//出栈代码
int pop(sq_stck &st,int &x)
{
    if(st.top==-1)          //若栈为空，则弹出失败
        return 0;
    else
    {
        x=st.data[st.top];  //先将元素赋值给x，再将指针-1，与进栈操作相反
        st.top--;
    }
    return 1;
}


int main()
{
    sq_stck st;             //定义栈
    
    init_stack(st);         //对栈进行初始化

    //判断栈是否为空
    cout<<"before push() :"<<endl;
    if(is_stack_empty(st)==1)
        cout<<"the stack is empty! "<<endl;
    else
        cout<<"the stack is not empty! "<<endl;

    //向栈中加入元素
    push(st,65);
    push(st,73);
    push(st,23);
    push(st,19);

    //再次判断栈是否为空
    cout<<"after push() :"<<endl;
    if(is_stack_empty(st)==1)
        cout<<"the stack is empty! "<<endl;
    else
        cout<<"the stack is not empty! "<<endl;

    //依次弹出栈中元素
    int x;
    pop(st,x);
    cout<<"the value of the top is :"<<endl;
    cout<<x<<endl;

    pop(st,x);
    cout<<"the value of the top is :"<<endl;
    cout<<x<<endl;

    pop(st,x);
    cout<<"the value of the top is :"<<endl;
    cout<<x<<endl;

    pop(st,x);
    cout<<"the value of the top is :"<<endl;
    cout<<x<<endl;

    return 0;
}
