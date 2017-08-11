//2016年1月31日12时22分09秒
//2016年1月31日12时50分05秒
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n, rowInvert, column, rest;
	char c;
	cin >> n >> c;
	rowInvert = (int)sqrt((n+1)/2.0);
	column = 2 * rowInvert - 1;
	rest = n - 2 * rowInvert * rowInvert + 1;
	//Print inverted triangle
	for(int i = 0; i < rowInvert; i++){
		for(int j = 0; j < i; j++)
			cout << ' ';
		for(int j = i; j < column - i; j++)
			cout << c;
		cout << endl;
	}
	//Print positive triangle
	for(int i = rowInvert - 2; i >= 0; i--){
		for(int j = 0; j < i; j++)
			cout << ' ';
		for(int j = i; j < column - i; j++)
			cout << c;
		cout << endl;
	}
	cout << rest;
	return 0;
}
