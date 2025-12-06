#include <iostream>
using namespace std;

// 复数类定义
class Complex {
private:
    double real;  // 实部
    double imag;  // 虚部

public:
    // 构造函数
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // 成员函数重载运算符+，实现复数加法
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // 成员函数重载运算符-，实现复数减法
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // 友元函数重载运算符*，实现复数乘法
    // 复数乘法公式：(a+bi)*(c+di) = (ac-bd) + (ad+bc)i
    friend Complex operator*(const Complex& c1, const Complex& c2);

    // 显示复数的方法
    void display() const {
        if (imag >= 0) {
            cout << real << " + " << imag << "i" << endl;
        } else {
            cout << real << " - " << -imag << "i" << endl;
        }
    }
};

// 友元函数实现复数乘法
Complex operator*(const Complex& c1, const Complex& c2) {
    double r = c1.real * c2.real - c1.imag * c2.imag;
    double i = c1.real * c2.imag + c1.imag * c2.real;
    return Complex(r, i);
}

// 主函数，测试复数类的运算符重载
int main() {
    // 创建复数对象
    Complex c1(3.0, 4.0);  // 3+4i
    Complex c2(1.0, 2.0);  // 1+2i
    Complex c3, c4, c5;

    // 测试加法运算
    c3 = c1 + c2;
    cout << "c1 = ";
    c1.display();
    cout << "c2 = ";
    c2.display();
    cout << "c1 + c2 = ";
    c3.display();

    // 测试减法运算
    c4 = c1 - c2;
    cout << "c1 - c2 = ";
    c4.display();

    // 测试乘法运算
    c5 = c1 * c2;
    cout << "c1 * c2 = ";
    c5.display();

    return 0;
}
