#include <iostream>
#include <Windows.h>
using namespace std;

class Matrix {
private:
    int data[2][2];

public:
    // 默认构造函数
    Matrix() { for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) data[i][j] = 0; }

    // 带参数构造函数
    Matrix(int values[2][2]) { for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) data[i][j] = values[i][j]; }

    // 拷贝构造函数
    Matrix(const Matrix& other) { for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) data[i][j] = other.data[i][j]; }

    // 友元函数重载运算符
    friend Matrix operator+(const Matrix& m1, const Matrix& m2) {
        Matrix result; for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) result.data[i][j] = m1.data[i][j] + m2.data[i][j]; return result;
    }

    friend Matrix operator-(const Matrix& m1, const Matrix& m2) {
        Matrix result; for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) result.data[i][j] = m1.data[i][j] - m2.data[i][j]; return result;
    }

    // 输入和显示方法
    void inputFromKeyboard() {
        cout << "请输入2x2矩阵的元素：" << endl;
        for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) cout << "矩阵[" << i << "][" << j << "] = ", cin >> data[i][j];
    }

    void display() const {
        for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) cout << data[i][j] << "\t"; cout << endl; }
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "二维数组运算符重载示例程序\n==========================\n";

    int initValues[2][2] = {{1, 2}, {3, 4}};
    Matrix matrix1(initValues);
    cout << "\n矩阵1（通过构造函数初始化）：\n", matrix1.display();

    Matrix matrix2; matrix2.inputFromKeyboard();
    cout << "\n矩阵2（键盘输入）：\n", matrix2.display();

    // 测试运算符重载的两种方式
    cout << "\n运算符重载结果：\n";
    cout << "矩阵1 + 矩阵2 = \n", (matrix1 + matrix2).display();
    cout << "矩阵1 - 矩阵2 = \n", (matrix1 - matrix2).display();

    return 0;
}