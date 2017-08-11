#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	/**
	 * 每次对折绳子长度都会减半，则越长的绳子
	 * 越晚加入，可以使得结果最长 
	 * 注意如果只有一根绳子 。。 
	 */
	sort(a, a + n);
	double sum = a[0];
	for(int i = 1; i < n; i++){
		sum = (sum + a[i]) / 2.0;
	}
	cout << floor(sum) << endl;
	return 0;
}
