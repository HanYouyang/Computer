#include <iostream>
using namespace std;

int main() {
	char s[80];
	cin.getline(s, 80);
	int a = 0, e = 0, i = 0, o = 0, u = 0;
	int x = 0;
	while (s[x] != '\0') {
		switch (s[x]) {
			case 'a':
				a = a + 1;
				break;
			case 'e':
				e = e + 1;
				break;
			case 'i':
				i = i + 1;
				break;
			case 'o':
				o = o + 1;
				break;
			case 'u':
				u = u + 1;
				break;
		}
		x = x + 1;
	}
	cout << a << ' ' << e << ' ' << i << ' ' << o << ' ' << u << endl;
	return 0;
}
