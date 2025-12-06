// 第七章第四题：文件操作 - 请根据题目要求添加代码
// 提示：可以实现文件读取、文件复制、文件追加等功能

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // 请根据题目要求实现相应的文件操作功能
    cout << "第七章第四题：文件操作示例" << endl;
    
    // 示例：文件读取功能
    ifstream fin("input.txt");
    if (fin) {
        string line;
        cout << "读取文件内容：" << endl;
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();
    } else {
        cout << "文件input.txt不存在" << endl;
    }
    
    return 0;
}