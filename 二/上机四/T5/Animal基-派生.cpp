#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

// 动物基类
class Animal {
protected:
    string gender, name; // 合并成员变量声明

public:
    // 构造函数（合并参数检查）
    Animal(string g, string n) : gender(g), name(n) {
        if (g.empty() || n.empty()) cout << "警告：动物性别或名称为空！" << endl;
    }
    // 虚析构函数
    virtual ~Animal() {}
    // 虚函数 - 动物叫声
    virtual void soar() const { cout << "动物发出声音" << endl; }
    // 虚函数 - 动物进食
    virtual void eat() const { cout << "动物进食" << endl; }
    // 获取动物信息的方法（合并到一行）
    string getInfo() const { return name + "(" + gender + ")"; }
};

// 老虎派生类
class Tiger : public Animal {
private:
    string huntingSkill;

public:
    // 构造函数（合并参数检查）
    Tiger(string g, string n, string skill) : Animal(g, n), huntingSkill(skill) {
        if (skill.empty()) { cout << "警告：老虎的捕猎技能未指定！" << endl; huntingSkill = "未知"; }
    }
    // 重写虚函数 - 老虎叫声
    virtual void soar() const override { cout << name << "(" << gender << ") 发出: 吼吼吼！" << endl; }
    // 重写虚函数 - 老虎进食
    virtual void eat() const override { cout << name << "(" << gender << ") 正在捕食猎物，展示" << huntingSkill << "技能" << endl; }
};

// 羊派生类
class Sheep : public Animal {
private:
    string woolColor;

public:
    // 构造函数（合并参数检查）
    Sheep(string g, string n, string color) : Animal(g, n), woolColor(color) {
        if (color.empty()) { cout << "警告：羊的毛色未指定！" << endl; woolColor = "白色"; }
    }
    // 重写虚函数 - 羊叫声
    virtual void soar() const override { cout << name << "(" << gender << ") 发出: 咩咩咩！" << endl; }
    // 重写虚函数 - 羊进食
    virtual void eat() const override { cout << name << "(" << gender << ") 正在吃草，它的羊毛是" << woolColor << "色的" << endl; }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "动物类继承与多态演示程序" << endl << "========================" << endl;
    try {
        // 创建派生类对象并使用基类指针数组存储
        Animal* animals[4] = { new Sheep("雌性", "小尾寒羊", "米黄"), new Tiger("雄性", "东北虎", "潜伏突袭"),
                             new Sheep("雄性", "美利奴羊", "洁白"), new Tiger("雌性", "孟加拉虎", "快速追击") };
        
        cout << "\n所有动物的信息与行为展示：" << endl << "-------------------------" << endl;
        for (int i = 0; i < 4; i++) {
            if (animals[i]) { // 简化空指针检查
                cout << "\n动物 " << (i + 1) << ": " << animals[i]->getInfo() << endl;
                cout << "叫声："; animals[i]->soar();
                cout << "进食："; animals[i]->eat();
                delete animals[i]; // 释放内存
            }
        }
        cout << "\n程序运行结束，展示了面向对象编程中的继承和多态特性。" << endl;
        cout << "使用基类指针成功调用了派生类的虚函数！" << endl;
    } catch (const exception& e) { cerr << "错误：程序运行出错 - " << e.what() << endl; return 1; }
    return 0;
}