#include<iostream>
using namespace std;
int main(){
	int a[100001], x, y, m, l, j, t = 0;
	cin >> l >> m;
	for (j = 0; j <= l; j++)
		a[j] = 1;
	while (m>0)
	{
		cin >> x >> y;
		for (; x <= y; x++)
		{
			a[x] = 0;
		}
		m--;
	}
	for (j = 0; j <= l; j++)
	if (a[j] == 1)
		t++;
	cout << t << endl;
	return 0;
}