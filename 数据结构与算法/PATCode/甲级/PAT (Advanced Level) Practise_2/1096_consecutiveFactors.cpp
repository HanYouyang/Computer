//2016年2月23日18时43分53秒
//2016年2月23日19时12分56秒
#include <cstdio>
#include <cmath>

int main()
{
	long long n, backup;
	scanf("%lld", &n);
	backup = n;//n在接下来的处理中会发生变化，所以用一个变量保存n
	long long range = (long long)sqrt(1.0 * n);//求sqrt(n)
	int ansI = 2, ansLen = 0;//ansI是对应的第一个整数，ansLen是长度
	for(int i = 2; i <= range; i++){
	//遍历到range的理论依据：在大于sqrt(n)的情况下，能整除n的数最多只有一个
	//上面理论依据的依据见晴神指导全书P148
		n = backup;//每次都要复原n
		int j = i, tempLen = 0;
		while(n % j == 0){//能整除
			tempLen++;//长度自增
			n /= j;
			j++;//判断下一个元素
		}
		if(tempLen > ansLen){//当前长度更大则更新
			ansLen = tempLen;
			ansI = i;
		}
	}
	if(ansLen == 0){//如果遍历结束长度仍旧是0，说明不超过sqrt(n)的整数中
			//不存在整除N的连续整数，答案就是n本身
		printf("1\n%lld", backup);
	} else {//否则输出[ansI, ansI + ansLen)
		printf("%d\n", ansLen);
		for(int i = 0; i < ansLen; i++){
			if(i) printf("*");
			printf("%d", ansI + i);
		}
	}
	return 0;
}
