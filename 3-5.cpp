#include<iostream>
#include<windows.h>
using namespace std;

class Time{
    int hour,minute,second;
public:
    Time(int h=0,int m=0,int s=0){
        hour=h;
        minute=m;
        second=s;
    }

    void setHour(int h){
        hour=h;
    }
    void setMinute(int m){
        minute=m;
    }
    void setSecond(int s){
        second=s;
    }
    void display(){
        cout<<hour<<":"<<minute<<":"<<second<<endl;
    }
};

int main(){
    // 设置控制台输入输出编码为UTF-8，解决中文乱码问题
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Time t1;
    Time t2(10,15,30);
    cout<<"t1对象的时间为：";
    t1.display();
    cout<<"t2对象的时间为：";
    t2.display();

    //修改t1对象的时分秒;
    t1.setHour(13);
    t1.setMinute(20);
    t1.setSecond(20);
    cout<<"修改后的t1对象的时间为：";
    t1.display();

    return 0;
}