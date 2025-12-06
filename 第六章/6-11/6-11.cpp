#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// 学生类定义
class Student {
private:
    string name;           // 姓名
    double score1;         // 第一门课程成绩
    double score2;         // 第二门课程成绩
    double score3;         // 第三门课程成绩

public:
    // 构造函数
    Student(const string& n = "", double s1 = 0, double s2 = 0, double s3 = 0) :
        name(n), score1(s1), score2(s2), score3(s3) {}

    // 获取姓名
    string getName() const {
        return name;
    }

    // 设置成绩
    void setScores(double s1, double s2, double s3) {
        score1 = s1;
        score2 = s2;
        score3 = s3;
    }

    // 获取成绩
    double getScore1() const { return score1; }
    double getScore2() const { return score2; }
    double getScore3() const { return score3; }

    // 重载加法运算符，用于累加成绩
    Student operator+(const Student& other) const {
        // 创建一个临时对象，累加两门课程的成绩
        // 姓名可以设为"Total"表示总和
        return Student("Total", 
                      this->score1 + other.score1,
                      this->score2 + other.score2,
                      this->score3 + other.score3);
    }

    // 计算并显示各门课程的平均分
    void displayAverage(int studentCount) const {
        cout << "======== 平均分统计 ========" << endl;
        cout << "第一门课程平均分: " << score1 / studentCount << endl;
        cout << "第二门课程平均分: " << score2 / studentCount << endl;
        cout << "第三门课程平均分: " << score3 / studentCount << endl;
        cout << "============================" << endl;
    }

    // 显示学生信息
    void display() const {
        cout << "姓名: " << name << endl;
        cout << "成绩1: " << score1 << endl;
        cout << "成绩2: " << score2 << endl;
        cout << "成绩3: " << score3 << endl;
        cout << "----------------------------" << endl;
    }
};

int main() {
    // 设置控制台编码为UTF-8，确保中文正常显示
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int studentCount; // 学生数量
    cout << "请输入学生数量: ";
    cin >> studentCount;

    // 创建学生对象数组
    Student* students = new Student[studentCount];
    Student totalScores; // 用于存储总分

    // 输入每个学生的信息
    for (int i = 0; i < studentCount; i++) {
        string name;
        double s1, s2, s3;
        
        cout << "\n请输入第" << (i + 1) << "个学生的信息:" << endl;
        cout << "姓名: ";
        cin >> name;
        cout << "成绩1: ";
        cin >> s1;
        cout << "成绩2: ";
        cin >> s2;
        cout << "成绩3: ";
        cin >> s3;
        
        students[i] = Student(name, s1, s2, s3);
        
        // 使用重载的加法运算符累加成绩
        totalScores = totalScores + students[i];
    }

    // 显示所有学生的信息
    cout << "\n======== 学生信息列表 ========" << endl;
    for (int i = 0; i < studentCount; i++) {
        students[i].display();
    }

    // 显示总分
    cout << "\n======== 总分统计 ========" << endl;
    cout << "成绩1总分: " << totalScores.getScore1() << endl;
    cout << "成绩2总分: " << totalScores.getScore2() << endl;
    cout << "成绩3总分: " << totalScores.getScore3() << endl;

    // 计算并显示平均分
    totalScores.displayAverage(studentCount);

    // 释放动态分配的内存
    delete[] students;

    return 0;
}