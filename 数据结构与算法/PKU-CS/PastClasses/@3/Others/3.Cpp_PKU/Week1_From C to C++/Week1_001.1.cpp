//use function pointer to refer function
#include<stdio.h>
void PrintMin(int a, int b) {
	if(a<b)
		printf("%d\n",a);
	else
		printf("%d\n",b);
}
int main () {
	void (*p)(int x, int y);
	int x=4,y=5;
	p = PrintMin;
	p(x,y);

	return 0;
}