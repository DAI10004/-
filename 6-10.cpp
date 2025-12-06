#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

// 图形抽象基类
class Shape {
public:
    // 虚析构函数
    virtual ~Shape() {}
    
    // 纯虚函数：计算面积
    virtual double getArea() const = 0;
    
    // 显示图形信息
    virtual void displayInfo() const = 0;
};

// 三角形类
class Triangle : public Shape {
private:
    double a, b, c; // 三角形的三边长
    
    // 检查三边是否能构成三角形
    bool isValid() const {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }
    
public:
    // 构造函数
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}
    
    // 计算三角形面积（使用海伦公式）
    double getArea() const override {
        if (!isValid()) {
            cout << "警告：输入的三边不能构成三角形！" << endl;
            return 0;
        }
        
        double s = (a + b + c) / 2; // 半周长
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    
    // 显示三角形信息
    void displayInfo() const override {
        cout << "三角形：边长 a = " << a << ", b = " << b << ", c = " << c << endl;
    }
};

// 正方形类
class Square : public Shape {
private:
    double side; // 正方形的边长
    
public:
    // 构造函数
    Square(double s) : side(s) {}
    
    // 计算正方形面积
    double getArea() const override {
        return side * side;
    }
    
    // 显示正方形信息
    void displayInfo() const override {
        cout << "正方形：边长 = " << side << endl;
    }
};

// 圆形类
class Circle : public Shape {
private:
    double radius; // 圆的半径
    
public:
    // 构造函数
    Circle(double r) : radius(r) {}
    
    // 计算圆形面积
    double getArea() const override {
        const double PI = 3.1415926535;
        return PI * radius * radius;
    }
    
    // 显示圆形信息
    void displayInfo() const override {
        cout << "圆形：半径 = " << radius << endl;
    }
};

int main() {
    // 设置控制台UTF-8编码，解决中文输出乱码
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    // 创建各种图形对象
    Shape* shapes[4];
    
    // 创建一个三角形（3, 4, 5）
    shapes[0] = new Triangle(3, 4, 5);
    
    // 创建一个正方形（边长6）
    shapes[1] = new Square(6);
    
    // 创建一个圆形（半径7）
    shapes[2] = new Circle(7);
    
    // 创建一个特殊三角形（等腰三角形）
    shapes[3] = new Triangle(5, 5, 8);
    
    // 使用多态计算并显示各图形的面积
    cout << "===== 图形面积计算 =====" << endl;
    for (int i = 0; i < 4; i++) {
        shapes[i]->displayInfo();
        cout << "面积：" << shapes[i]->getArea() << endl << endl;
        
        // 释放内存
        delete shapes[i];
    }
    
    return 0;
}