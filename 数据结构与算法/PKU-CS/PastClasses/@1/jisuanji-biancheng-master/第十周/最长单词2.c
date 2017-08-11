#include "iostream"
#include "string.h"
using namespace std;
int main(int argc, char const *argv[])
{
	char str[500];
	char longestWord[500];
	char currentWord[500];
	int maxlength = 0;
	int currentlength = 0;
	int flag = 0;
	cin.getline(str, 500);
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] != ' ' && str[i] != '.') {
			currentWord[currentlength] = str[i];
			currentlength++;
		}
		else {
			if (currentlength > maxlength) {
				maxlength = currentlength;
				memset(longestWord, '\0', sizeof(longestWord));
				currentWord[currentlength] = '\0';
				strcpy(longestWord, currentWord);
			}
			currentlength = 0;
			memset(currentWord, '\0', sizeof(currentWord));
		}
	}
	cout << longestWord << endl;
	return 0;
}