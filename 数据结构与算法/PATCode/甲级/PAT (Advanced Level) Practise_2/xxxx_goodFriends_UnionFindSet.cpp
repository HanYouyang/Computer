//2016年3月4日10时48分56秒
//2016年3月4日
/*
	题目见《计算机考研复试上机指导全书》P300
*/
#include <cstdio>

const int maxn = 110;
const int maxm = 110;
int father[maxn];
bool isRoot[maxn];

int findFather(int x)
{
	if(father[x] == x){
		return x;
	} else {
		int F = findFather(father[x]);
		father[x] = F;
		return F;
	}
}

void Union(int a, int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

int main()
{
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		father[i] = i;
		isRoot[i] = false;
	}
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		Union(a, b);
	}
	for(int i = 0; i < n; i++){
		isRoot[findFather(i)] = true;
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(isRoot[i] == true){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
