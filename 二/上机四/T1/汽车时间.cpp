#include <iostream>
#include <Windows.h>
using namespace std;

// 基类：Car
class Car {
protected:
    double distance;  // 距离（英里）

public:
    // 构造函数
    Car(double dist = 0.0) : distance(dist) {}
    
    // 设置距离
    void setDistance(double dist) {
        distance = dist;
    }
    
    // 获取距离
    double getDistance() const {
        return distance;
    }
    
    // 虚函数：计算行驶时间（小时）
    virtual void travel_time() const {
        const double speed = 80.0;  // 速度：80英里/小时
        double time = distance / speed;
        cout << "Car行驶时间：" << time << " 小时（距离：" << distance << " 英里，速度：80英里/小时）" << endl;
    }
};

// 派生类：Truck
class Truck : public Car {
public:
    // 构造函数
    Truck(double dist = 0.0) : Car(dist) {}
    
    // 重写计算行驶时间函数
    void travel_time() const override {
        const double speed = 120.0;  // 速度：120千米/小时
        double time = distance / speed;
        cout << "Truck行驶时间：" << time << " 小时（距离：" << distance << " 千米，速度：120千米/小时）" << endl;
    }
};

int main() {
    // 设置控制台编码为UTF-8，确保中文正常显示
    SetConsoleOutputCP(CP_UTF8);
    
    // 创建Car对象（距离以英里为单位）
    Car car(240.0);  // 240英里
    
    // 创建Truck对象（距离以千米为单位）
    Truck truck(360.0);  // 360千米
    
    // 测试Car的travel_time方法
    cout << "===== 不同车型行驶时间计算 =====" << endl;
    car.travel_time();
    
    // 测试Truck的travel_time方法
    truck.travel_time();
    
    // 演示多态
    cout << "\n===== 多态演示 =====" << endl;
    Car* vehicles[2];
    vehicles[0] = &car;
    vehicles[1] = &truck;
    
    for (int i = 0; i < 2; i++) {
        vehicles[i]->travel_time();
    }
    
    return 0;
}