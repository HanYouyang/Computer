#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	char str[4][65];
	scanf("%s %s %s %s",str[0], str[1], str[2], str[3]);
	int i=0, j=0;
	while(str[0][i] != '\0' && str[1][i] != '\0'){
		if(str[0][i] == str[1][i] && (isdigit(str[0][i]) || str[0][i]>='A'&&str[0][i]<='N')){
			if(j == 0){
				if(str[0][i]>='A' && str[0][i]<='G')
				{
					printf("%s ",week[str[0][i]-'A']);
					j = 1;
				}
			} else if(j == 1) {
				if(str[0][i]>='0' && str[0][i]<='9')
					printf("%02d:", str[0][i]-'0');
				else
					printf("%02d:", str[0][i]-'A'+10);
				j++;
			} else {
				break;
			}
		}
		i++;
	}
	i = 0;
	while(str[2][i]!='\0' && str[3][i]!='\0'){
		if(str[2][i] == str[3][i] && isalpha(str[2][i]))
		{
			printf("%02d\n", i);
			break;
		}
		i++;
	}
	return 0;
}
