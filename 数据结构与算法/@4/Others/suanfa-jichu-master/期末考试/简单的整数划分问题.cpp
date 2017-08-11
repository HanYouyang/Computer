#include "iostream"
using namespace std;
int divide(int n, int m){
	if (n == 1 || m == 1)
		return 1;
	if (m > n)
		return divide(n, n);
	if (m == n)
		return 1 + divide(n, m - 1);
	if (m < n)
		return divide(n - m, m) + divide(n, m - 1);

}

int main(int argc, char const *argv[])
{
	int number;
	while(cin >> number)
		cout << divide(number, number) << endl;
	return 0;
}