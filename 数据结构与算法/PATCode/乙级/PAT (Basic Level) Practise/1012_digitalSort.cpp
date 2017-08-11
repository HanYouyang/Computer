#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

double output[5] = {0};
bool isTrue[5];
int alternate = 1;
int output3count = 0;

void process(int integer, int complement)
{
	switch(complement)
	{
		case 0:
			if(integer % 2 == 0){
				output[0] += integer;
				isTrue[0] = true;
			}
			break;
		case 1:
			output[1] += alternate*integer;
			alternate = (-1)*alternate;
			isTrue[1] = true;
			break;
		case 2:
			output[2] ++;
			isTrue[2] = true;
			break;
		case 3:
			output[3] += integer;
			output3count++;
			isTrue[3] = true;
			break;
		case 4:
			if(integer > output[4]){
				output[4] = integer;
				isTrue[4] = true;
			}
			break;
		default:
			break;
	}
}

int main()
{
	int N, integer;
	int complement;
	memset(isTrue, 0, sizeof(isTrue));
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> integer;
		complement = integer % 5;
		process(integer, complement);
	}
	if(isTrue[0]){
		cout << output[0];
	}
	else
		cout << "N";
	if(isTrue[1]){
		cout << ' ' << output[1];
	}
	else
		cout << " N";
	if(isTrue[2]){
		cout << ' ' << output[2];
	}
	else
		cout << " N";
	if(output3count){
		printf(" %.1f", output[3]/output3count);
	}
	else
		cout << " N";
	if(isTrue[4]){
		cout << ' ' << output[4];
	}
	else
		cout << " N";
	return 0;
}