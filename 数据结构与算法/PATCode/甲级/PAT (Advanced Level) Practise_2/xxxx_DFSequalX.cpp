//2016年2月27日14时39分07秒
//2016年2月27日
/*问题
	给定N（1 <= N <= 20）个整数（可能有负数），从中选择K个数，使得
	这K个数之和恰好等于一个给定的整数X；如果有多种方案的话，选择他们
	中元素平方和最大的一个
	输入格式
	4 2 6//4个整数，从中选择2个数，和为6
	2 3 3 4//四个整数
*/
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 30;

int A[maxn], n, k, x, maxSumSqu = -1;
//序列A中n个数选k个数使得和为x，最大平方和为maxSumSqu
vector<int> temp, ans;
//temp存放临时方案，ans存放平方和最大方案
void DFS(int index, int nowK, int sum, int sumSqu){
//当前处理为index号整数，当前已选整数个数为nowK
//当前已选整数之和为sum，当前已选整数平方和为sumSqu
	if(nowK == k && sum == x){
	//找到k个数的和为x
		if(sumSqu > maxSumSqu){
		//如果比当前找到的更优
			maxSumSqu = sumSqu;//更新最大平方和
			ans = temp;//更新最优方案
		}
		return;
	}
	if(index == n || nowK > k || sum > x){
	//已经处理完n个数，或者超过k个数，或者和超过x，返回
		return;
	}
	//选index号数
	temp.push_back(A[index]);
	DFS(index + 1, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
	temp.pop_back();
	//不选index号数
	DFS(index + 1, nowK, sum, sumSqu);
}

int main()
{
	scanf("%d%d%d", &n, &k, &x);
	for(int i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}
	DFS(0, 0, 0, 0);
	for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++){
		if(it != ans.begin()) printf(" ");
		printf("%d", *it);
	}
	return 0;
}

/*拓展问题
	上面的问题中每个数只能选择一次，如果稍微改一下题目：假设N个整数中的每一个
	都可以被选择多次，那么选择k个数，使得k个数之和恰好为x。如何做？
*/

/*解答
	这个问题只需要对上面的代码进行少量的修改即可。由于每个整数都可以被选择多次
	因此当我们选择了index号数时，不应当直接进入index + 1号数的处理。显然，我们
	应当能够继续选择index号数，直到某个时刻决定不再选择index号数，就会通过“不选
	index号数”这条分支进入index + 1号数的处理。因此只需要把“选index号数”这条分支
	的代码修改为DFS(index, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
*/	
