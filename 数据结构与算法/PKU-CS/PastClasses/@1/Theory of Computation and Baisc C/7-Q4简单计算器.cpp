#include <iostream>
using namespace std;
// 简单计算器
int main(){
    int x , y;
    char operater;
    cin >> x >> y >> operater;
    if( operater == '+' || operater == '-' || operater == '*' || operater == '/'){
        switch(operater){
        case('+'):
            cout << x + y << endl;
            break;
        case('-'):
            cout << x - y << endl;
            break;
        case('*'):
            cout << x * y << endl;
            break;
        case('/'):
            if(y == 0)
                cout << "Divided by zero!" << endl;
            else
                cout << x / y << endl;
        }
    }else{
        cout << "Invalid operator!" << endl;
    }


    return 0;
}
