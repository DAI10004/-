#include <iostream>
#include <windows.h>
using namespace std;

class Time {
private:
    int hours;   // 小时
    int minutes; // 分钟
    int seconds; // 秒

public:
    // 构造函数
    Time(int h = 0, int m = 0, int s = 0) {
        hours = h;
        minutes = m;
        seconds = s;
        normalize(); // 标准化时间格式
    }

    // 标准化时间格式（处理进位和借位）
    void normalize() {
        // 处理秒的进位
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        } else if (seconds < 0) {
            minutes += seconds / 60 - (seconds % 60 != 0 ? 1 : 0);
            seconds = (seconds % 60 + 60) % 60;
        }

        // 处理分钟的进位
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        } else if (minutes < 0) {
            hours += minutes / 60 - (minutes % 60 != 0 ? 1 : 0);
            minutes = (minutes % 60 + 60) % 60;
        }

        // 处理小时的进位（24小时制）
        if (hours >= 24 || hours < 0) {
            hours = (hours % 24 + 24) % 24;
        }
    }

    // 前缀++运算符重载
    Time& operator++() {
        seconds++;
        normalize();
        return *this;
    }

    // 后缀++运算符重载
    Time operator++(int) {
        Time temp = *this;
        seconds++;
        normalize();
        return temp;
    }

    // 前缀--运算符重载
    Time& operator--() {
        seconds--;
        normalize();
        return *this;
    }

    // 后缀--运算符重载
    Time operator--(int) {
        Time temp = *this;
        seconds--;
        normalize();
        return temp;
    }

    // 显示时间
    void display() const {
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }
};

int main() {
    // 设置控制台UTF-8编码，解决中文输出乱码
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    // 创建时间对象
    Time t1(23, 59, 59);
    Time t2(0, 0, 0);

    cout << "初始时间 t1: ";
    t1.display();
    cout << "初始时间 t2: ";
    t2.display();

    // 测试++运算符
    cout << "\n测试++运算符：" << endl;
    cout << "t1++后: ";
    (t1++).display();
    cout << "t1现在: ";
    t1.display();

    cout << "++t2后: ";
    (++t2).display();

    // 测试--运算符
    cout << "\n测试--运算符：" << endl;
    cout << "t1--后: ";
    (t1--).display();
    cout << "t1现在: ";
    t1.display();

    cout << "--t2后: ";
    (--t2).display();

    // 测试边界情况
    Time t3(23, 59, 59);
    Time t4(0, 0, 0);
    cout << "\n测试边界情况：" << endl;
    cout << "t3(23:59:59)++: ";
    (++t3).display();
    cout << "t4(00:00:00)--: ";
    (--t4).display();

    return 0;
}