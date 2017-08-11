#include<iostream>
#include<stdlib.h>
using namespace std;
double notation(){
	char str[10];
	cin >> str;
	switch (str[0]){
	case '+':return notation() + notation();
	case '-':return notation() - notation();
	case '*':return notation() * notation();
	case '/':return notation() / notation();
	default:return atoi(str);
	}
}
int main1(){
	cout << notation();
	system("pause");
	return 0;
}