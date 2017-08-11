#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int k;
	cin >> k;
	int num1 = 0, num5 = 0, num10 = 0;
	for (int i = 0; i < k; ++i)
	 {
	 	int n;
	 	cin >> n;
	 	if (n == 1)
	 		num1++;
	 	if (n == 5)
	 		num5++;
	 	if (n == 10)
	 		num10++;
	 } 
	cout << num1 << endl;
	cout << num5 << endl;
	cout << num10 << endl;
	return 0;
}