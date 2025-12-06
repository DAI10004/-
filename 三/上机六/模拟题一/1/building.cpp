#include <iostream>
#include <string>

// 基类 Building：存储楼房的基本信息
class Building {
protected:
    int floors;      // 楼层数
    int rooms;       // 房间数
    double area;     // 总平方米数
    
public:
    // 构造函数：初始化Building对象
    Building(int f, int r, double a) : floors(f), rooms(r), area(a) {}
    
    // 显示函数：输出Building的基本信息
    void show() const {
        std::cout << "楼层数：" << floors << std::endl;
        std::cout << "房间数：" << rooms << std::endl;
        std::cout << "总平方米数：" << area << "㎡" << std::endl;
    }
};

// 派生类 House：继承自Building，增加卧室和浴室信息
class House : public Building {
private:
    int bedrooms;    // 卧室数量
    int bathrooms;   // 浴室数量
    
public:
    // 构造函数：初始化House对象，调用基类构造函数
    House(int f, int r, double a, int bdr, int bth) 
        : Building(f, r, a), bedrooms(bdr), bathrooms(bth) {}
    
    // 显示函数：输出House的所有信息，包括基类信息
    void show() const {
        std::cout << "=== 住宅信息 ===" << std::endl;
        Building::show();  // 调用基类的show()函数
        std::cout << "卧室数量：" << bedrooms << std::endl;
        std::cout << "浴室数量：" << bathrooms << std::endl;
    }
};

// 派生类 Office：继承自Building，增加灭火器和电话信息
class Office : public Building {
private:
    int fireExtinguishers;  // 灭火器数目
    int phones;             // 电话数目
    
public:
    // 构造函数：初始化Office对象，调用基类构造函数
    Office(int f, int r, double a, int fe, int p) 
        : Building(f, r, a), fireExtinguishers(fe), phones(p) {}
    
    // 显示函数：输出Office的所有信息，包括基类信息
    void show() const {
        std::cout << "=== 办公楼信息 ===" << std::endl;
        Building::show();  // 调用基类的show()函数
        std::cout << "灭火器数目：" << fireExtinguishers << std::endl;
        std::cout << "电话数目：" << phones << std::endl;
    }
};

// 主函数：测试各个类的功能
int main() {
    // 创建House对象
    House myHouse(3, 8, 200.5, 4, 2);
    // 创建Office对象
    Office myOffice(10, 50, 1500.0, 20, 50);
    
    // 显示信息
    myHouse.show();
    std::cout << "\n";
    myOffice.show();
    
    return 0;
}