#include "iostream"
#include "math.h"
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	double array[n][2];
	double dis= 0, maxdis = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 2; ++j)
			cin >> array[i][j];

	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1;j < n; ++j)
		{
			dis =  sqrt(pow(array[i][0] - array[j][0],2) + pow(array[i][1] - array[j][1],2));
			if(dis > maxdis)
				maxdis = dis;
		}
	cout << fixed << setprecision(4) << maxdis << endl;;
	return 0;
}