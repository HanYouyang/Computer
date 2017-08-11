#include <iostream>
#include <iomanip>


using namespace std;

int main()
{
	int i;

	cin >> i;

	cout << fixed << setbase(16) << i << endl;
	cout << setbase(10) << setw(10) << setfill('0') << i << endl;

	return 0;
}