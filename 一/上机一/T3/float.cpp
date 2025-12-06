#include <iostream>
#include <windows.h>
using namespace std;


// 定义复数类
class Complex {
private:
    double real;   // 复数的实部
    double imag;   // 复数的虚部

public:
    // 构造函数
    //设置默认构造的初始值
    Complex(double r = 10.0, double i = 4.0) : real(r), imag(i) {
        cout << "构造函数被调用: " << real << " + " << imag << "i" << endl;
    }

    // 拷贝构造函数
    Complex(const Complex& c) : real(c.real), imag(c.imag) {
        cout << "拷贝构造函数被调用: " << real << " + " << imag << "i" << endl;
    }

    // 显示复数的值
    void display() {
        if (imag > 0) {
            cout << real << " + " << imag << "i" << endl;
        } else if (imag < 0) {
            cout << real << " - " << -imag << "i" << endl;
        } else {
            cout << real << endl;
        }
    }

    // 获取实部
    double getReal() const {
        return real;
    }

    // 获取虚部
    double getImag() const {
        return imag;
    }
};

int main() {
    // 设置控制台为UTF-8编码，确保中文输入输出正常
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    // 使用构造函数创建复数对象（从用户输入初始化）
    double realPart, imagPart;
    cout << "请输入复数c1的实部: ";
    cin >> realPart;
    cout << "请输入复数c1的虚部: ";
    cin >> imagPart;
    
    Complex c1(realPart, imagPart);
    cout << "复数c1的值为: ";
    c1.display();

    // 使用默认构造函数创建复数对象
    Complex c2;
    cout << "复数c2的值为: ";
    c2.display();

    // 使用拷贝构造函数创建复数对象
    Complex c3(c1);
    cout << "复数c3的值为: ";       
    c3.display();

    return 0;
}
