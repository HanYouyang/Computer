#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int s, x;
	double max = 0.0, temp;
	for(int i = 0; i < n; i++){
		cin >> s >> x;
		temp = sqrt(pow(s, 2) + pow(x, 2));
		temp > max ? max = temp : max = max;
	}
	printf("%.2f\n", max);
	return 0;
} 
