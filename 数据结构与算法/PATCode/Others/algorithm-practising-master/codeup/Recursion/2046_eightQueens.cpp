//2016年2月18日13时01分27秒
//2016年2月18日13时32分19秒
#include <cstdio>
#include <algorithm>

const int maxn = 10;
const int queenNum = 8;
const int maxCount = 92;

int m;
int count = 0;
int hashTable[maxn] = {false};
int P[maxn] = {0};
int queenString[maxCount + 5][queenNum + 5];

void queenPrint(int index)
{
	if (index == queenNum + 1) {
		for (int i = 1; i <= queenNum; i++) queenString[count][i] = P[i];
		count++;
		return;
	}
	for (int x = 1; x <= queenNum; x++) {
		if (hashTable[x] == false) {
			bool flag = true;
			for (int pre = 1; pre < index; pre++) {
				if (abs(pre - index) == abs(P[pre] - x)){
					flag = false;
					break;
				}
			}
			if (flag) {
				P[index] = x;
				hashTable[x] = true;
				queenPrint(index + 1);
				hashTable[x] = false;
			}
		}
	}
}

int main()
{
	queenPrint(1);
	int n = 0;
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &m);
			for(int i = 1; i <= queenNum; i++) printf("%d", queenString[m - 1][i]);
			printf("\n");
		}
	}
	return 0;
}
