#include<stdio.h>
#include<string.h>

int main()
{
	char s1[80],s2[80],s3[80],s4[80];
	char day,hour;
	int minute,i=0,j=0;
	scanf("%s",s1);
	scanf("%s",s2);
	scanf("%s",s3);
	scanf("%s",s4);
	while(1)
	{
		if(s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='G')
		{
			day=s1[i];
			s1[i]=' ';
			break;
		}
		i++;
	}
	while(1)
	{
		if(s1[i]==s2[i]&&((s1[i]>='0') && (s1[i]<='9')||(s1[i]>='A') && (s1[i]<='N')))
		{
			hour=s1[i];
			break;
		}
		i++;
	}
	while(1)
	{
		if(s3[j]==s4[j]&&((s3[j]>='A'&&s3[j]<='Z')||(s3[j]>='a'&&s3[j]<='z')))
		{
			minute=j;
			break;
		}
		j++;
	}
	switch (day)
	{
		case 'A':printf("MON ");break;
        case 'B':printf("TUE ");break;
        case 'C':printf("WED ");break;
        case 'D':printf("THU ");break;
        case 'E':printf("FRI ");break;
        case 'F':printf("SAT ");break;
        case 'G':printf("SUN ");break;
	}
	if(hour<10)
	{
		printf("0%d:",hour-'0');
	}else
	{
		printf("%d:",hour-'A'+10);
	}
	printf("%02d",minute);
	
	return 0;
} 
