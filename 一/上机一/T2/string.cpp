#include <iostream>
#include <cstring>
#include <windows.h>  
using namespace std;

class String {
private:
    char content[100];  // 字符串内容
    int length;         // 字符串长度

public:
    // 构造函数初始化
    String(const char* str = "") {
        strcpy(content, str);
        length = strlen(content);  // 计算字符串长度
    }

    // 显示字符串
    void display() {
        cout << "字符串内容: " << content << std::endl;
    }

    // 求字符串长度
    int getLength() {
        return length;
    }

    // 连接另一个字符串
    void concatenate(const char* str) {
        if (length + strlen(str) < 100) {  // 确保不会溢出
            strcat(content, str);
            length = strlen(content);  // 更新长度
        } else {
            cout << "警告：连接后的字符串过长，无法完全连接！" << endl;
        }
    }
};

int main() {
    // 设置控制台为UTF-8编码，确保中文输入输出正常
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    // 创建字符串对象（从用户输入初始化）
    char inputStr[100];
    cout << "请输入一个字符串: ";
    cin.getline(inputStr, 100);
    String s1(inputStr);

    
    // 显示原始字符串及其长度
    s1.display();
    cout << "字符串长度: " << s1.getLength() << endl;

  // 连接另一个字符串
    cout << "请输入要连接的字符串: ";
    cin.getline(inputStr, 100);
    s1.concatenate(inputStr);

  // 显示连接后的字符串及其长度
    cout << "\n连接后的字符串：" << endl;
    s1.display();
    cout << "字符串长度: " << s1.getLength() << endl;   

    return 0;
}
