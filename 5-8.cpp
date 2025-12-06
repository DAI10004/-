#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

// 基类：人员类
class Person {
private:
    string name;        // 姓名
    int age;            // 年龄
    string gender;      // 性别
    string id;          // 唯一标识号

public:
    // 构造函数
    Person(const string& n = "", int a = 0, const string& g = "", const string& i = "") :
        name(n), age(a), gender(g), id(i) {}

    // 析构函数
    virtual ~Person() {}

    // 设置属性的方法
    void setName(const string& n) { name = n; }
    void setAge(int a) { age = a; }
    void setGender(const string& g) { gender = g; }
    void setId(const string& i) { id = i; }

    // 获取属性的方法
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }
    string getId() const { return id; }

    // 显示基本信息的虚函数
    virtual void displayInfo() const {
        cout << "姓名: " << name << endl;
        cout << "年龄: " << age << endl;
        cout << "性别: " << gender << endl;
        cout << "ID: " << id << endl;
    }

    // 虚函数，每个派生类可以重写
    virtual string getType() const {
        return "人员"; // 基类默认类型
    }
};

// 派生类：学生类
class Student : public Person {
private:
    string studentId;   // 学号
    string className;   // 班级
    double gpa;         // 平均成绩

public:
    // 构造函数
    Student(const string& n = "", int a = 0, const string& g = "", const string& i = "",
            const string& sid = "", const string& cn = "", double avg = 0.0) :
        Person(n, a, g, i), studentId(sid), className(cn), gpa(avg) {}

    // 设置特有属性的方法
    void setStudentId(const string& sid) { studentId = sid; }
    void setClassName(const string& cn) { className = cn; }
    void setGPA(double avg) { gpa = avg; }

    // 获取特有属性的方法
    string getStudentId() const { return studentId; }
    string getClassName() const { return className; }
    double getGPA() const { return gpa; }

    // 重写显示信息的方法
    virtual void displayInfo() const override {
        cout << "===== 学生信息 =====" << endl;
        Person::displayInfo(); // 调用基类方法显示共同信息
        cout << "学号: " << studentId << endl;
        cout << "班级: " << className << endl;
        cout << "平均成绩: " << gpa << endl;
        cout << "===================" << endl;
    }

    // 重写获取类型的方法
    virtual string getType() const override {
        return "学生"; // 返回类型为学生
    }

    // 学生特有方法：选课
    void enrollCourse(const string& courseName) {
        cout << getName() << " 已选课程: " << courseName << endl;
    }
};

// 派生类：教师类
class Teacher : public Person {
private:
    string teacherId;   // 教师编号
    string department;  // 所属部门
    string title;       // 职称
    double salary;      // 薪资

public:
    // 构造函数
    Teacher(const string& n = "", int a = 0, const string& g = "", const string& i = "",
            const string& tid = "", const string& dept = "", const string& ttl = "", double sal = 0.0) :
        Person(n, a, g, i), teacherId(tid), department(dept), title(ttl), salary(sal) {}

    // 设置特有属性的方法
    void setTeacherId(const string& tid) { teacherId = tid; }
    void setDepartment(const string& dept) { department = dept; }
    void setTitle(const string& ttl) { title = ttl; }
    void setSalary(double sal) { salary = sal; }

    // 获取特有属性的方法
    string getTeacherId() const { return teacherId; }
    string getDepartment() const { return department; }
    string getTitle() const { return title; }
    double getSalary() const { return salary; }

    // 重写显示信息的方法
    virtual void displayInfo() const override {
        cout << "===== 教师信息 =====" << endl;
        Person::displayInfo(); // 调用基类方法显示共同信息
        cout << "教师编号: " << teacherId << endl;
        cout << "所属部门: " << department << endl;
        cout << "职称: " << title << endl;
        cout << "薪资: " << salary << endl;
        cout << "===================" << endl;
    }

    // 重写获取类型的方法
    virtual string getType() const override {
        return "教师"; // 返回类型为教师
    }

    // 教师特有方法：授课
    void teachCourse(const string& courseName) {
        cout << getName() << " 正在教授课程: " << courseName << endl;
    }
};

