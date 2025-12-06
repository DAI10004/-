#include <iostream>
#include <cmath>  // 用于M_PI常量

// 抽象基类 Shape：定义形状的基本接口
class Shape {
public:
    // 纯虚函数 getArea()：计算面积
    virtual double getArea() const = 0;
    
    // 纯虚函数 getPerim()：计算周长
    virtual double getPerim() const = 0;
    
    // 虚析构函数：确保派生类对象正确销毁
    virtual ~Shape() {}
};

// 派生类 Rectangle：矩形
class Rectangle : public Shape {
private:
    double width;   // 宽度
    double height;  // 高度
    
public:
    // 构造函数：初始化Rectangle对象
    Rectangle(double w, double h) : width(w), height(h) {}
    
    // 实现getArea()：面积 = 宽度 * 高度
    double getArea() const override {
        return width * height;
    }
    
    // 实现getPerim()：周长 = 2 * (宽度 + 高度)
    double getPerim() const override {
        return 2 * (width + height);
    }
    
    // 显示函数：输出矩形信息
    void show() const {
        std::cout << "=== 矩形信息 ===" << std::endl;
        std::cout << "宽度：" << width << std::endl;
        std::cout << "高度：" << height << std::endl;
        std::cout << "面积：" << getArea() << std::endl;
        std::cout << "周长：" << getPerim() << std::endl;
    }
};

// 派生类 Circle：圆形
class Circle : public Shape {
private:
    double radius;  // 半径
    const double PI = M_PI;  // π常量
    
public:
    // 构造函数：初始化Circle对象
    Circle(double r) : radius(r) {}
    
    // 实现getArea()：面积 = π * 半径²
    double getArea() const override {
        return PI * radius * radius;
    }
    
    // 实现getPerim()：周长 = 2 * π * 半径
    double getPerim() const override {
        return 2 * PI * radius;
    }
    
    // 显示函数：输出圆形信息
    void show() const {
        std::cout << "=== 圆形信息 ===" << std::endl;
        std::cout << "半径：" << radius << std::endl;
        std::cout << "面积：" << getArea() << std::endl;
        std::cout << "周长：" << getPerim() << std::endl;
    }
};

// 主函数：测试各个类的功能
int main() {
    // 创建Rectangle对象：宽5，高3
    Rectangle myRectangle(5.0, 3.0);
    // 创建Circle对象：半径4
    Circle myCircle(4.0);
    
    // 调用显示函数
    myRectangle.show();
    std::cout << "\n";
    myCircle.show();
    
    return 0;
}