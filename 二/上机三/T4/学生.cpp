#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

// 学生类（基类）
class Student {
protected:
    string studentId, name, gender, schoolName, admissionDate; // 合并成员变量声明

public:
    // 构造函数
    Student(string id = "", string n = "", string g = "", string school = "", string date = "")
        : studentId(id), name(n), gender(g), schoolName(school), admissionDate(date) {}
    
    // 合并getter/setter函数
    void setStudentId(string id) { studentId = id; } string getStudentId() const { return studentId; }
    void setName(string n) { name = n; } string getName() const { return name; }
    void setGender(string g) { gender = g; } string getGender() const { return gender; }
    void setSchoolName(string school) { schoolName = school; } string getSchoolName() const { return schoolName; }
    void setAdmissionDate(string date) { admissionDate = date; } string getAdmissionDate() const { return admissionDate; }
    
    // 显示学生信息
    virtual void displayInfo() const { cout << "学号: " << studentId << endl << "姓名: " << name << endl << "性别: " << gender << endl << "学校: " << schoolName << endl << "入学时间: " << admissionDate << endl; }
    
    // 计算在校时间（年）
    int getStudyYears() const {
        time_t now = time(0); tm* ltm = localtime(&now); int currentYear = 1900 + ltm->tm_year;
        if (admissionDate.length() >= 4) { return currentYear - stoi(admissionDate.substr(0, 4)); }
        return 0;
    }
};

// 毕业生类（派生类）
class Graduate : public Student {
private:
    string graduationDate, degree, thesisTitle; // 合并成员变量声明

public:
    // 构造函数
    Graduate(string id = "", string n = "", string g = "", string school = "", string admission = "", 
            string graduation = "", string deg = "", string thesis = "")
        : Student(id, n, g, school, admission), graduationDate(graduation), degree(deg), thesisTitle(thesis) {}
    
    // 合并getter/setter函数
    void setGraduationDate(string date) { graduationDate = date; } string getGraduationDate() const { return graduationDate; }
    void setDegree(string deg) { degree = deg; } string getDegree() const { return degree; }
    void setThesisTitle(string thesis) { thesisTitle = thesis; } string getThesisTitle() const { return thesisTitle; }
    
    // 重写显示信息函数
    void displayInfo() const override {
        cout << "=== 毕业生信息 ===" << endl; Student::displayInfo();
        cout << "毕业时间: " << graduationDate << endl << "所获学位: " << degree << endl;
        if (!thesisTitle.empty()) cout << "论文题目: " << thesisTitle << endl;
    }
    
    // 计算学习总时长（年）
    double getTotalStudyDuration() const {
        if (admissionDate.length() >= 4 && graduationDate.length() >= 4) {
            int admissionYear = stoi(admissionDate.substr(0, 4)), gradYear = stoi(graduationDate.substr(0, 4));
            double years = gradYear - admissionYear;
            if (admissionDate.length() >= 7 && graduationDate.length() >= 7) {
                years += (stoi(graduationDate.substr(5, 2)) - stoi(admissionDate.substr(5, 2))) / 12.0;
            }
            return years;
        }
        return 0;
    }
};

// 主函数
int main() {
    SetConsoleOutputCP(CP_UTF8);
    Student student("2021001", "张三", "男", "北京大学", "2021-09-01");
    Graduate graduate("2019001", "李四", "女", "清华大学", "2019-09-01", "2023-06-30", "工学学士", "人工智能在医疗诊断中的应用");
    
    cout << "\n===== 普通学生信息 =====" << endl;
    student.displayInfo(); cout << "在校时间: " << student.getStudyYears() << " 年" << endl;
    
    cout << "\n===== 毕业生信息 =====" << endl;
    graduate.displayInfo(); cout << "学习总时长: " << graduate.getTotalStudyDuration() << " 年" << endl;
    
    cout << "\n===== 继承特性演示 =====" << endl;
    cout << "毕业生学号（通过基类方法）: " << graduate.getStudentId() << endl;
    cout << "毕业生姓名（通过基类方法）: " << graduate.getName() << endl;
    
    cout << "\n===== 修改信息演示 =====" << endl;
    graduate.setName("李四改"); graduate.setDegree("工学硕士");
    cout << "修改后的毕业生信息:" << endl; graduate.displayInfo();
    
    return 0;
}