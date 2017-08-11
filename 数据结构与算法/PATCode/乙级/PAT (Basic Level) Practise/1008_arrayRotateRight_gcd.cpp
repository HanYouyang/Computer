//2016年2月22日18时59分35秒
//2016年2月22日19时28分15秒
#include <cstdio>

//求a和b的最大公约数
int gcd(int a, int b)
{
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
	int n, m, a[110];
	//temp为临时变量，pos存放当前处理的位置，next为下一个要处理的位置
	int temp, pos, next;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
	}
	m = m % n;//m有可能比n大，因此要修正
	if(m != 0){//m==0时直接输出原数组，不需要执行此部分
		int d = gcd(m, n);//d为m和n的最大公约数
		for(int i = n - m; i < n - m + d; i++){
			temp = a[i];//把当前位置元素先拿走
			pos = i;//记录当前处理的位置
			do{
				next = (pos - m + n) % n;//计算下一个要处理的位置
				//如果下一个位置不是初始点，则把下一个位置的元素赋值给当前处理的位置
				if(next != i) a[pos] = a[next];
				//如果是初始点，则把一开始拿走的元素赋值给初始位置
				else a[pos] = temp;
				pos = next;//传递位置
			}while(pos != i);//循环直到当前处理位置等于初始位置时结束
		}
	}
	for(int i = 0; i < n; i++){	//输出数组
		if(i) printf(" ");
		printf("%d", a[i]);
	
	return 0;
}
