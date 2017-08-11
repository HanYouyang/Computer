//2016年2月18日15时41分06秒
//2016年2月18日15时50分50秒

//区间贪心
//问题：给出N个开区间(x, y)，从中选择尽可能多的区间，使得这些开区间两两没有交集
//本题解法：先把所有区间按右端点y从小到大排序，右区间相同的按左端点x从小到大排序
//	然后根据总是选择右端点最小的区间的方案选择了第一个区间，判断接下来的每个
//	区间的左端点是否大于或等于第一个区间的右端点，若满足，则将结果加1（初始为1）
//	并将这个新的区间当作第一个区间继续判断
//tips：也可以对x从大到小排序然后总是选择左端点最大的区间
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 110;

struct Coordinate{
	int x, y;
}coo[maxn];

bool cmp(Coordinate a, Coordinate b){
	if(a.y != b.y) return a.y < b.y;
	else return a.x < b.x;
}

int main()
{
	int n;
	while(~scanf("%d", &n) && n != 0){
		for(int i = 0; i < n; i++) scanf("%d%d", &coo[i].x, &coo[i].y);
		sort(coo, coo + n, cmp);
		int count = 1, lastY = coo[0].y;
		for(int i = 1; i < n; i++){
			if(coo[i].x >= lastY){
				lastY = coo[i].y;
				count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
