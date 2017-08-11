#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int words = 0, sum = 0;
    cin >> words;
    char str[41] = {0};
    for (int i = 0; i < words; i++) {
        cin >> str;
        if (sum + 1 + strlen(str) > 80) {
            cout << endl;               
            sum = 0;        
        } 
        else if(i > 0) {
            cout << " ";
            sum = sum + 1;  
        }
        cout << str;
        sum = sum + strlen(str);
    }
    return 0;
}
