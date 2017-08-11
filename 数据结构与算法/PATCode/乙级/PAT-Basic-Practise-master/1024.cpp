#include <iostream>
using namespace std;
int main()
{
	string s;
	int len;
	cin >> s;
	len = s.length();
	if(s[0] == '-')
		cout << "-";
	
	int E;
	for(int i=1; i<len; i++)
		if(s[i] == 'E'){
			E = i;
			break;
		}
	
	int zhishu = 0;
    for (int i = E + 2; i < len; i++) {
        zhishu = zhishu * 10 + (s[i] - '0');
    }
	
	if(s[E+1] == '-'){
		if (0 < zhishu) {
            cout << "0.";
            for (int i = 1; i < zhishu; i++) {
                cout << 0;
            }
            for (int i = 1; i < E; i++) {
                if (s[i] >= '0' && s[i] <= '9') {
                    cout << s[i];
                }
            }
        } else {
            for (int i = 1; i < E; i++) {
                if (i == 2 - zhishu) {
                    cout << ".";
                }
                if (s[i] >= '0' && s[i] <= '9') {
                    cout << s[i];
                }
            }
        }
	} else {
		if (E - 3 < zhishu) {
            if (s[1] != '0')
                cout << s[1];
            for (int i = 3; i < E; i++) {
                if (s[i] >= '0' && s[i] <= '9') {
                    cout << s[i];
                }
            }
            for (int i = 0; i < zhishu-(E-3); i++) {
                cout << 0;
            }
        } else {
            if (s[1] != '0')
                cout << s[1];
            for (int i = 3; i < E; i++) {
                if (i == 3 + zhishu) {
                    cout << ".";
                }
                if (s[i] >= '0' && s[i] <= '9') {
                    cout << s[i];
                }
            }
        }
	}
	return 0;
}
