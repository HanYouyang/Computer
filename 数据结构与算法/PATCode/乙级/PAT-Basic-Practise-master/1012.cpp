#include <stdio.h>
#include <math.h>
int main()
{
	int A1=0,F1=0, A2=0,F2=0, A3=0,F3=0, N4=0,F4=0, A5=0,F5=0;
	double A4 = 0.0;
	int i, j, x, n;
	scanf("%d",&n);
	int s[n], b[n];
	for(i=0; i<n; i++){
		scanf("%d",&s[i]);
		b[i] = 0;
	}
	
	for(i=0,j=0; i<n; i++){
		if (s[i] % 10 == 0) {
            A1 += s[i];
            F1 = 1;
        }
        if (s[i] % 5 == 1) {
            b[j++] = s[i];
            F2 = 1;
        }
        if (s[i] % 5 == 2) {
            A3++;
            F3 = 1;
        }
        if (s[i] % 5 == 3) {
            A4 += s[i];
            N4++;
            F4 = 1;
        }
        if (s[i] % 5 == 4) {
            if (A5 < s[i]) {
                A5 = s[i];
                F5 = 1;
            }
        }
	}
	for (i = 0; i < j; i++) {
        if (i == 0 || i % 2 == 0) {
            A2 += b[i];
        } else {
            A2 -= b[i];
        }
    }
	if(F1 == 0)
		printf("N ");
	else
		printf("%d ", A1);
	if(F2 == 0)
		printf("N ");
	else
		printf("%d ", A2);
	if(F3 == 0)
		printf("N ");
	else
		printf("%d ", A3);
	if(F4 == 0)
		printf("N ");
	else
		printf("%.1f ", A4/N4);
	if(F5 == 0)
		printf("N\n");
	else
		printf("%d\n", A5);
	return 0;
}
