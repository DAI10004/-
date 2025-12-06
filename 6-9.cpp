#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

// Animal基类
class Animal {
protected:
    string gender; // 动物性别
    string name;   // 动物名称（可选，用于标识）

public:
    // 构造函数
    Animal(const string& g, const string& n = "") : gender(g), name(n) {}

    // 虚析构函数，确保正确释放派生类资源
    virtual ~Animal() {}

    // 虚函数：动物的叫声
    virtual void soar() const = 0; // 纯虚函数

    // 虚函数：动物的进食行为
    virtual void eat() const = 0;  // 纯虚函数

    // 获取性别信息
    string getGender() const {
        return gender;
    }

    // 获取名称
    string getName() const {
        return name;
    }
};

// Tiger派生类（老虎）
class Tiger : public Animal {
private:
    string habitat; // 栖息地信息

public:
    // 构造函数
    Tiger(const string& g, const string& n = "", const string& h = "森林") 
        : Animal(g, n), habitat(h) {}

    // 重写虚函数：老虎的叫声
    void soar() const override {
        cout << "老虎" << (name.empty() ? "" : " " + name) << "(" << gender << ")" 
             << " 咆哮：嗷呜！" << endl;
    }

    // 重写虚函数：老虎的进食行为
    void eat() const override {
        cout << "老虎" << (name.empty() ? "" : " " + name) 
             << " 捕食肉类" << endl;
    }
};

// Sheep派生类（羊）
class Sheep : public Animal {
private:
    string color; // 毛色信息

public:
    // 构造函数
    Sheep(const string& g, const string& n = "", const string& c = "白色") 
        : Animal(g, n), color(c) {}

    // 重写虚函数：羊的叫声
    void soar() const override {
        cout << color << "的羊" << (name.empty() ? "" : " " + name) << "(" << gender << ")" 
             << " 咩叫：咩咩~" << endl;
    }

    // 重写虚函数：羊的进食行为
    void eat() const override {
        cout << color << "的羊" << (name.empty() ? "" : " " + name) 
             << " 吃草" << endl;
    }
};

int main() {
    // 设置控制台UTF-8编码，解决中文输出乱码
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // 创建派生类对象（每个派生类创建两个对象）
    Tiger tiger1("雄性", "虎王");
    Tiger tiger2("雌性", "虎后");
    Sheep sheep1("雄性", "大山羊");
    Sheep sheep2("雌性", "小母羊");

    // 创建基类指针数组，打乱顺序存储对象
    Animal* animals[4];
    animals[0] = &sheep1;  // 羊先
    animals[1] = &tiger1;  // 虎
    animals[2] = &sheep2;  // 羊
    animals[3] = &tiger2;  // 虎后

    // 使用循环访问数组中的对象，调用虚函数
    cout << "===== 动物的叫声 =====" << endl;
    for (int i = 0; i < 4; i++) {
        animals[i]->soar();
    }

    cout << "\n===== 动物的进食行为 =====" << endl;
    for (int i = 0; i < 4; i++) {
        animals[i]->eat();
    }

    return 0;
}