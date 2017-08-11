//2016年2月19日09时39分08秒
//2016年2月19日10时21分46秒
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
long long arraySeq[maxn];
int n, p;

int binarySearch(int i, long long x)
{
	//因为有可能所有元素均不满足下面if中的条件，因此right初始值要置为n，而不能为n-1
	int left = i, right = n, mid;
	while(left < right){
		mid = (left + right) / 2;
		//找到第一个满足arraySeq[mid] > x 的元素
		if(arraySeq[mid] > x){
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	return left;
}

int main()
{
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++){
		scanf("%lld", &arraySeq[i]);
	}
	//从小到达排序
	sort(arraySeq, arraySeq + n);
	int ans = 0;
	for(int i = 0; i < n; i++){
		//long long m = arraySeq[i];
		//long long x = m * p;
		//int num = binarySearch(i, x);
		////当得到更长的序列时，更新个数ans为最长序列的长度
		//if((num - i) > ans) ans = num - i;
		////上面的代码更简洁的写法如下
		int temp = binarySearch(i, arraySeq[i] * p);
		ans = max(ans, temp - i);
	}
	printf("%d\n", ans);
	return 0;
}
