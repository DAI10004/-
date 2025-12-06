#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

class Employee {
private:
    char name[50];
    char address[100];
    char postalCode[10];

public:
    // 构造函数
    Employee(const char* n, const char* addr, const char* pCode) {
        strcpy(name, n);
        strcpy(address, addr);
        strcpy(postalCode, pCode);
    }

    // 修改姓名的功能
    void setName(const char* newName) {
        strcpy(name, newName);
    }
    void setAddress(const char* newAddress) {
        strcpy(address, newAddress);
    }
    void setPostalCode(const char* newPostalCode) {
        strcpy(postalCode, newPostalCode);
    }

    // 显示员工信息
    void display() {
        cout << "姓名: " << name << "\n家庭地址: " << address << "\n邮政编码: " << postalCode << endl;
    }
};

int main() {
    // 设置控制台为UTF-8编码，确保中文输入输出正常
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    // 创建员工对象（从用户输入初始化）
    char name[50], address[100], postalCode[10];
    cout << "请输入员工姓名: ";
    cin.getline(name, 50);
    cout << "请输入员工家庭地址: ";
    cin.getline(address, 100);
    cout << "请输入邮政编码: ";
    cin.getline(postalCode, 10);
    
    Employee emp(name, address, postalCode);
    
    // 显示初始信息
    cout << "初始员工信息：" << endl;       
    emp.display();
    
    // 修改姓名（从用户输入）
    char newName[50];
    cout << "请输入新的员工姓名：";        
    cin.getline(newName, 50);
    emp.setName(newName);
    
    // 修改家庭地址（从用户输入）
    char newAddress[100];
    cout << "请输入新的员工家庭地址：";        
    cin.getline(newAddress, 100);
    emp.setAddress(newAddress);

    // 修改邮政编码（从用户输入）
    char newPostalCode[10];
    cout << "请输入新的邮政编码：";        
    cin.getline(newPostalCode, 10);
    emp.setPostalCode(newPostalCode);

    cout << "修改后的信息：" << endl;
    emp.display();
    
    return 0;
}
