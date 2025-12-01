#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

// 哺乳动物基类
class Mammal {
protected:
    string name, gender; int age; // 合并成员变量声明

public:
    // 构造函数
    Mammal(string n = "", int a = 0, string g = "") : name(n), age(a), gender(g) {}
    virtual ~Mammal() {} // 虚析构函数
    
    // 合并getter/setter函数
    void setName(string n) { name = n; } string getName() const { return name; }
    void setAge(int a) { age = a; } int getAge() const { return age; }
    void setGender(string g) { gender = g; } string getGender() const { return gender; }
    
    // 虚函数：发声
    virtual void speak() const { cout << name << " (哺乳动物): 发出声音" << endl; }
    // 显示基本信息
    void displayInfo() const { cout << "名称: " << name << ", 年龄: " << age << ", 性别: " << gender << endl; }
};

// 人类派生类
class Human : public Mammal {
private:
    string occupation;

public:
    // 构造函数
    Human(string n = "", int a = 0, string g = "", string o = "") : Mammal(n, a, g), occupation(o) {}
    // 合并getter/setter函数
    void setOccupation(string o) { occupation = o; } string getOccupation() const { return occupation; }
    // 重写speak函数
    void speak() const override { cout << name << " (人类): 说 '你好! 我是一名" << occupation << "。'" << endl; }
    // 显示人类信息
    void displayInfo() const { Mammal::displayInfo(); cout << "职业: " << occupation << endl; }
};

// 狗类派生类
class Dog : public Mammal {
private:
    string breed;

public:
    // 构造函数
    Dog(string n = "", int a = 0, string g = "", string b = "") : Mammal(n, a, g), breed(b) {}
    // 合并getter/setter函数
    void setBreed(string b) { breed = b; } string getBreed() const { return breed; }
    // 重写speak函数
    void speak() const override { cout << name << " (" << breed << "狗): 汪汪汪!" << endl; }
    // 显示狗信息
    void displayInfo() const { Mammal::displayInfo(); cout << "品种: " << breed << endl; }
};

// 猫类派生类
class Cat : public Mammal {
private:
    string furColor;

public:
    // 构造函数
    Cat(string n = "", int a = 0, string g = "", string fc = "") : Mammal(n, a, g), furColor(fc) {}
    // 合并getter/setter函数
    void setFurColor(string fc) { furColor = fc; } string getFurColor() const { return furColor; }
    // 重写speak函数
    void speak() const override { cout << name << " (" << furColor << "猫): 喵喵喵!" << endl; }
    // 显示猫信息
    void displayInfo() const { Mammal::displayInfo(); cout << "毛色: " << furColor << endl; }
};

// 演示函数：通过基类指针调用speak()
void demonstratePolymorphism(const Mammal* mammal) { cout << "通过基类指针调用speak(): "; mammal->speak(); }

// 主函数
int main() {
    SetConsoleOutputCP(CP_UTF8);
    Mammal baseMammal("通用哺乳动物", 5, "雄性");
    Human person("张三", 30, "男", "工程师");
    Dog dog("旺财", 3, "公", "金毛");
    Cat cat("小白", 2, "母", "白色");
    
    cout << "===== 直接调用speak()函数 =====" << endl;
    cout << "直接调用基类对象: "; baseMammal.speak();
    cout << "直接调用人类对象: "; person.speak();
    cout << "直接调用狗对象: "; dog.speak();
    cout << "直接调用猫对象: "; cat.speak();
    
    cout << "\n===== 通过基类指针演示多态 =====" << endl;
    // 使用基类指针数组存储不同派生类对象的地址
    Mammal* mammals[4] = { &baseMammal, &person, &dog, &cat };
    
    // 通过基类指针调用speak()，展示多态
    for (int i = 0; i < 4; i++) {
        cout << "\n对象信息: " << endl; mammals[i]->displayInfo();
        cout << "使用基类指针调用speak(): "; mammals[i]->speak();
    }
    
    cout << "\n===== 演示函数中使用多态 =====" << endl;
    demonstratePolymorphism(&person); demonstratePolymorphism(&dog); demonstratePolymorphism(&cat);
    
    cout << "\n===== 总结 =====" << endl;
    cout << "1. 当使用派生类对象直接调用speak()时，调用的是派生类重写的版本" << endl;
    cout << "2. 当通过基类指针指向派生类对象并调用speak()时，\n   会根据对象的实际类型动态调用相应的函数，这就是多态" << endl;
    cout << "3. speak()函数在基类中声明为virtual，派生类中使用override关键字重写" << endl;
    
    return 0;
}