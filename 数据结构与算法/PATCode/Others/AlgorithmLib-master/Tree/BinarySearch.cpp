//Binary Search 二分查找
//时间复杂度o(logn)
//Miibotree
//2015.2.25
#include <stdio.h>

int BinarySearch(int a[], int n, int x)//默认序列递增
{
	int left = 1, right = n, mid = (left + right) / 2;
	while(left <= right)
	{
		if(a[mid] == x)
			return mid;
		else if(a[mid] > x)//说明要查找的数在左边
		//else if(a[mid] < x) 如果序列是递减的，代码改为这一行
		{
			right = mid - 1;
			mid = (left + right) / 2;
		}
		else
		{
			left = mid + 1;
			mid = (left + right) / 2;
		}
	}
	return -1;
}

//lower_bound 函数
//给出查询元素x，求出序列中的一个x的位置L，
//以及序列中的一个大于x的位置R，
//以此形成一个元素的左闭右开区间[L, R)

//判断lower_bound函数查找x是成功还是失败
ing L = lower_bound(a, n, x);
if(L <= n && a[L] == x)//L在区间内并且该位置的值就是x
	printf("YES\n");

//判断upper_bound函数查找成功还是失败
int R = upper_bound(a, n, x);
if(R > 0 && a[R - 1] == x)
	printf("YES\n");
//求解的一个大于等于x的树
int ans = INF;
int R = upper_bound(a, n, x);
if(a[R - 1] == x)//查找成功
	ans = x;
else if (R <= n && a[R] < ans)
	ans = a[R];

int main()
{
	int a[10] = {1, 3, 4, 7, 8, 10, 11, 12, 15};
	printf("%d%d\n", BinarySearch(a, 10, 6), BinarySearch(a, 10, 1));
} 