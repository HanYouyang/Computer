long long Trans(char *str, int m)//任意m进制数转换成十进制数的函数
{
	long long tmp = 0, c = 1;
	int lenth = strlen(str);//c表示权重
	for(int i = lenth - 1; i >= 0; i--)
	{
		int x;
		if(str[i] >= '0' && str[i] <= '9')
			x = str[i] - '0';
		else
			x = str[i] - 'a' + 10;
		tmp += x * c;
		c *= m;
	}
	return tmp;
}