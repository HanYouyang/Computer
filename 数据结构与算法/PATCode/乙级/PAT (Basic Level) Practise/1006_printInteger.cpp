#include <stdio.h>

int main()
{
	char threeLetter[3] = {'A', 'S', 'B'};
	int threeNumber[3] = {0};
	int num;
	int i = 0;
	scanf("%d", &num);
	while(num != 0){
		threeNumber[i++] = num%10;
		num = num/10;
	}
	for(int i = 2; i > 0; i--){
		for(int j = 0; j < threeNumber[i]; j++)
			printf("%c", threeLetter[i]);
	}
	for(int i = 1; i <= threeNumber[0]; i++)
		printf("%d", i);
	printf("\n");
	return 0;
}
