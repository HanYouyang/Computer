#include <iostream>

using namespace std;

int main(){
	int k, a[100][100]; 
	cin >> k; 
	int m, n,count;
	while (k >= 1){
		cin >> m >> n; count = 0;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				cin >> a[i][j];
				if (i == 0 || i == m - 1 || j == 0 || j == n - 1){
					count += a[i][j];
				}
			}
		}
		cout << count << endl; 
		k--;
	}

	return 0;
}