#include<iostream>
#include<string.h>
#include<windows.h>
using namespace std;

class Student{
    private:
        int num;
        char name[10];
        float math;
        float english;
        float computer;
    public:
        void set_stu_info(int n,char *ch,float m,float e,float c){
            num=n;
            strcpy(name,ch);
            math=m;
            english=e;
            computer=c;
        }
        float sum(){
            return math+english+computer;
        }
        float average(){
            return sum()/3;
        }
        int get_reg_num(){
            return num;
        }
        void print(){
            cout<<"学号："<<num<<endl;
            cout<<"姓名："<<name<<endl;
            cout<<"数学："<<math<<endl;
            cout<<"英语："<<english<<endl;
            cout<<"计算机："<<computer<<endl;
            cout<<"总分："<<sum()<<endl;
            cout<<"平均分："<<average()<<endl;
        }
};

int main(){
    // 设置控制台为UTF-8编码，解决中文乱码问题
    SetConsoleOutputCP(CP_UTF8);
    
    Student stu[50];
    int i,q,max=0,aver=0;
    char name[10];
    float m,e,c;

    int count=0;
    for(;;){
        cout<<"请输入学生的学号、姓名、数学成绩、英语成绩、计算机成绩：(若输入的学号为0则表示退出)"<<endl;
        cin>>q;
        if(q==0) break;
        cin>>name>>m>>e>>c;
        stu[count].set_stu_info(q,name,m,e,c);
        count++;
        float total = m + e + c;
        if(max<total) max=total;

        aver+=total;
    }
    cout<<"学生信息为："<<endl<<endl;

    for(i=0;i<count;i++){
        stu[i].print();
        cout<<endl;
    }
    cout<<"全班学生总成绩最高分为"<<max<<endl;
    cout<<"全班学生总平均分为"<<aver/count<<endl;
    cout<<"请输入要查的学生的学号："<<endl;
    cin>>q;
    for(i=0;i<count;i++){
        if(stu[i].get_reg_num()==q){
            stu[i].print();
            break;
        }
    }
    if(i==count) cout<<"查无此人"<<endl;
    return 0;
}