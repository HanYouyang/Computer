#include<stdio.h>
#include<string.h>
int main()
{
	char string[10010]={0};
	gets(string);
	int numberOfP=0,numberOfA=0,numberOfT=0,numberOfe=0,numberOfs=0,numberOft=0;
	int i;
	for(i=0;i<strlen(string);i++)
	{
		switch(string[i])
		{
			case 'P':
				numberOfP++;
				break;
			case 'A':
				numberOfA++;
				break;
			case 'T':
				numberOfT++;
				break;
			case 'e':
				numberOfe++;
				break;
			case 's':
				numberOfs++;
				break;
			case 't':
				numberOft++;
				break;
		}
	}
	while(numberOfP!=0||numberOfA!=0||numberOfT!=0||numberOfe!=0||numberOfs!=0||numberOft!=0)
	{
		if(numberOfP!=0)
		{
			printf("P");
			numberOfP--;
		}
		if(numberOfA!=0)
		{
			printf("A");
			numberOfA--;
		}
		if(numberOfT!=0)
		{
			printf("T");
			numberOfT--;
		}
		if(numberOfe!=0)
		{
			printf("e");
			numberOfe--;
		}
		if(numberOfs!=0)
		{
			printf("s");
			numberOfs--;
		}
		if(numberOft!=0)
		{
			printf("t");
			numberOft--;
		}
	}
	return 0;
}
