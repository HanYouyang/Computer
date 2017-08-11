#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    if (s1.length() == 0) {
        cout << s2;
        return 0;
    }
    if(s1.find('+', 0) != string::npos){
    	for(int i=0; i<s2.length(); i++){
    		if(s2[i] >= 'A' && s2[i] <= 'Z')
    			s2[i] = '*';
		}
	}
	for(int i=0; i<s2.length(); i++)
		for(int j=0; j<s1.length(); j++){
			if (s1[j] == s2[i]) {
                s2[i] = '*';
            }
            if (s1[j] >= 'A' && s1[j] <= 'Z' && s2[i] == s1[j] + 32) {
                s2[i] = '*';
            }
		}
	for (int i = 0; i < s2.length(); i++) {
        if (s2[i] != '*') {
            cout << s2[i];
        }
    }
    cout << endl;
    return 0;
}
