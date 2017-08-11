#include <iostream>
#include <string> 
#include <cctype>
using namespace std;
void H2D(string s){
	string low[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string high[13] = {"###", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	if(s.length() <= 4){
		for (int i = 0; i <= 12; i++) {
            if (s[0] == low[i][0] && s[1] == low[i][1] && s[2] == low[i][2]) {
                cout << i << endl;
            } else if (s[0] == high[i][0] && s[1] == high[i][1] && s[2] == high[i][2]) {
                cout << 13 * i << endl;
            }
        }
	} else {
		int a = 0, b = 0;
		for (int j = 1; j <= 12; j++) {
            if (s[0] == high[j][0] && s[1] == high[j][1] && s[2] == high[j][2]) {
                a = j;
            }
            if (s[4] == low[j][0] && s[5] == low[j][1] && s[6] == low[j][2]) {
                b = j;
            }
        }
        cout << a * 13 + b << endl;
	}
}
void D2H(string s){
	string low[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string high[13] = {"###", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int p;
    if (s.length() == 1) {
        p = s[0] - '0';
    } else if(s.length() == 2) {
        p = (s[0] - '0') * 10 + (s[1] - '0');
    } else {
        p = (s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0');
    }
    if (p <= 12) {
        cout << low[p] << endl;
    } else if (p % 13 == 0) {
        cout << high[p / 13] << endl;
    } else {
        cout << high[p / 13] << " " << low[p % 13] << endl;
    }
}
int main()
{
	int n;
	cin >> n;
	getchar(); //∂¡»°ªÿ≥µ
	for(int i = 0; i < n; i++){
		string s;
		getline(cin, s);
		if(isalpha(s[0])){
			H2D(s);
		} else {
			D2H(s);
		}
	} 
	return 0;
}
