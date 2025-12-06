#include <iostream>
#include <cmath>
#include <Windows.h>
#include <vector>
using namespace std;

// 设置颜色的函数
void setColor(int color) { HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(hConsole, color); }

// 图形抽象基类
class Shape {
protected:
    int x, y, color; // 合并成员变量声明
    string name;

public:
    // 构造函数（合并参数检查）
    Shape(int x = 0, int y = 0, int color = 7) : x(x), y(y), color(color) {
        if (color < 0 || color > 255) { cout << "警告：颜色值超出有效范围，已设置为默认值！" << endl; this->color = 7; }
    }
    virtual ~Shape() {} // 虚析构函数
    virtual double calculateArea() const = 0; // 纯虚函数
    virtual void draw() const = 0;
    // 显示图形信息
    virtual void displayInfo() const { setColor(color); cout << name << " - 位置: (" << x << ", " << y << ")，面积: " << calculateArea() << endl; setColor(7); }
    string getName() const { return name; }
};

// 三角形派生类
class Triangle : public Shape {
private:
    double a, b, c;

public:
    // 构造函数
    Triangle(int x = 0, int y = 0, double a = 0, double b = 0, double c = 0, int color = 10) : Shape(x, y, color), a(a), b(b), c(c) {
        name = "三角形"; if (a <= 0 || b <= 0 || c <= 0) { cout << "警告：三角形边长必须为正数！" << endl; this->a = this->b = this->c = 0; }
    }
    // 计算面积（海伦公式）
    double calculateArea() const override {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) return 0;
        double s = (a + b + c) / 2; return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    // 绘制函数
    void draw() const override {
        setColor(color); cout << "在位置 (" << x << ", " << y << ") 绘制三角形，三边长: " << a << ", " << b << ", " << c << endl;
        int height = static_cast<int>(a);
        if (height > 0) {
            for (int i = 1; i <= height; i++) { for (int j = 0; j < height - i; j++) cout << " "; for (int j = 0; j < 2 * i - 1; j++) cout << "*"; cout << endl; }
        } else { cout << "无法绘制：三角形无效" << endl; }
        setColor(7);
    }
    // 显示信息
    void displayInfo() const override {
        Shape::displayInfo();
        cout << "   三边长: " << a << ", " << b << ", " << c << "   " << ((a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a) ? "(有效三角形)" : "(无效三角形)") << endl;
    }
};

// 正方形派生类
class Square : public Shape {
private:
    double side;

public:
    // 构造函数
    Square(int x = 0, int y = 0, double side = 0, int color = 11) : Shape(x, y, color), side(side) {
        name = "正方形"; if (side <= 0) { cout << "警告：正方形边长必须为正数！" << endl; this->side = 0; }
        else if (side > 50) { cout << "警告：正方形边长过大，可能无法完整显示！" << endl; }
    }
    // 计算面积
    double calculateArea() const override { return side * side; }
    // 绘制函数
    void draw() const override {
        setColor(color); cout << "在位置 (" << x << ", " << y << ") 绘制正方形，边长: " << side << endl;
        int size = static_cast<int>(side);
        if (size > 0 && size <= 50) {
            for (int i = 0; i < size; i++) { for (int j = 0; j < size; j++) cout << "■ "; cout << endl; }
        } else if (size > 0) { cout << "正方形过大，无法在控制台中完整显示" << endl; }
        else { cout << "无法绘制：正方形无效" << endl; }
        setColor(7);
    }
    // 显示信息
    void displayInfo() const override { Shape::displayInfo(); cout << "   边长: " << side << endl; }
};

// 圆形派生类
class Circle : public Shape {
private:
    double radius;

public:
    // 构造函数
    Circle(int x = 0, int y = 0, double radius = 0, int color = 12) : Shape(x, y, color), radius(radius) {
        name = "圆形"; if (radius <= 0) { cout << "警告：圆半径必须为正数！" << endl; this->radius = 0; }
        else if (radius > 10) { cout << "警告：圆半径过大，可能无法完整显示！" << endl; }
    }
    // 计算面积
    double calculateArea() const override { return M_PI * radius * radius; }
    // 绘制函数
    void draw() const override {
        setColor(color); cout << "在位置 (" << x << ", " << y << ") 绘制圆形，半径: " << radius << endl;
        int r = static_cast<int>(radius);
        if (r > 0 && r <= 10) {
            for (int i = -r; i <= r; i++) {
                for (int j = -r; j <= r; j++) {
                    double distance = sqrt(i * i + j * j);
                    cout << (distance < radius - 0.5 ? "● " : (distance < radius + 0.5 ? "○ " : "  "));
                }
                cout << endl;
            }
        } else if (r > 0) { cout << "圆过大，无法在控制台中完整显示" << endl; }
        else { cout << "无法绘制：圆无效" << endl; }
        setColor(7);
    }
    // 显示信息
    void displayInfo() const override { Shape::displayInfo(); cout << "   半径: " << radius << endl; }
};

int main() {
    try {
        SetConsoleOutputCP(CP_UTF8);
        cout << "图形绘制与面积计算程序" << endl << "====================" << endl << endl;
        // 创建图形对象
        Triangle triangle(10, 5, 5, 5, 6); Square square(20, 10, 4); Circle circle(30, 15, 3);
        // 创建图形指针数组
        vector<Shape*> shapes = { &triangle, &square, &circle };
        
        // 显示所有图形信息
        cout << "所有图形信息：" << endl << "---------------" << endl;
        for (const auto& shape : shapes) { if (shape) { shape->displayInfo(); cout << endl; } }
        
        // 计算总面积
        double totalArea = 0; for (const auto& shape : shapes) { if (shape) totalArea += shape->calculateArea(); }
        cout << "所有图形总面积: " << totalArea << endl << endl;
        
        // 绘制所有图形
        cout << "图形绘制效果：" << endl << "---------------" << endl;
        for (const auto& shape : shapes) {
            if (shape) { cout << "\n绘制" << shape->getName() << "：" << endl; shape->draw(); cout << endl; }
        }
        cout << "\n程序运行结束！" << endl;
    } catch (const exception& e) { cerr << "错误：程序运行出错 - " << e.what() << endl; return 1; }
    catch (...) { cerr << "错误：程序发生未知异常！" << endl; return 1; }
    return 0;
}