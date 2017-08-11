#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
	double Pi = 3.14159;
	int h, r;
	cin >> h >> r;
	cout << ceil(20 * 1000 / (Pi * r * r * h));
	return 0;
}