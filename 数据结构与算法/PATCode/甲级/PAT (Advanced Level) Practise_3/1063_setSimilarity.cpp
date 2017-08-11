//2016年2月24日15时06分50秒
//2016年2月24日15时42分05秒

//多次使用set的自带函数insert发生了超时
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

const int maxn = 51;
const int maxm = 10010;
set<int> myset[maxn];

void compare(int a, int b)
{//求a与b的similarity
	/*//测试点4运行超时版本
	set<int> tempset;
	tempset.insert(myset[a].begin(), myset[a].end());
	tempset.insert(myset[b].begin(), myset[b].end());
	int nc = myset[a].size() + myset[b].size() - tempset.size();
	int nt = tempset.size();
	*/
	//insert与find的时间复杂度均为O(longN)因此上面方法的运行时间大约是下面方法的二倍
	int nc = 0, nt = myset[b].size();//相同的个数，不同的个数
	for(set<int>::iterator it = myset[a].begin(); it != myset[a].end(); it++){
		if(myset[b].find(*it) != myset[b].end()) nc++;//在myset[b]中找到了myset[a]中的元素
		else nt++;//没找到
	}
	printf("%.1f%%\n", (100.0 * nc) / nt);
	//按格式输出比率
	return;
}

int main()
{
	int n, k;//集合总数，k个请求
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int m;//集合内元素的个数
		scanf("%d", &m);
		for(int j = 0; j < m; j++){
		//输入元素并插入到集合中
			int temp;
			scanf("%d", &temp);
			myset[i].insert(temp);
		}
	}
	scanf("%d", &k);//输入请求计算的个数
	for(int i = 0; i < k; i++){
		int a, b;//集合1，集合2
		scanf("%d%d", &a, &b);
		compare(a, b);//计算similarity
	}
	return 0;
}
