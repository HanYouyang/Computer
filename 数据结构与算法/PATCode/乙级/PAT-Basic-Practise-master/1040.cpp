#include <iostream>
#include <string>
using namespace std;
/**
 * һ������Ľⷨ������ÿһA����ǰ���P�ĸ������������T�ĸ����ĳ˻������ܹ��ɵ�PAT�ĸ��� 
 * ���岽�裺
 * 1. ��ͳ��T�ĸ��� countt
 * 2. ÿ����һ��T��countt--
 * 3. ÿ����һ��P��countp++
 * 4. ÿ������ĸA��result += countt * countp
 */
int main() {
    string s;
    cin >> s;
    int result = 0;
    int countp = 0;
    int countt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'T')
            countt++;
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'P') countp++;
        if (s[i] == 'T') countt--;
        if (s[i] == 'A') {
            result = (result + (countp * countt) % 1000000007) % 1000000007;
        }
    }
    cout << result << endl;
    return 0;
}
