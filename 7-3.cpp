// 第七章第三题：文件操作 - 将输入的字符串写入文件
#include <iostream>
#include <fstream> // 文件操作头文件
using namespace std;

int main() {
    // 1. 打开文件（输出模式，若文件不存在则创建，存在则覆盖）
    ofstream fout("output.txt");
    if (!fout) { // 检查文件是否成功打开
        cerr << "文件打开失败！" << endl;
        return 1; // 异常退出
    }

    // 2. 提示用户输入
    cout << "请输入字符串（以!结束）：";
    char ch;

    // 3. 循环读取字符，直到遇到!
    while (cin.get(ch) && ch != '!') {
        fout.put(ch); // 逐个字符写入文件
    }

    // 4. 关闭文件（必须！确保数据写入磁盘）
    fout.close();
    cout << "字符串已成功写入 output.txt 文件！" << endl;

    return 0;
}