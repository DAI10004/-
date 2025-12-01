// 二维向量类Vector - 表示平面中的向量，包含坐标x和y
#include <iostream>

// 使用标准命名空间以简化代码
using namespace std;

class Vector {
public:
    // 数据成员：向量的x和y坐标
    float x, y;
    
    // 默认构造函数 - 初始化为零向量
    Vector() : x(0.0), y(0.0) {}
    
    // 带参数构造函数 - 直接初始化坐标
    Vector(float x, float y) : x(x), y(y) {}
    
    // 输入初始化函数 - 通过用户输入设置向量坐标
    void input() {
        cout << "请输入x坐标: ";
        cin >> x;
        cout << "请输入y坐标: ";
        cin >> y;
    }
    
    // 友元函数声明
    friend Vector operator+(const Vector& a, const Vector& b);
    friend ostream& operator<<(ostream& out, const Vector& v);
};

// 重载+运算符 - 向量加法
Vector operator+(const Vector& a, const Vector& b) {
    return Vector(a.x + b.x, a.y + b.y);
}

// 重载<<运算符 - 向量输出格式
ostream& operator<<(ostream& out, const Vector& v) {
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

int main() {
    // 使用C++标准方式设置UTF-8编码
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 测试默认构造函数
    cout << "===== 测试默认构造函数 =====" << endl;
    Vector c;
    cout << "默认构造的向量c: " << c << endl;
    
    // 测试输入初始化方式
    cout << "\n===== 测试输入初始化方式 =====" << endl;
    Vector d;
    cout << "请输入向量d的坐标：" << endl;
    d.input();
    cout << "通过输入初始化的向量d: " << d << endl;
    
    // 测试带参数构造函数和运算符重载
    cout << "\n===== 测试带参数构造函数和运算符 =====" << endl;
    Vector a(1, 2), b(3, 4);
    cout << "向量a: " << a << endl;
    cout << "向量b: " << b << endl;
    cout << "向量a + 向量b = " << a + b << endl;
    
    return 0;
}