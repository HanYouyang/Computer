#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, byBike, byWalk;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		double distance;
		cin >> distance;
		byBike = 27 + distance / 3 + 23;
		byWalk = distance / 1.2;
		if (byWalk > byBike)
			cout << "Bike" << endl;
		else if (byWalk < byBike)
			cout << "Walk" << endl;
		else
			cout<< "All" << endl;
	}
	return 0;
}