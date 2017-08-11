#include <iostream.h>
#include <cstring>
using namespace std;

int main() {
	char str[15], substr[4];
	while (cin >> str >> substr) {
		int max = 0, max_index = 0;
	    for (int i = 0; i < strlen(str); i ++) {
		    if (str[i] > max) {
			    max = str[i];
			    max_index = i;
		    }
	    }
	
	    for (int i = strlen(str); i > max_index; i--) {
		    str[i + 3] = str[i];
	    }	
	    str[max_index + 1] = substr[0];
	    str[max_index + 2] = substr[1];
	    str[max_index + 3] = substr[2];	
	
	    cout << str <<  endl;
	}
	
	return 0;
}
