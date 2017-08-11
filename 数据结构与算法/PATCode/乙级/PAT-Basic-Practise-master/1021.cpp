#include <stdio.h>
#include <string.h>
char s[1005];
int main()
{
	int i;
	memset(s, 'A', sizeof(char) * 1005);
	int m[10] = { 0 };
	scanf("%s", s);
	for(i=0; i<strlen(s); i++){
		switch(s[i]){
			case '0':
				m[0]++;
				break;
			case '1':
				m[1]++;
				break;
			case '2':
				m[2]++;
				break;
			case '3':
				m[3]++;
				break;
			case '4':
				m[4]++;
				break;
			case '5':
				m[5]++;
				break;
			case '6':
				m[6]++;
				break;
			case '7':
				m[7]++;
				break;
			case '8':
				m[8]++;
				break;
			case '9':
				m[9]++;
				break;
		}
	}
	for(i=0; i<10; i++){
		if(m[i])
			printf("%d:%d\n", i, m[i]);
	}
	return 0;
}
