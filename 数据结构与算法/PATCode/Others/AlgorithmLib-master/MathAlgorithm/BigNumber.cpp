//大数加法完整版本
#include <stdio.h>
#include <memory.h>
#include <string.h>

struct bign{
	int d[1000];
	int len;
	bign()
	{
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char str[])
{
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++)
		a.d[i] = str[a.len - 1 - i] - '0';
	return a;
}

bign add(bign a, bign b)
{
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++)
	{
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if(carry > 0)
		c.d[c.len++] = carry;
	return c;
}

bign sub(bign a, bign b)
{
	bign c;
	for(int i = 0; i < a.len || i < b.len; i++)
	{
		if(a.d[i] < b.d[i])//向高位进位
		{
			a.d[i + 1]--;
			a.d[i] +=10;
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	while(c.d[c.len - 1] == 0 && c.len >= 2)//高位是0同时保留至少一位最低位
		c.len--;
	return c;
}

bign multi(bign a, int b)//高精度a和低精度b
{
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len; i++)
	{
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0)
	{
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

bign divide(bign a, int b, int &r)//r保存余数
{
	bign c;
	c.len = a.len;
	for(int i = a.len - 1; i >= 0; i--)
	{
		r = r * 10 + a.d[i];
		if(r < b)//不够除，商0
			c.d[i] = 0;
		else
		{
			c.d[i] = r / b;
			r = r % b;
		}
	}
	//跟减法的情况一样，需要去除高位的0
	while(c.d[c.len - 1] == 0 && c.len >= 2)
		c.len--;
	return c;
}

void Print(bign c)
{
	for(int i = c.len - 1; i >= 0; i--)
		printf("%d", c.d[i]);
}

int main()
{
	char s1[100], s2[100];	
	scanf("%s %s", s1, s2);
	bign a, b, c;
	a = change(s1);
	b = change(s2);
	//c = add(a, b);
	//c = sub(a, b);
	//c = multi(a, b);
	int r = 0;
	c = divide(a, 3, r);
	printf("r = %d\n", r);
	Print(c);
	return 0;
}