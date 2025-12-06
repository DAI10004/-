#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

// 基类：车辆
class Vehicle {
protected:
    string brand, model, color; // 合并成员变量声明
    int year;
    double price;

public:
    // 构造函数
    Vehicle(string brand = "未知", string model = "未知", int year = 2020, string color = "白色", double price = 0.0) 
        : brand(brand), model(model), year(year), color(color), price(price) {}
    
    // 获取和设置品牌
    void setBrand(string b) { brand = b; }
    string getBrand() const { return brand; }
    
    // 获取和设置型号
    void setModel(string m) { model = m; }
    string getModel() const { return model; }
    
    // 获取和设置年份
    void setYear(int y) { year = y; }
    int getYear() const { return year; }
    
    // 获取和设置颜色
    void setColor(string c) { color = c; }
    string getColor() const { return color; }
    
    // 获取和设置价格
    void setPrice(double p) { price = p; }
    double getPrice() const { return price; }
    
    // 显示车辆信息（虚函数）
    virtual void displayInfo() const { cout << "品牌: " << brand << "\n型号: " << model << "\n年份: " << year << "\n颜色: " << color << "\n价格: " << price << " 元" << endl; }
    
    // 车辆运行（虚函数）
    virtual void run() const { cout << brand << model << " 正在行驶" << endl; }
};

// 派生类：卡车
class Truck : public Vehicle {
private:
    double loadCapacity;
    string truckType;

public:
    // 构造函数
    Truck(string brand = "未知", string model = "未知", int year = 2020, string color = "白色", double price = 0.0, double loadCapacity = 0.0, string truckType = "轻型") 
        : Vehicle(brand, model, year, color, price), loadCapacity(loadCapacity), truckType(truckType) {}
    
    // 获取和设置载重能力
    void setLoadCapacity(double capacity) { loadCapacity = capacity; }
    double getLoadCapacity() const { return loadCapacity; }
    
    // 获取和设置货车类型
    void setTruckType(string type) { truckType = type; }
    string getTruckType() const { return truckType; }
    
    // 重写显示信息函数
    void displayInfo() const override { cout << "=== 卡车信息 ===" << endl; Vehicle::displayInfo(); cout << "载重能力: " << loadCapacity << " 吨" << "\n类型: " << truckType << endl; }
    
    // 重写运行函数
    void run() const override { cout << truckType << "卡车 " << brand << model << " 正在运输货物" << endl; }
    
    // 卡车特有功能：装载货物
    void loadCargo(double weight) const { cout << "装载 " << weight << " 吨货物" << (weight <= loadCapacity ? "，装载成功" : "，超载警告！") << endl; }
};

// 派生类：乘用车
class PassengerCar : public Vehicle {
protected:
    int passengerCapacity;

public:
    // 构造函数
    PassengerCar(string brand = "未知", string model = "未知", int year = 2020, string color = "白色", double price = 0.0, int passengerCapacity = 5) 
        : Vehicle(brand, model, year, color, price), passengerCapacity(passengerCapacity) {}
    
    // 获取和设置载客量
    void setPassengerCapacity(int capacity) { passengerCapacity = capacity; }
    int getPassengerCapacity() const { return passengerCapacity; }
    
    // 重写显示信息函数
    void displayInfo() const override { cout << "=== 乘用车信息 ===" << endl; Vehicle::displayInfo(); cout << "载客量: " << passengerCapacity << " 人" << endl; }
    
    // 重写运行函数
    void run() const override { cout << brand << model << " 搭载乘客行驶中" << endl; }
};

// 派生类：轿车
class Sedan : public PassengerCar {
private:
    string level;
    bool hasLeatherSeats;

public:
    // 构造函数
    Sedan(string brand = "未知", string model = "未知", int year = 2020, string color = "白色", double price = 0.0, int passengerCapacity = 5, string level = "紧凑型", bool hasLeatherSeats = false) 
        : PassengerCar(brand, model, year, color, price, passengerCapacity), level(level), hasLeatherSeats(hasLeatherSeats) {}
    
    // 获取和设置级别
    void setLevel(string l) { level = l; }
    string getLevel() const { return level; }
    
    // 获取和设置是否有真皮座椅
    void setLeatherSeats(bool has) { hasLeatherSeats = has; }
    bool getLeatherSeats() const { return hasLeatherSeats; }
    
