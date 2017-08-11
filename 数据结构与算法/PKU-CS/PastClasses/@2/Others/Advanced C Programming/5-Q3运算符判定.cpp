#include <iostream>
#include <cstdlib>
using namespace std;
//运算符判定
int main(){
    int a, b, c;
    char a1[10], b1[10], c1[10];
    
    cin.getline(a1, 10, ',');
    cin.getline(b1, 10, ',');
    cin.getline(c1, 10);
    
    a = atoi(a1);
    b = atoi(b1);
    c = atoi(c1);

    if(a + b == c){
        cout << '+';
    }else if(a - b == c){
        cout << '-';
    }else if(a * b == c){
        cout << '*';
    }else if(a / b == c){
        cout << '/';
    }else if (a % b == c){
        cout << '%';
    }else{
        cout << "error";
    }

    return 0;
}