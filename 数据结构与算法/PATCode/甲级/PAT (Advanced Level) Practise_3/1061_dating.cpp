#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void printDate(char c)
{
	switch(c)
	{
		case 'A':
			printf("MON ");
			break;
		case 'B':
			printf("TUE ");
			break;
		case 'C':
			printf("WED ");
			break;
		case 'D':
			printf("THU ");
			break;
		case 'E':
			printf("FRI ");
			break;
		case 'F':
			printf("SAT ");
			break;
		case 'G':
			printf("SUN ");
			break;
		default:
			break;
	}
}

int main()
{
	bool isfirst = true;
	char a[70];
	char b[70];
	char c[70];
	char d[70];
	scanf("%s", a);
	scanf("%s", b);
	scanf("%s", c);
	scanf("%s", d);
	for(int i = 0; a[i] && b[i]; i++){
		if(isfirst && a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G'){
			printDate(a[i]);
			isfirst = false;
			i++;
		}
		if( (!isfirst) && a[i] == b[i]){
			if(isalpha(a[i]) && a[i] >= 'A' && a[i] <= 'N'){
				printf("%d:", toupper(a[i])-'A'+10);
				break;
			}
			else if(a[i] >= '0' && a[i] <= '9'){
				printf("%02d:", a[i]-'0');
				break;
			}
		}
	}
	for(int i = 0; c[i] && d[i]; i++){
		if(c[i] == d[i] && isalpha(c[i])){
			printf("%02d", i);
			break;
		}
	}
	return 0;
}
