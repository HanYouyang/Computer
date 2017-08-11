#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	char A[12], B[12];
	int i, DA, DB, a=0, b=0;
	long int PA=0, PB=0;
	scanf("%s %d %s %d", A, &DA, B, &DB);
	for(i=0; i<strlen(A); i++)
		if(A[i] == DA+'0')
			a++;
	for(i=0; i<strlen(B); i++)
		if(B[i] == DB+'0')
			b++;
	for(i=a-1; i>=0; i--){
		PA = PA + DA * pow(10, i);
	}
	for(i=b-1; i>=0; i--){
		PB = PB + DB * pow(10, i);
	}
	printf("%ld\n", PA+PB);
	return 0;
}
