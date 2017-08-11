#include <iostream>
using namespace std;
int main(){
    int n1, n2, result;
    char sign;
    cin >> n1 >> n2;
    cin >> sign;
    switch (sign) {
        case '+': result = n1 + n2; cout << result; break;
        case '-': result = n1 - n2; cout << result; break;
        case '*': result = n1 * n2; cout << result; break;
        case '/': if (n2 == 0){cout << "Divided by zero!";break;}else {result = n1 / n2; cout << result;break;}
        default : cout << "Invalid operator!";break;
    }
    return 0;
}
