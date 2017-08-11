#include "iostream"
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
	char str[10];
	char substr[10];
	char output[20];
	int maxposition = 0;
	int strlength;
	while (cin >> str >> substr) {
		maxposition = 0;
		strlength = strlen(str);
		// cout << "str length is: " << strlength << endl;
		for (int i = 0; str[i] != '\0'; ++i)
		{
			if (str[i] > str[maxposition])
				maxposition = i;
		}
		// cout << "max position is: " << maxposition << endl;
		for (int i = 0; i < strlen(str) + strlen(substr); ++i)
		{
			if (i < maxposition + 1){
				output[i] = str[i];
			}
			else if (i < maxposition + 4){
				output[i] = substr[i - maxposition - 1];
			}
			else{
				output[i] = str[i - 3];
			}

		}
		output[strlen(str) + strlen(substr)] = '\0';
		cout << output << endl;
	}
	return 0;
}