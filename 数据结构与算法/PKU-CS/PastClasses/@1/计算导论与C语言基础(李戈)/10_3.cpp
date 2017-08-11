#include <iostream>
using namespace std;

int main() {
	char s[500];
	cin.getline(s, 500, '.');
	
	int start = 0, stop = 0, length = 0;
	int max_start = 0, max_stop = 0, max_length = 0;	
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == ' ') {
			stop = i - 1;
			length = stop - start + 1;
			if (length > max_length) {
				max_length = length;
				max_start = start;
				max_stop = stop;
			}
			start = i + 1;
		} 	
		i = i + 1;
	}
	stop = i - 1;
	length = stop - start + 1;
	if (length > max_length) {
		max_length = length;
		max_start = start;
		max_stop = stop;
	}
	
	for (int i = max_start; i <= max_stop; i++) {
		cout << s[i];
	}
	
	return 0;	
}

