#include <iostream>
#include <string>

// 基类 Car：存储距离和计算行驶时间
class Car {
protected:
    double distance;   // 两点间的距离
    const double speed = 80.0;  // 速度：英里/小时
    
public:
    // 构造函数：初始化Car对象
    Car(double d) : distance(d) {}
    
    // 虚函数 travel_time()：计算并显示行驶时间
    virtual void travel_time() const {
        double time = distance / speed;  // 时间 = 距离 / 速度
        std::cout << "=== 汽车行驶信息 ===" << std::endl;
        std::cout << "距离：" << distance << " 英里" << std::endl;
        std::cout << "速度：" << speed << " 英里/小时" << std::endl;
        std::cout << "行驶时间：" << time << " 小时" << std::endl;
    }
};

// 派生类 Truck：继承自Car，使用千米和不同速度
class Truck : public Car {
private:
    const double truck_speed = 120.0;  // 卡车速度：千米/小时
    
public:
    // 构造函数：初始化Truck对象
    Truck(double d) : Car(d) {}  // 注意：这里的d是千米，基类的distance存储的是千米值
    
    // 重写虚函数 travel_time()：使用千米和卡车速度计算时间
    void travel_time() const override {
        double time = distance / truck_speed;  // 时间 = 距离 / 速度
        std::cout << "=== 卡车行驶信息 ===" << std::endl;
        std::cout << "距离：" << distance << " 千米" << std::endl;
        std::cout << "速度：" << truck_speed << " 千米/小时" << std::endl;
        std::cout << "行驶时间：" << time << " 小时" << std::endl;
    }
};

// 主函数：测试各个类的功能
int main() {
    // 创建Car对象：距离160英里
    Car myCar(160.0);
    // 创建Truck对象：距离240千米
    Truck myTruck(240.0);
    
    // 调用各自的travel_time()函数
    myCar.travel_time();
    std::cout << "\n";
    myTruck.travel_time();
    
    return 0;
}