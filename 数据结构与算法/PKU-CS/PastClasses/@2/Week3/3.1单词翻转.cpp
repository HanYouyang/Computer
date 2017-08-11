#include <iostream>
#include <cstring>
using namespace std;

void output(char input[]){
	int length = strlen(input);
	if(length == 0)
		return;
	else
		cout << input[length-1];
		input[length-1] = '\0';
		output(input);
}

int main(int argc, char const *argv[])
{
	char input[500] = {'\0'};
	char temp[500] = {'\0'};
 	cin.getline(input, 500);
 	int j = 0;
 	for (int i = 0;  input[i] != '\0'; ++i)
 	{
 		if (input[i+1] == '\0')
 		{
 			temp[j] = input[i];
 			output(temp);
 		}
 		else if (input[i] == ' '){
 			if (j != 0){
 				output(temp);
 				memset(temp, '\0', strlen(temp));
 				j = 0;
 			}	
 			cout << ' ';
 		}
 		else{
 			temp[j] = input[i];
 			j++;
 		}
 	}
	return 0;
}