#include<iostream>
#include<cstdio>
#include<cmath>


int main()
{
	double R1,P1,R2,P2,a,b,c,d,A,B;
	std::cin >> R1 >> P1 >> R2 >> P2;

	a = R1*cos(P1);
	b = R1*sin(P1);
	c = R2*cos(P2);
	d = R2*sin(P2);
	A = a*c - b*d;//或 A=R1*R2*cos(P!+P2)
	B = b*c + a*d;//B=R1*R2*sin(P!+P2)

	if (A<0 && A>-0.005)
		printf("0.00");
	else printf("%.2lf", A);

	if (B < 0 && B>-0.005)//特别注意细节！！！
		printf("+0.00i\n");
	else if (B < 0)
		printf("%.2lfi\n", B);
	else
		printf("+%.2lfi\n", B);
	return 0;
}
