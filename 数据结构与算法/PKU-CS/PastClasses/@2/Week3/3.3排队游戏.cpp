#include "iostream"
#include <string.h>
using namespace std;
int main()
{
	char input[100];
	int countboy = 0;
	int saveboy[100] = {0};
	cin.getline(input,100);
	char boy,girl;
	boy = input[0];
	girl = input[strlen(input)-1];
	for (int i = 0; input[i] != '\0'; ++i)
	{
		if (input[i] == boy)
		{
			saveboy[countboy++] = i;
		}
		else{
			cout << saveboy[--countboy] << " " << i << endl;
		}
	}
	return 0;
}