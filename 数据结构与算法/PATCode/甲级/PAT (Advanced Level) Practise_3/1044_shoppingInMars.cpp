//2016年2月19日19时12分26秒
//2016年2月19日20时03分17秒
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x7ffffff;

const int maxn = 100010;

int main()
{
	bool isExact = false;
	int n, m;
	int chain[maxn], pile[maxn] = {0};
	int lost = inf;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &chain[i]);
		pile[i] = pile[i - 1] + chain[i];
	}
	for(int i = 1; i <= n; i++){
		int j = upper_bound(pile + i, pile + n + 1, m + pile[i - 1]) - pile;
		int pay = pile[j - 1] - pile[i - 1];
		if(m == pay){
			isExact = true;
			printf("%d-%d\n", i, j - 1);
		}
		else if(j != n + 1 && lost > chain[j] + pay - m){
			lost = chain[j] + pay - m;
		}
	}
	if(!isExact){
		for(int i = 1; i <= n; i++){
			int j = upper_bound(pile + i, pile + n + 1, m + lost + pile[i - 1]) - pile;
			int pay = pile[j - 1] - pile[i - 1];
			if(pay == m + lost) printf("%d-%d\n", i, j - 1);
		}
	}
	return 0;
}
