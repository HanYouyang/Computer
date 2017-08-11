//2016年1月29日09时58分26秒
//2016年1月29日11时17分28秒
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100010;

int main()
{
	int N;
	int dis[maxn];
	int M;
	int exita, exitb;
	cin >> N;
	int sum = 0;
	for(int i = 1; i <= N; i++){
		int temp;
		cin >> temp;
		sum += temp;
		dis[i] = sum;
	}
	cin >> M;
	while(M--){
		cin >> exita >> exitb;
		if(exita > exitb)
			swap(exita, exitb);
		int temp = dis[exitb - 1] - dis[exita - 1];
		//cout << min(temp, sum-temp) << endl;
		cout << (temp < (sum-temp) ? temp : (sum - temp)) << endl;
	}
	return 0;
}
