#include <iostream>
#include <windows.h>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int data[2][2]; // 2x2矩阵

public:
    // 构造函数
    Matrix(int r = 2, int c = 2) : rows(r), cols(c) {
        // 初始化矩阵为0
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = 0;
    }

    // 带值的构造函数
    Matrix(int r, int c, int val) : rows(r), cols(c) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = val;
    }

    // 设置矩阵元素
    void setElement(int i, int j, int val) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            data[i][j] = val;
        }
    }

    // 获取矩阵元素
    int getElement(int i, int j) const {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            return data[i][j];
        }
        return 0;
    }

    // 获取行数
    int getRows() const { return rows; }
    
    // 获取列数
    int getCols() const { return cols; }

    // 友元函数：矩阵加法
    friend Matrix operator+(const Matrix& m1, const Matrix& m2);
    
    // 友元函数：矩阵乘法
    friend Matrix operator*(const Matrix& m1, const Matrix& m2);
    
    // 友元函数：矩阵转置
    friend Matrix transpose(const Matrix& m);
    
    // 友元函数：矩阵输出
    friend ostream& operator<<(ostream& os, const Matrix& m);

    // 显示矩阵
    void display() {
        cout << *this;
    }
};

// 友元函数实现：矩阵加法
Matrix operator+(const Matrix& m1, const Matrix& m2) {
    // 检查矩阵维度是否相同
    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        cerr << "矩阵维度不匹配，无法执行加法运算！" << endl;
        return Matrix(2, 2); // 返回一个默认矩阵
    }
    
    Matrix result(m1.rows, m1.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return result;
}

// 友元函数实现：矩阵乘法
Matrix operator*(const Matrix& m1, const Matrix& m2) {
    // 检查矩阵维度是否匹配
    if (m1.cols != m2.rows) {
        cerr << "矩阵维度不匹配，无法执行乘法运算！" << endl;
        return Matrix(2, 2); // 返回一个默认矩阵
    }
    
    Matrix result(m1.rows, m2.cols);
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < m1.cols; k++) {
                result.data[i][j] += m1.data[i][k] * m2.data[k][j];
            }
        }
    }
    return result;
}

// 友元函数实现：矩阵转置
Matrix transpose(const Matrix& m) {
    Matrix result(m.cols, m.rows);
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            result.data[j][i] = m.data[i][j];
        }
    }
    return result;
}

// 友元函数实现：矩阵输出
ostream& operator<<(ostream& os, const Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            os << m.data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}
    
int main() {
    // 设置控制台为UTF-8编码，确保中文输入输出正常
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    // 创建第一个矩阵（从用户输入初始化）
    Matrix m1(2, 2);
    int value;
    cout << "请输入第一个2x2矩阵的元素：" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "请输入第" << (i + 1) << "行第" << (j + 1) << "列元素: ";
            cin >> value;
            m1.setElement(i, j, value);
        }
    }
    
    cout << "矩阵m1：" << endl;
    m1.display();
    
    // 创建第二个矩阵（从用户输入初始化）
    Matrix m2(2, 2);
    cout << "请输入第二个2x2矩阵的元素：" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "请输入第" << (i + 1) << "行第" << (j + 1) << "列元素: ";
            cin >> value;
            m2.setElement(i, j, value);
        }
    }
    
    cout << "矩阵m2：" << endl;
    m2.display();
    
    // 矩阵加法
    Matrix m3 = m1 + m2;
    cout << "矩阵加法 m1 + m2：" << endl;
    m3.display();
    
    // 矩阵乘法
    Matrix m4 = m1 * m2;
    cout << "矩阵乘法 m1 * m2：" << endl;
    m4.display();
    
    // 矩阵转置
    Matrix m5 = transpose(m1);
    cout << "矩阵m1的转置：" << endl;
    m5.display();
    
    return 0;
}
