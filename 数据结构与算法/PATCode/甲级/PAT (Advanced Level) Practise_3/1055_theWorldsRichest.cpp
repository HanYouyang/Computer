//2016年2月15日17时28分04秒
//2016年2月15日17时57分38秒
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;

struct People{
	char name[10];
	int age;
	int netWorth;
}peo[maxn];

bool cmp(People a, People b)
{
	if(a.netWorth != b.netWorth) return a.netWorth > b.netWorth;
	else if(a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%s%d%d", peo[i].name, &peo[i].age, &peo[i].netWorth);
	}
	sort(peo, peo + n, cmp);
	for(int i = 0; i < k; i++){
		int m, amin, amax;
		int count = 0;
		cin >> m >> amin >> amax;
		printf("Case #%d:\n", i + 1);
		for(int j = 0; j < n; j++){
			if(peo[j].age >= amin && peo[j].age <= amax){
				printf("%s %d %d\n", peo[j].name, peo[j].age, peo[j].netWorth);
				count++;
			}
			if(m == count) break;
		}
		if(0 == count) printf("None\n");
	}
	return 0;
}
