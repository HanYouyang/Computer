#include <iostream>

using namespace std;

int main()
{
	int times = 0;
	int poker[54];
	int pn[54] = {0};
	int rule[54] = {0};
	char map[5] = {'S', 'H', 'C', 'D', 'J'};
	cin >> times;
	for(int i = 0; i < 54; i++){
		poker[i] = i;
		cin >> rule[i];
	}
	while(times--){
		for(int i = 0; i < 54; i++){
			pn[ rule[i] - 1 ] = poker[i];
		}
		for(int i = 0; i < 54; i++)
			poker[i] = pn[i];
	}
	cout << map[ pn[0] / 13] << pn[0] % 13 + 1;
	for(int i = 1; i < 54 ; i++){
		cout << ' ' << map[pn[i] / 13] << pn[i] %13 + 1;
	}
	return 0;
}

