#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

// 点类，用于表示位置
class Point {
private:
    double x;
    double y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void setPoint(double x, double y) { this->x = x; this->y = y; }

    double getX() const { return x; }
    double getY() const { return y; }

    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

// 形状类（基类）
class Shape {
protected:
    string color;
    Point position;

public:
    Shape(string color = "black", Point position = Point(0, 0)) 
        : color(color), position(position) {}
    
    virtual ~Shape() {}
    
    void setColor(string color) { this->color = color; }
    string getColor() const { return color; }
    
    void setPosition(Point position) { this->position = position; }
    Point getPosition() const { return position; }
    
    void move(double dx, double dy) {
        position.setPoint(position.getX() + dx, position.getY() + dy);
    }
    
    virtual double calculateArea() const = 0;
    virtual void display() const = 0;
};

// 圆形类
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius = 0, string color = "black", Point position = Point(0, 0)) 
        : Shape(color, position), radius(radius) {}
    
    void setRadius(double radius) { this->radius = radius; }
    double getRadius() const { return radius; }
    
    double calculateArea() const {
        return 3.14159 * radius * radius;
    }
    
    void display() const {
        cout << "Circle:" << endl;
        cout << "  Color: " << color << endl;
        cout << "  Center: ";
        position.display();
        cout << endl;
        cout << "  Radius: " << radius << endl;
        cout << "  Area: " << calculateArea() << endl;
    }
};

// 矩形类
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double width = 0, double height = 0, string color = "black", Point position = Point(0, 0)) 
        : Shape(color, position), width(width), height(height) {}
    
    void setDimensions(double width, double height) {
        this->width = width;
        this->height = height;
    }
    
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    
    double calculateArea() const {
        return width * height;
    }
    
    void display() const {
        cout << "Rectangle:" << endl;
        cout << "  Color: " << color << endl;
        cout << "  Position: ";
        position.display();
        cout << endl;
        cout << "  Width: " << width << endl;
        cout << "  Height: " << height << endl;
        cout << "  Area: " << calculateArea() << endl;
    }
};

// 三角形类
class Triangle : public Shape {
private:
    Point p1;
    Point p2;

public:
    Triangle(Point p0 = Point(0, 0), Point p1 = Point(0, 0), Point p2 = Point(0, 0), string color = "black") 
        : Shape(color, p0), p1(p1), p2(p2) {}
    
    double calculateArea() const {
        double x0 = position.getX(), y0 = position.getY();
        double x1 = p1.getX(), y1 = p1.getY();
        double x2 = p2.getX(), y2 = p2.getY();
        
        return 0.5 * abs((x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0));
    }
    
    void display() const {
        cout << "Triangle:" << endl;
        cout << "  Color: " << color << endl;
        cout << "  Point 0: ";
        position.display();
        cout << endl;
        cout << "  Point 1: ";
        p1.display();
        cout << endl;
        cout << "  Point 2: ";
        p2.display();
        cout << endl;
        cout << "  Area: " << calculateArea() << endl;
    }
};

// 椭圆形类
class Ellipse : public Shape {
private:
    double a; // 长半轴
    double b; // 短半轴

public:
    Ellipse(double a = 0, double b = 0, string color = "black", Point position = Point(0, 0)) 
        : Shape(color, position), a(a), b(b) {}
    
    double calculateArea() const {
        return 3.14159 * a * b;
    }
    
    void display() const {
        cout << "Ellipse:" << endl;
        cout << "  Color: " << color << endl;
        cout << "  Center: ";
        position.display();
        cout << endl;
        cout << "  Semi-major: " << a << endl;
        cout << "  Semi-minor: " << b << endl;
        cout << "  Area: " << calculateArea() << endl;
    }
};

// 主函数
int main() {
    // 创建不同形状
    Circle c(5, "red", Point(10, 10));
    Rectangle r(10, 6, "blue", Point(0, 0));
    Triangle t(Point(0, 0), Point(10, 0), Point(5, 10), "green");
    Ellipse e(8, 4, "yellow", Point(20, 20));
    
    // 创建形状指针数组
    vector<Shape*> shapes;
    shapes.push_back(&c);
    shapes.push_back(&r);
    shapes.push_back(&t);
    shapes.push_back(&e);
    
    // 显示所有形状信息
    cout << "Shape Inheritance Example" << endl;
    cout << "=========================" << endl;
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->display();
        cout << endl;
    }
    
    return 0;
}