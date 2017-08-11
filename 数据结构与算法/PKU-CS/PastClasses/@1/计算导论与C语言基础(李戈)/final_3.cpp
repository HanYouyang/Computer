#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n;
	cin >> n;
	double point[n][2];
	for (int i = 0; i < n; i++) {
		cin >> point[i][0] >> point[i][1];		
	}
	
	double dis, max_dis = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			dis = sqrt(pow(point[i][0] - point[j][0], 2) + pow(point[i][1] - point[j][1], 2));
			if (dis > max_dis) {
				max_dis = dis;
			}
		}
	}
	
	cout << fixed << setprecision(4) << max_dis << endl;
	
	return 0;
} 