    // 重写显示信息函数
    void displayInfo() const override { cout << "=== 轿车信息 ===" << endl; PassengerCar::displayInfo(); cout << "级别: " << level << "\n真皮座椅: " << (hasLeatherSeats ? "有" : "无") << endl; }
    
    // 轿车特有功能：自动驾驶
    void enableAutoDrive() const { cout << "已启用自动驾驶模式" << endl; }
};

// 派生类：面包车
class Minivan : public PassengerCar {
private:
    bool hasSlidingDoor;
    int luggageCapacity;

public:
    // 构造函数
    Minivan(string brand = "未知", string model = "未知", int year = 2020, string color = "白色", double price = 0.0, int passengerCapacity = 7, bool hasSlidingDoor = true, int luggageCapacity = 500) 
        : PassengerCar(brand, model, year, color, price, passengerCapacity), hasSlidingDoor(hasSlidingDoor), luggageCapacity(luggageCapacity) {}
    
    // 获取和设置是否有滑动门
    void setSlidingDoor(bool has) { hasSlidingDoor = has; }
    bool getSlidingDoor() const { return hasSlidingDoor; }
    
    // 获取和设置行李容量
    void setLuggageCapacity(int capacity) { luggageCapacity = capacity; }
    int getLuggageCapacity() const { return luggageCapacity; }
    
    // 重写显示信息函数
    void displayInfo() const override { cout << "=== 面包车信息 ===" << endl; PassengerCar::displayInfo(); cout << "滑动门: " << (hasSlidingDoor ? "有" : "无") << "\n行李容量: " << luggageCapacity << " 升" << endl; }
    
    // 面包车特有功能：调整座椅布局
    void adjustSeatsLayout() const { cout << "已调整座椅布局，增加行李空间" << endl; }
};

// 客车派生类：公共汽车
class Bus : public PassengerCar {
private:
    string busType;
    bool hasAirConditioning;

public:
    // 构造函数
    Bus(string brand = "未知", string model = "未知", int year = 2020, string color = "绿色", double price = 0.0, int passengerCapacity = 40, string busType = "城市公交", bool hasAirConditioning = true) 
        : PassengerCar(brand, model, year, color, price, passengerCapacity), busType(busType), hasAirConditioning(hasAirConditioning) {}
    
    // 设置公交类型
    void setBusType(string type) { busType = type; }
    string getBusType() const { return busType; }
    
    // 设置是否有空调
    void setAirConditioning(bool has) { hasAirConditioning = has; }
    bool getAirConditioning() const { return hasAirConditioning; }
    
    // 重写显示信息函数
    void displayInfo() const override { cout << "=== 公共汽车信息 ===" << endl; PassengerCar::displayInfo(); cout << "类型: " << busType << "\n空调: " << (hasAirConditioning ? "有" : "无") << endl; }
    
    // 公共汽车特有功能：报站
    void announceStation(string station) const { cout << "前方到站: " << station << " 请做好下车准备" << endl; }
};

// 主函数
int main() {
    // 设置控制台编码为UTF-8，确保中文正常显示
    SetConsoleOutputCP(CP_UTF8);
    // 创建各种车辆对象
    Truck truck("东风", "天龙", 2022, "红色", 250000.0, 15.0, "重型");
    Sedan sedan("宝马", "3系", 2023, "黑色", 350000.0, 5, "中型", true);
    Minivan minivan("本田", "奥德赛", 2023, "银色", 280000.0, 7, true, 630);
    Bus bus("宇通", "ZK6128", 2022, "绿色", 800000.0, 50, "城市公交", true);
    
    // 显示各种车辆信息
    cout << "\n===== 车辆继承体系演示 =====\n" << endl;
    
    truck.displayInfo(); cout << endl; truck.run(); truck.loadCargo(10.0); cout << endl;
    sedan.displayInfo(); cout << endl; sedan.run(); sedan.enableAutoDrive(); cout << endl;
    minivan.displayInfo(); cout << endl; minivan.run(); minivan.adjustSeatsLayout(); cout << endl;
    bus.displayInfo(); cout << endl; bus.run(); bus.announceStation("人民广场"); cout << endl;
    
    // 演示多态
    cout << "\n===== 多态演示 =====\n" << endl;
    Vehicle* vehicles[] = {&truck, &sedan, &minivan, &bus};
    
    for (int i = 0; i < 4; i++) { vehicles[i]->displayInfo(); vehicles[i]->run(); cout << endl; }
    
    return 0;
}