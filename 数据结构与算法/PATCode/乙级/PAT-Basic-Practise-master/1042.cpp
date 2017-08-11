#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main() 
{
    string s;
    getline(cin, s);
    int len = s.length();
    for (int i = 0; i < len; i++) {
        s[i] = tolower(s[i]);
    }
    int a[26] = {0};
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            a[s[i] - 'a']++;
    }
    int max = a[0];
    int j = 0;
    for (int i = 1; i < 26; i++) {
        if (a[i] > max) {
            max = a[i];
            j = i;
        }
    }
    char ch = j + 'a';
    cout << ch << " " << max << endl;
    return 0;
}
