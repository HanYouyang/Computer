//2016年2月23日15时21分30秒
//2016年2月23日
#include <cstdio>

const int maxn = 10010;
bool full[maxn] = {false};

bool isPrime(int n)
{//判断是否是素数
	if(n <= 1) return false;
	for(int i = 2; i * i <= n; i++){
	//i要从2开始;
	//遇到一个新的错误提示：当分母为零时，会出现program received signal SIGFPE, Arithmetic exception.
		if(0 == (n % i)) return false;
	}
	return true;
}

int main()
{
	int msize, n, num[maxn];
	scanf("%d%d", &msize, &n);
	while(!isPrime(msize)) msize++;
	for(int i = 0; i < n; i++){
		scanf("%d", num + i);
	}
	for(int i = 0; i < n; i++){
		if(i) printf(" ");//非第一个元素要在输出元素之前输出空格
		int pos = num[i] % msize;
		if(!full[pos]){//没有发生冲突
			full[pos] = true;
			printf("%d", pos); 
		} else {//发生冲突
			int step;
			for(step = 1; step < msize; step++){//二次探测过程
				int newPos = (pos + step * step) % msize;
				if(!full[newPos]){//有插入地方
					full[newPos] = true;
					printf("%d", newPos);
					break;
				}
			}
			if(step >= msize){//找不到插入地方
				printf("-");
			}
		}
	}
	return 0;
}
