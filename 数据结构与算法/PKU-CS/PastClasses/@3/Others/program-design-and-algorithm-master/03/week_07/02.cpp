#include <iostream>
#include <iomanip>


using namespace std;

int main()
{
	double i;

	cin >> i;

	cout << fixed << setprecision(5) << i << endl;
	cout << fixed << scientific << setprecision(7) << i << endl;

	return 0;
}