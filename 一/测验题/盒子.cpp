#include <iostream>
#include <windows.h>
using namespace std;

class Box {
private:
    int length, width, height;
public:
    Box(int l, int w, int h) : length(l), width(w), height(h) {}
    int getVolume() { return length * width * height; }
};
int main(){
    // 设置控制台输出为UTF-8编码
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int l, w, h;
    cout << "请输入盒子的长、宽、高: ";
    cin >> l >> w >> h;
    Box box(l, w, h);
    cout << "盒子的体积为: " << box.getVolume() << endl;

    return 0;
}
