#include <stdio.h>
#include <string.h>
int main()
{
	char bcs[1005] = {0}, shang[1005] = {0};
	int i, num, cs, yushu=0, s; //s为当前位的商 
	scanf("%s%d", bcs, &cs);
	for(i=0; i<strlen(bcs); i++) {
		num = bcs[i] - '0';
		s = (yushu * 10 + num) / cs;
		yushu = (yushu * 10 + num) % cs;
		
		shang[i] = s + '0';
		if(i == strlen(bcs))
			shang[i+1] = '\0'; 
	}
	while(shang[0] == '0'){
		//如果首位为0，把商往前移 
		if(strlen(shang) == 1)
			break;
		for(i=0; i<strlen(shang); i++)
			shang[i] = shang[i+1];
	}
	printf("%s %d\n", shang, yushu);
	return 0;
}
