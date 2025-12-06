#include <iostream>
#include <string>
using namespace std;

// 抽象类Vehicle的定义
class Vehicle {
protected:
    string name;  // 交通工具名称
    int speed;    // 速度

public:
    // 构造函数
    Vehicle(string n, int s) : name(n), speed(s) {}

    // 纯虚函数display，使Vehicle成为抽象类
    // 纯虚函数没有实现，必须在派生类中重写
    virtual void display() const = 0;

    // 虚析构函数，确保派生类对象能正确析构
    virtual ~Vehicle() {}
};

// 船类Boat，继承自Vehicle
class Boat : public Vehicle {
private:
    int capacity;  // 载客量

public:
    // 构造函数
    Boat(string n, int s, int c) : Vehicle(n, s), capacity(c) {}

    // 重写虚函数display，显示船的信息
    void display() const override {
        cout << "交通工具类型：船" << endl;
        cout << "名称：" << name << endl;
        cout << "速度：" << speed << " km/h" << endl;
        cout << "载客量：" << capacity << " 人" << endl;
    }
};

// 汽车类Automobile，继承自Vehicle
class Automobile : public Vehicle {
protected:
    int seats;  // 座位数（protected权限，派生类可访问）

public:
    // 构造函数
    Automobile(string n, int s, int se) : Vehicle(n, s), seats(se) {}

    // 重写虚函数display，显示汽车的信息
    void display() const override {
        cout << "交通工具类型：汽车" << endl;
        cout << "名称：" << name << endl;
        cout << "速度：" << speed << " km/h" << endl;
        cout << "座位数：" << seats << " 座" << endl;
    }
};

// 跑车类SportsCar，继承自Automobile
class SportsCar : public Automobile {
private:
    string engineType;  // 发动机类型

public:
    // 构造函数
    SportsCar(string n, int s, int se, string et) : Automobile(n, s, se), engineType(et) {}

    // 重写虚函数display，显示跑车的信息
    void display() const override {
        cout << "交通工具类型：跑车" << endl;
        cout << "名称：" << name << endl;
        cout << "速度：" << speed << " km/h" << endl;
        cout << "座位数：" << seats << " 座" << endl;
        cout << "发动机类型：" << engineType << endl;
    }
};

// 测试函数，体现多态性
// 接收基类指针，调用虚函数，根据实际对象类型执行不同的实现
void testPolymorphism(const Vehicle* vehicle) {
    vehicle->display();  // 动态绑定，调用实际对象的display方法
    cout << "------------------------" << endl;
}

// 主函数
int main() {
    // 创建不同类型的交通工具对象
    Boat boat("泰坦尼克号", 23, 2224);
    Automobile car("大众朗逸", 180, 5);
    SportsCar sportsCar("法拉利488", 330, 2, "V8涡轮增压");

    // 使用基类指针指向派生类对象，体现多态性
    Vehicle* vehicles[] = {&boat, &car, &sportsCar};

    // 调用测试函数，体现多态性
    cout << "多态性测试结果：" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < 3; i++) {
        testPolymorphism(vehicles[i]);
    }

    return 0;
}
