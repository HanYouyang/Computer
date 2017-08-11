#include <iostream>
#include <string>
using namespace std;
/**
 * 一个巧妙的解法：对于每一A，它前面的P的个数和它后面的T的个数的乘积就是能构成的PAT的个数 
 * 具体步骤：
 * 1. 先统计T的个数 countt
 * 2. 每遇到一个T则countt--
 * 3. 每遇到一个P则countp++
 * 4. 每遇到字母A则result += countt * countp
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
