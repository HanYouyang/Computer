//2016年2月16日19时15分26秒
//2016年2月16日19时44分02秒
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

//当maxn为510时会出现断错误，因为此时29行的m-i可能超过51
const int maxn = 1010;

int main()
{
	int n, m;
	int count[maxn] = {0};
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		count[temp]++;
	}
	for(int i = 0; i <= m / 2; i++){
		if(count[i] == 0) continue;
		if(i == m - i){
			if(count[i] >= 2){
				cout << i << ' ' << i << endl;
				return 0;
			}
		} else if(count[m - i]){
			cout << i << ' ' << m - i << endl;
			return 0;
		}
	}
	cout << "No Solution" << endl;
	return 0;
}
