#include <stdio.h>
int main()
{
int n1 = 15;
short n2 = -15;
unsigned short n3 = 0xffe0;
char c = 15;
n1 = n1>>2;
n2 >>= 3;
n3 >>= 4;
c >>= 3;
printf( "n1=%d,n2=%x,n3=%x,c=%x",n1,n2,n3,c);
}
