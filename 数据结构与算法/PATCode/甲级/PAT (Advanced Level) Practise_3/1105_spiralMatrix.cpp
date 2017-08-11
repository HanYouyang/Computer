//2016年3月8日14时53分22秒
//2016年3月8日15时30分32秒
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 10010;//最大节点数

int sum, m, n;//填充的元素总数，行，列
int origin[maxn], matrix[maxn][maxn];//原始填充元素，存放结果矩阵
//当sum是较大的素数时，m就是sum本身，此时矩阵是sum行1列的，因此行数最多为sum；
//当sum是完全平方数时，n等于根号sum，因此列数最多为根号sum
//于是填充矩阵行数必须不小于sum，列数不小于根号sum
bool cmp(int a, int b)
{//按照元素从大到小进行排序
	return a > b;
}

void getMN(int sum)
{//根据和sum得到行数和列数
	m = (int)ceil(sqrt(1.0 * sum));
	while(sum % m != 0){
		m++;
	}
	n = sum / m;
}

int main()
{
	scanf("%d", &sum);//输入元素总数
	for(int i = 0; i < sum; i++){
		scanf("%d", &origin[i]);//输入每个元素
	}
	sort(origin, origin + sum, cmp);//对元素从大到小排序
	getMN(sum);//得到m和n
	int i = 1, j = 1, now = 0;
	int U = 1, D = m, L = 1, R = n;
	while(now < sum){//模拟填充
		if(now == sum - 1){//对于最后一个数据单独处理***********************************************
			matrix[i][j] = origin[now++];
		}
		while(now < sum && j < R){//向右填充
			matrix[i][j] = origin[now++];
			j++;
		}
		while(now < sum && i < D){//向下填充
			matrix[i][j] = origin[now++];
			i++;
		}
		while(now < sum && j > L){//向左填充
			matrix[i][j] = origin[now++];
			j--;
		}
		while(now < sum && i > U){//向上填充
			matrix[i][j] = origin[now++];
			i--;
		}
		i++; j++;//位置移至内层左上角
		U++; D--; L++; R--;//缩小边界
	}
	for(int i = 1; i <= m ; i++){//按照格式输出
		for(int j = 1; j <= n; j++){
			printf("%d", matrix[i][j]);
			if(j < n) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
