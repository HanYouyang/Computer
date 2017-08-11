#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main6(){
	char str[20] = { 0 }, substr[4] = { 0 };
	while (scanf("%s %s", str, substr)){
		int max = str[0], index = 0, i = 1;
		while (str[i] != 0){
			if (str[i] > max){
				max = str[i];
				index = i;
			}
			i++;
		}
		for (i--; i > index; i--){
			str[i + 3] = str[i];
		}
		for (i = 0; i < 3; i++){
			str[index + i + 1] = substr[i];
		}
		printf("%s",str);
	}
	system("pause");
	return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main5()
{
	string dest, sorc;
	int pos;
	while (cin >> dest >> sorc)
	{
		pos = 0;
		for (int i = 0; i<dest.length(); i++)
		{
			if (dest.at(i)>dest.at(pos)) pos = i;
		}
		dest.insert(dest.begin() + pos + 1, sorc.begin(), sorc.end());
		cout << dest << endl;
	}
	cin.get(); cin.get();
	return 0;
}