#include <iostream>

using namespace std;
int main()
{
	int number = 0;
	char input[1000][300] = {'\0'};
	char output[1000][300] = {'\0'};
	cin >> number;
	int k = 0;
	while(k < number){
		cin >> input[k];
		for (int i = 0; input[k][i] != '\0'; ++i)
		{
			switch(input[k][i]){
				case 'A': output[k][i] = 'T'; break;
				case 'T': output[k][i] = 'A'; break;
				case 'C': output[k][i] = 'G'; break;
				case 'G': output[k][i] = 'C'; break;  
			}
		}
		k++;
	}
	for (int i = 0; i < number; ++i)
	{
		cout << output[i] << endl;
	}
	return 0;
}