// 派生类：职员类
class Staff : public Person {
private:
    string staffId;     // 职员编号
    string position;    // 职位
    string department;  // 所属部门
    double salary;      // 薪资

public:
    // 构造函数
    Staff(const string& n = "", int a = 0, const string& g = "", const string& i = "",
          const string& sid = "", const string& pos = "", const string& dept = "", double sal = 0.0) :
        Person(n, a, g, i), staffId(sid), position(pos), department(dept), salary(sal) {}

    // 设置特有属性的方法
    void setStaffId(const string& sid) { staffId = sid; }
    void setPosition(const string& pos) { position = pos; }
    void setDepartment(const string& dept) { department = dept; }
    void setSalary(double sal) { salary = sal; }

    // 获取特有属性的方法
    string getStaffId() const { return staffId; }
    string getPosition() const { return position; }
    string getDepartment() const { return department; }
    double getSalary() const { return salary; }

    // 重写显示信息的方法
    virtual void displayInfo() const override {
        cout << "===== 职员信息 =====" << endl;
        Person::displayInfo(); // 调用基类方法显示共同信息
        cout << "职员编号: " << staffId << endl;
        cout << "职位: " << position << endl;
        cout << "所属部门: " << department << endl;
        cout << "薪资: " << salary << endl;
        cout << "===================" << endl;
    }

    // 重写获取类型的方法
    virtual string getType() const override {
        return "职员"; // 返回类型为职员
    }

    // 职员特有方法：处理工作
    void handleTask(const string& taskName) {
        cout << getName() << " 正在处理任务: " << taskName << endl;
    }
};

// 大学类，用于管理所有人员
class University {
private:
    string name;                    // 大学名称
    vector<Person*> personnel;      // 人员集合

public:
    // 构造函数
    University(const string& n = "") : name(n) {}

    // 析构函数，释放动态分配的内存
    ~University() {
        for (auto person : personnel) {
            delete person;
        }
        personnel.clear();
    }

    // 添加人员
    void addPerson(Person* person) {
        if (person) {
            personnel.push_back(person);
            cout << "成功添加" << person->getType() << "：" << person->getName() << endl;
        }
    }

    // 显示所有人员信息
    void displayAllPersonnel() const {
        cout << "\n===== " << name << " 人员信息 =====" << endl;
        if (personnel.empty()) {
            cout << "暂无人员信息" << endl;
        } else {
            for (const auto& person : personnel) {
                person->displayInfo();
                cout << endl;
            }
        }
        cout << "===============================\n" << endl;
    }

    // 获取大学名称
    string getName() const { return name; }
};

int main() {
    // 设置控制台编码为UTF-8，确保中文正常显示
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // 创建大学对象
    University university("示例大学");

    // 创建各类人员对象
    Student* student1 = new Student("张三", 20, "男", "P001", "S2023001", "计算机科学与技术1班", 3.8);
    Teacher* teacher1 = new Teacher("李四", 40, "女", "P002", "T2010001", "计算机学院", "教授", 12000);
    Staff* staff1 = new Staff("王五", 35, "男", "P003", "SF2015001", "行政助理", "校长办公室", 6000);

    // 添加人员到大学
    university.addPerson(student1);
    university.addPerson(teacher1);
    university.addPerson(staff1);

    // 显示所有人员信息
    university.displayAllPersonnel();

    // 测试各个派生类的特有方法
    cout << "\n===== 特有功能测试 =====" << endl;
    student1->enrollCourse("面向对象程序设计");
    teacher1->teachCourse("数据结构");
    staff1->handleTask("会议安排");
    cout << "======================\n" << endl;

    // 创建基类指针，演示多态
    cout << "\n===== 多态演示 =====" << endl;
    vector<Person*> personList;
    personList.push_back(new Student("赵六", 21, "女", "P004", "S2022002", "软件工程2班", 3.6));
    personList.push_back(new Teacher("孙七", 45, "男", "P005", "T2008002", "电子工程学院", "副教授", 9000));
    personList.push_back(new Staff("周八", 30, "女", "P006", "SF2018002", "财务专员", "财务处", 5000));

    // 通过基类指针调用虚函数，展示多态
    for (const auto& person : personList) {
        cout << "这是一个" << person->getType() << "：" << person->getName() << endl;
        person->displayInfo();
        cout << endl;
        delete person; // 释放内存
    }
    cout << "===================\n" << endl;

    cout << "程序运行结束！" << endl;
    return 0;
}