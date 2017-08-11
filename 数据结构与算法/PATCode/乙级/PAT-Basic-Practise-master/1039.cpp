#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	int m = 0;
	for (int i = 0, j = 0; j < s2.length(); ) {
		if (i != s1.length()) {
			if (s1[i] == s2[j]) {
				i++;
				j++;
			} else if (s1[i] > s2[j]) {
				j++;
				m++;
			} else {
				i++;
				if (i == s1.length()) {
					m += s1.length() - i;
				}
			}
		} else {
			m += s2.length() - j;
			break;
		}
	}
	if (m == 0) {
		cout << "Yes " << s1.length() - s2.length() << endl;
	} else {
		cout << "No " << m << endl;
	}
	return 0;
} 
