//2016年2月23日20时53分14秒
//2016年2月23日21时21分15秒
#include <cstdio>
#include <cstring>

struct bign{//用结构体存储大整数
	int d[25];
	int len;//大整数长度
	bign(){//初始化结构体变量
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char s[]){//将字符串改为大整数结构体类型
	bign a;
	a.len = strlen(s);
	for(int i = 0; i < a.len; i++){
	//整数的高位存储在结构体的高位，整数的低位存储在结构体的低位
		a.d[i] = s[a.len - i - 1] - '0';
	}
	return a;
}

bign multi(bign a, int b)
{//大正数的乘法函数
	bign c;
	int carry = 0;//进位，初始为零
	c.len = a.len;
	for(int i = 0; i < a.len; i++){
	//将b作为一个整体
		int temp = a.d[i] * b + carry;
		c.d[i] = temp % 10;//个位数作为该位的结果
		carry = temp / 10;//高位部分作为新的进位
	}
	while(carry != 0){//最后进位可能不止一位，依次写进大正数的高位
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

bool Judge(bign a, bign b)
{//判断b的所有位是否是a的某个排列
	if(a.len != b.len) return false;
	//如果长度不相等，则肯定不是
	int cnt[10] = {0};//计数0～9出现的次数
	for(int i = 0; i < a.len; i++){
		cnt[a.d[i]]++;//数位a.d[i]对应的cnt值加1
		cnt[b.d[i]]--;//数位b.d[i]对应的cnt值减1
	}
	for(int i = 0; i < 10; i++){
	//判断0～9出现的次数是否都为零
		if(cnt[i] != 0) return false;
		//出现不为零，返回false
	}
	return true;//全部为零，返回true
}

int main()
{
	char s[25];
	int b = 2;
	//input
	scanf("%s", s);//以字符串的形式输入大整数
	//process
	bign a = change(s);//将字符串改变为大正数结构体的形式
	bign c = multi(a, b);//计算a*b
	if(Judge(a, c)) printf("Yes\n");
	//如果c是a的某个排列，输出Yes
	else printf("No\n");
	//output
	for(int i = c.len - 1; i >= 0; i--){
	//逆序输出结果
		printf("%d", c.d[i]);
	}
	return 0;
}
