#include <stdio.h>
int max(int n){
	char s[4];
	char t;
	int i, j, p;
	//spritf(char��ָ��buffer����ʽ���ַ�����Ҫ��ʽ��������), ���أ�д��buffer���ַ��� 
	int length = sprintf(s, "%04d", n); //����4λע�ⲹ0 
	for(i=0; i<length; i++)
		for(j=i+1; j<length; j++)
			if(s[i] < s[j]){
				t = s[i];
				s[i] = s[j];
				s[j] = t;
			}
	sscanf(s, "%d", &p);
	return p;
}
int min(int n){
	char s[4];
	char t;
	int i, j, m;
	//spritf(char��ָ��buffer����ʽ���ַ�����Ҫ��ʽ��������), ���أ�д��buffer���ַ��� 
	int length = sprintf(s, "%04d", n); //����4λע�ⲹ0 
	for(i=0; i<length; i++)
		for(j=i+1; j<length; j++)
			if(s[i] > s[j]){
				t = s[i];
				s[i] = s[j];
				s[j] = t;
			}
	sscanf(s, "%d", &m);
	return m;
}
int main()
{
	int n, num;
	int a, b;
	scanf("%d", &n);
	do{
		a = max(n);
		b = min(n);
		printf("%04d - %04d = %04d\n", a, b, a-b);
		n = a - b;
	}while(n != 6174 && n != 0);
	return 0;
}
