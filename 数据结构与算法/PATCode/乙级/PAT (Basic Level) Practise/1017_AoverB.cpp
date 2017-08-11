//2016年2月23日20时10分59秒
//2016年2月23日20时43分37秒
#include <cstdio>
#include <cstring>

struct bign{//用结构体来表示大整数
	int d[1010];
	int len;//大整数的长度
	bign(){//构造函数初始化
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char s[])
{//将字符串转化成大整数
	bign a;
	a.len = strlen(s);
	for(int i = 0; i < a.len; i++){
	//整数的高位存储在数组的高位，整数的低位存储在数组的低位
		a.d[i] = s[a.len - i - 1] - '0';
	}
	return a;
}

bign divide(bign a, int b, int & r)
{//除法实现 r为余数
	bign c;
	c.len = a.len;//被除数的每一位和商的每一位是一一对应的，因此先令长度相等
	for(int i = a.len - 1; i >= 0; i--){//从高位开始
		r = r * 10 + a.d[i];//和让一位余留的余数组合
		if(r < b){//如果不够除，该位为零
			c.d[i] = 0;
		} else {//如果够除
			c.d[i] = r / b;//商
			r = r % b;//新的余数
		}
	}
	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0){
		c.len--;//去除高位的零，同时至少保留一位最低位
	}
	return c;
}

int main()
{
	char s[1010];//以字符串的形式输入大整数
	int b, r = 0;//b是除数，r是余数
	scanf("%s%d", s, &b);
	bign a = change(s);//将字符串转换成大整数
	bign ans = divide(a, b, r);//调用除法函数
	for(int i = ans.len - 1; i >= 0; i--){
	//输出商
		printf("%d", ans.d[i]);
	}
	printf(" %d", r);//输出余数
	return 0;
}
