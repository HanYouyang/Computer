#include<stdio.h>
#include<math.h>
typedef long long Type;//用int还是过不了，必须用longlong才能过 
Type  gcd(Type a,Type b);
void print(Type a,Type b);
void add(Type a1,Type b1,Type a2,Type b2);
void sub(Type a1,Type b1,Type a2,Type b2);
void mul(Type a1,Type b1,Type a2,Type b2);
void div(Type a1,Type b1,Type a2,Type b2);
Type main()
{
	Type a1,b1,a2,b2; 
	scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
	Type g=gcd(a1,b1);
	a1=a1/g;
	b1=b1/g;
	g=gcd(a2,b2);
	a2=a2/g;
	b2=b2/g;  //先进行约分，就不会出现Type不够用的情况了 
	add(a1,b1,a2,b2);
	sub(a1,b1,a2,b2);
	mul(a1,b1,a2,b2);
	div(a1,b1,a2,b2);
	return 0;
}
Type  gcd(Type a,Type b)
{
	if(a==0)
	{
		return 1;
	}
	a=fabs(a);
	b=fabs(b);//这里要取绝对值，否则求出来的最大公约数可能为负，后面的处理就会麻烦 
	Type max=a;
	if(a<b)
	{
		max=b;
		b=a;
		a=max;
	}
	Type r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;	
}
void print(Type a,Type b)
{
	Type g=gcd(a,b);
	Type a1=a/g;
	Type b1=b/g;
	Type c=a1/b1;
	Type a2=a1%b1;
	if(c==0)
	{
		if(a2<0)
		{
			printf("(%lld/%lld)",a2,b1);
		}else if(a2==0)
		{
			printf("0");
		}else
		{
			printf("%lld/%lld",a2,b1);
		}
	}else if(c>0)
	{
		if(a2==0)
		{
			printf("%lld",c);
		}else
		{
			printf("%lld %lld/%lld",c,a2,b1);
		}
	}else
	{
		if(a2==0)
		{
			printf("(%lld)",c);
		}else
		{
			printf("(%lld %lld/%lld)",c,-a2,b1);
		}
	}	
}
void add(Type a1,Type b1,Type a2,Type b2)
{
	Type b=b1*b2;
	Type a=a1*b2+a2*b1;
	print(a1,b1);
	printf(" + ");
	print(a2,b2);
	printf(" = ");
	print(a,b);
	printf("\n");
}
void sub(Type a1,Type b1,Type a2,Type b2)
{
	Type b=b1*b2;
	Type a=a1*b2-a2*b1;
	print(a1,b1);
	printf(" - ");
	print(a2,b2);
	printf(" = ");
	print(a,b);
	printf("\n");
} 
void mul(Type a1,Type b1,Type a2,Type b2)
{
	Type b=b1*b2;
	Type a=a1*a2;
	print(a1,b1);
	printf(" * ");
	print(a2,b2);
	printf(" = ");
	print(a,b);
	printf("\n");
	
}
void div(Type a1,Type b1,Type a2,Type b2)
{
	
	Type b=b1*a2;
	Type a=a1*b2;
	print(a1,b1);
	printf(" / ");
	print(a2,b2);
	printf(" = ");
	if(b==0)
	{
		printf("Inf");//除法分母为0. 
	}else if(b<0)
	{
		a=-a;
		b=-b;
		print(a,b);//b<0时b的符号要给到a上。 
	}else
	{
		print(a,b);
	}
	printf("\n");
	
}




