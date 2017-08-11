#include <iostream>
using namespace std;
int main()
{
	int n, d;
	double e;
	cin >> n >> e >> d;
	int kn = 0, kz = 0;
	int m;
	double em; 
	for(int i = 0; i < n; i++){
		cin >> m;
		int ei = 0;
		for(int j = 0; j < m; j++){
			cin >> em;
			if(em < e)
				ei++;
		}
		if(m > d){
			(ei > m / 2) ? kz++ : kz=kz;
		} else {
			(ei > m / 2) ? kn++ : kn=kn;
		}
	}
	printf("%.1f%% %.1f%%\n", kn*1.0 / n * 100, kz*1.0 / n * 100);
	return 0;
} 
