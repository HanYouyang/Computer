#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
/**
 sscanf() �C ��һ���ַ����ж�����ָ����ʽ���������
 sprintf() �C�ַ�����ʽ������Ѹ�ʽ��������д��ĳ���ַ�����
 */
int main()
{
	int N, cnt = 0;
	cin >> N;
	double num, sum = 0.0;
	char a[50], b[50];
	for(int i = 0; i < N; i++){
		scanf("%s", a);
		sscanf(a, "%lf", &num);
		sprintf(b, "%.2lf", num);
		bool flag = false;
		for(int j = 0; j < strlen(a); j++){
			if(a[j] != b[j])
				flag = true;
		}
		if(flag || num < -1000 || num > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            sum += num;
            cnt++;
        }
	}
	if(cnt == 1) {
        printf("The average of 1 number is %.2lf", sum);
    } else if(cnt > 1) {
        printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
    } else {
        printf("The average of 0 numbers is Undefined");
    }
	return 0;
}
