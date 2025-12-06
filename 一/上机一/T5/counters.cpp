#include <iostream>
#include <windows.h>
using namespace std;

class Counter {
public:
    int count; // 计数器值

    // 构造函数
    Counter(int initialValue = 0) : count(initialValue) {}

    // 增加计数器值
    void increment() { count++; }
    void decrement() { count--; }
    void increment(int value) { count += value; }
    void decrement(int value) { count -= value; }

    // 输出当前计数器值
    void display() { cout << "计数器值: " << count << endl; }
};

int main() {
    // 设置控制台为UTF-8编码，确保中文输入输出正常
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    // 从用户输入获取计数器初始值
    int initialValue;
    cout << "请输入计数器的初始值: ";
    cin >> initialValue;
    
    Counter c(initialValue);

    int addValue;
    cout << "请输入增加值: ";
    cin >> addValue;
    
    int diffValue;
    cout << "请输入减少值: ";
    cin >> diffValue;

    cout << "初始计数器值: " << c.count << endl;
    
    c.increment(addValue); // 增加计数器值
    c.display();           // 输出计数器值
    
    c.decrement(diffValue); // 减少计数器值
    c.display();           // 输出计数器值
    
    return 0;
}
