//2016年2月16日18时25分51秒
//2016年2月16日18时34分19秒
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1010;

int  main()
{
	int n, result[maxn] = {0};
	scanf("%d", &n);
	int champion = 0;
	for(int i = 0; i < n; i++){
		int team, member, score;
		scanf("%d-%d %d", &team, &member, &score);
		result[team] += score;
		if(result[team] > result[champion]) champion = team;
	}
	printf("%d %d\n", champion, result[champion]);
	return 0;
}
