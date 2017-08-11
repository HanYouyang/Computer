//2016年2月23日21时38分31秒
//2016年2月23日22时17分14秒
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1010;
//当字符串长度为30时会有两个点过不去，发生段错误
//是因为可能要经过几百次加法，而几百次加法之后可能会超过30位

struct bign{//用结构体存储大整数
	int d[maxn];
	int len;
	bign(){//构造函数初始化
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char s[])
{//将字符数组改变为大整数结构体类型
	bign a;
	a.len = strlen(s);
	for(int i = 0; i < a.len; i++){
	//大整数的高位存储在数组的高位
		a.d[i] = s[a.len - i - 1] - '0';
	}
	return a;
}

bign add(bign a, bign b)
{//两个大整数相加
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++){
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;	
		carry = temp / 10;
	}
	if(carry != 0) c.d[c.len++] = carry;
	//如果最后进位不为零，则直接赋给结果的最高位
	return c;
}

bool judge(bign c)
{//判断是否时回文数
	if(c.len == 1) return true;
	for(int i = 0; i < c.len / 2; i++){
		if(c.d[i] != c.d[c.len - i - 1]) return false;
	}
	return true;
}

void print(bign ans)
{//输出大整数
	for(int i = ans.len - 1; i >= 0; i--){
		printf("%d", ans.d[i]);
	}
	printf("\n");
}

int main()
{
	char s[maxn];
	int step;
	//input
	scanf("%s%d", s, &step);
	//process && output
	bign a = change(s);
	for(int i = 0; i < step; i++){
		if(judge(a)){//中途得到回文数
			print(a);
			printf("%d", i);
			return 0;
		} else {//如果没得到回文数
			bign b = a;
			reverse(b.d, b.d + b.len);
			//c++中的reverse函数
			a = add(a, b);
		}
	}
	print(a);
	printf("%d", step);
	return 0;
}
