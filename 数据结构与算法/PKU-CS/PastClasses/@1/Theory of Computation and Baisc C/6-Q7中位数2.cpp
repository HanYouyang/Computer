#include <iostream>
#include <cstdio>
 
using namespace std;
//中位数 
int main()
{
    int i, j, n, t;
    int num[10001];
 
	while(1)
	{
		cin >> n;
		if(n == 0)
			break;
		for(i = 0; i < n; i++)
			cin >> num[i];
		for(i = 0; i < n; i++){
			t = num[i];
			j = i;
			while(j > 0 && num[j-1] >= t)
			{
				num[j] = num[j-1];
				j--;
			}
			num[j] = t;
		}
		if(n % 2 == 0)
			cout << (num[n/2 -1] + num[n/2]) / 2 << endl;
		else
			cout << num[(n + 1)/2 - 1] << endl;
	}
    return 0;
}

