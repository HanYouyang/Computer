#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int n, output;
	cin >> n;
	output = (99 - n) / 5  + 1;
	if (output <= 4)
		cout << output;
	else if (output == 5 || output == 6)
		cout << 5;
	else if (output == 7 || output == 8)
		cout << 6;
	else
		cout << 7;
	return 0;
}