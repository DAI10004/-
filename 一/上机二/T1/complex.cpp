#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Complex {
private:
    double real;  // 实部
    double imag;  // 虚部

public:
    // 构造函数
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // 获取实部
    double getReal() const { return real; }
    
    // 获取虚部
    double getImag() const { return imag; }

    // 友元函数：复数加法
    friend Complex operator+(const Complex& c1, const Complex& c2);
    
    // 友元函数：复数减法
    friend Complex operator-(const Complex& c1, const Complex& c2);
    
    // 友元函数：复数乘法
    friend Complex operator*(const Complex& c1, const Complex& c2);
    
    // 友元函数：复数输出
    friend ostream& operator<<(ostream& os, const Complex& c);
};

// 友元函数实现：复数加法
Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

// 友元函数实现：复数减法
Complex operator-(const Complex& c1, const Complex& c2) {
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

// 友元函数实现：复数乘法
// (a+bi)(c+di) = (ac-bd) + (ad+bc)i
Complex operator*(const Complex& c1, const Complex& c2) {
    return Complex(
        c1.real * c2.real - c1.imag * c2.imag,
        c1.real * c2.imag + c1.imag * c2.real
    );
}

// 友元函数实现：复数输出
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    if (c.imag > 0) {
        os << c.real << " + " << c.imag << "i";
    } else if (c.imag < 0) {
        os << c.real << " - " << -c.imag << "i";
    } else {
        os << c.real;
    }
    return os;
}

// 解析复数字符串函数
Complex parseComplex(const string& str) {
    double real = 0.0, imag = 0.0;
    
    // 查找虚数部分的位置
    size_t i_pos = str.find('i');
    if (i_pos != string::npos) {
        // 查找正负号位置，用于分离实部和虚部
        size_t plus_pos = str.find_last_of('+');
        size_t minus_pos = str.find_last_of('-');
        
        // 检查符号是否在i之前
        if (plus_pos != string::npos && plus_pos < i_pos) {
            // 有实部和正号虚部
            if (plus_pos > 0) {
                real = stod(str.substr(0, plus_pos));
            }
            string imag_str = str.substr(plus_pos + 1, i_pos - plus_pos - 1);
            if (imag_str.empty()) imag = 1.0;
            else imag = stod(imag_str);
        } else if (minus_pos != string::npos && minus_pos < i_pos) {
            // 有实部和负号虚部或只有负号虚部
            if (minus_pos == 0) {
                // 只有负号虚部
                string imag_str = str.substr(1, i_pos - 1);
                if (imag_str.empty()) imag = -1.0;
                else imag = -stod(imag_str);
            } else {
                // 有实部和负号虚部
                real = stod(str.substr(0, minus_pos));
                string imag_str = str.substr(minus_pos + 1, i_pos - minus_pos - 1);
                if (imag_str.empty()) imag = -1.0;
                else imag = -stod(imag_str);
            }
        } else {
            // 只有虚部，没有符号
            string imag_str = str.substr(0, i_pos);
            imag = stod(imag_str);
        }
    } else {
        // 没有虚部，整个字符串作为实部
        real = stod(str);
        imag = 0.0;
    }
    
    return Complex(real, imag);
}

int main() {
    // 设置控制台为UTF-8编码，确保中文输入输出正常
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    // 创建复数对象（从用户输入初始化）
    string input1, input2;
    cout << "请输入第一个复数(格式如: 10+4i 或 10 或 -3i): ";
    cin >> input1;
    
    cout << "请输入第二个复数(格式如: 10+4i 或 10 或 -3i): ";
    cin >> input2;
    
    // 解析复数
    Complex c1 = parseComplex(input1);
    Complex c2 = parseComplex(input2);
    
    // 输入运算符
    char op;
    cout << "请输入运算符(+、-、*): ";
    cin >> op;
    
    // 根据运算符执行相应的运算
    if (op == '+') {
        Complex result = c1 + c2;
        cout << "计算结果: " << c1 << " + " << c2 << " = " << result << endl;
    } else if (op == '-') {
        Complex result = c1 - c2;
        cout << "计算结果: " << c1 << " - " << c2 << " = " << result << endl;
    } else if (op == '*') {
        Complex result = c1 * c2;
        cout << "计算结果: " << c1 << " * " << c2 << " = " << result << endl;
    } else {
        cout << "错误：不支持的运算符！" << endl;
    }
    
    return 0;
}