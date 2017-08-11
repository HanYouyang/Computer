//start:2016年1月28日10时16分55秒
//end:2016年1月28日11时20分10秒
#include <iostream>
#include <cmath>

using namespace std;

int change(char c)
{
	if( c == 'B' ) return 0;
	if( c == 'C' ) return 1;
	if( c == 'J' ) return 2;
}

int main()
{
	int N;
	int a[3] = {0}, b[3] = {0};// B C J
	char sa, sb;
	cin >> N;
	int total = N;
	char map[3] = {'B', 'C', 'J'};
	while(N--){
		cin >> sa >> sb;
		int ia = change(sa);
		int ib = change(sb);
		if(ia == ib) continue;
		if(abs(ia - ib) == 2)
			if(ia > ib) a[ia]++; else b[ib]++;
		else
			if(ia < ib) a[ia]++; else b[ib]++;
	}
	int suma = a[0]+a[1]+a[2];
	int sumb = b[0]+b[1]+b[2];
	cout << suma << ' ' << total-suma-sumb << ' ' << sumb << endl;
	cout << sumb << ' ' << total-suma-sumb << ' ' << suma << endl;
	int maxia = 0, maxib = 0;
	for(int i = 0; i < 3; i++){
		if(a[i] > a[maxia]) maxia = i;
		if(b[i] > b[maxia]) maxib = i;
	}
	cout << map[maxia] << ' ' << map[maxib];
	return 0;
}








