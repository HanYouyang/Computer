#include <iostream>

using namespace std;
//从键盘输入一指定金额（以元为单位，如345），然后输出支付该金额的各种面额的人民币数量
//显示100元，50元，20元，10元，5元，1元各多少张，要求尽量使用大面额的钞票。
int main(){
    int money, nHundred, nFifty, nTwenty, nTen, nFive, nOne;

    cin >> money;

    nHundred = money / 100;
    nFifty = (money - nHundred * 100) / 50;
    nTwenty = (money - nHundred * 100 - nFifty * 50) / 20;
    nTen = (money - nHundred * 100 - nFifty * 50 - nTwenty * 20) / 10;
    nFive = (money - nHundred * 100 - nFifty * 50 - nTwenty * 20 - nTen * 10) / 5;
    nOne = (money - nHundred * 100 - nFifty * 50 - nTwenty * 20 - nTen * 10 - nFive * 5) / 1;

    cout << nHundred << endl;
    cout << nFifty << endl;
    cout << nTwenty << endl;
    cout << nTen << endl;
    cout << nFive << endl;
    cout << nOne << endl;

    return 0;
}
