#include<iostream>
using namespace std;

#define max_size 100

//顺序表的结构体定义
typedef struct 
{
    int data[max_size];     //存放顺序表元素的数组
    int length;             //存放顺序表的长度
}sql_list;                  //顺序表类型的定义


//本函数返回元素的值为x的元素的位置
int find_elem(sql_list L,int x)
{
    int i;
    for(i=0;i<L.length;i++) //遍历顺序表中的元素
    {
        if(x==L.data[i])     //如果找到了一个元素大于x
        {
            return i;       //成功找到，返回其位置
        }
    }
    return -1;               //没有找到，返回-1
}

//本函数向顺序表中插入元素
//p代表要插入的位置，x代表要插入的元素的值
int insert_elem(sql_list &L,int p,int x)
{
    int i;
    //p = find_elem(L,x);                   //调用查找函数找到适合元素插入的位置
    if(p<0||p>L.length||L.length==max_size) //位置错误或者表长已经达到最大
        return 0;
    for(int i=L.length-1;i>p;i--)           //从后向前移动元素，防止元素覆盖
    {
        L.data[i+1]=L.data[i];
    }
    L.data[p]=x;                            //将x插入
    (L.length)++;                           //修改长度
    return 1;                               //插入成功
}


//该函数删除指定位置的元素
//p代表待删除元素的位置，e保留删除元素的值
int del_elem(sql_list &L,int p,int &e)
{
    int i;
    if(p<0||p>L.length-1)                   //插入位置有误，返回0
    return 0;
    e=L.data[p];                            //待删除元素的值保存到e
    for(i=p;i<L.length-1;i++)               //为防止元素覆盖，从前向后移动
    {
        L.data[i]=L.data[i+1];
    }
    (L.length)--;                           //表长修改
    return 1;                               //删除成功
}

//该函数初始化了顺序表
void init_list(sql_list &L)                 //L本身发生改变，故使用引用型
{
    L.length=0;
}

//该函数按位置查找元素
//其中p代表元素位置，e保留p位置上的元素
int get_elem(sql_list L,int p,int &e)
{
    if(p<0||p>L.length-1)                   //p的值越界，返回0
        return 0;
    e=L.data[p];
    return 1;
}


int main()
{
    sql_list L;
    init_list(L);
    
    for(int i=0;i<10;i++)                   //插入元素0~9
    {
        insert_elem(L,i,i);
    }
    for(int i=0;i<10;i++)                   //打印
    {
        cout<<L.data[i]<<endl;
    }

    //按值查找元素位置
    int position=find_elem(L,4);           
    cout<<"the position of value 4 is : "<<position<<endl;

    //删除操作
    int temp;
    del_elem(L,6,temp);                     //删除位置为6的元素
    cout<<"we delete the elem whose value is : "<<temp<<endl;
    for(int i=0;i<L.length;i++)
        cout<<L.data[i]<<endl;

    //按位查找元素
    get_elem(L,8,temp);
    cout<<"we get the elem whose positon is "<<8<<endl;
    cout<<"and its value is "<<temp<<endl;


    return 0;
}

