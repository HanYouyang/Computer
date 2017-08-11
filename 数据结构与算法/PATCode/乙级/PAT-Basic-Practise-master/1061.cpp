#include <iostream>
using namespace std;
int main()
{
	int n, m;
	int sum, temp;
	cin >> n >> m;
	int a[m], b[m];
	for(int i = 0; i < m; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i];
	for(int i = 0; i < n; i++){
		sum = 0;
		for(int j = 0; j < m; j++){
			cin >> temp;
			if(temp == b[j])
				sum += a[j];
		}
		cout << sum << endl;
	}
	return 0;
}
