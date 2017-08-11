//2016年2月16日15时33分04秒
//2016年2月16日15时39分42秒
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int hashTable[105] = {0};
	for(int i = 0; i < n; i++){
		int score;
		cin >> score;
		hashTable[score]++;
	}
	int k;
	cin >> k;
	for(int i = 0; i < k; i++){
		int score;
		cin >> score;
		if(i) cout << ' ';
		cout << hashTable[score];
	}
	return 0;
}
