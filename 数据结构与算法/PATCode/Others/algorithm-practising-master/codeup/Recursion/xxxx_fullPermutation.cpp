#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 11;

int n, P[maxn], hashTable[maxn] = {false};

void generateP(int index) {
	if(index == (n + 1)) {
		for(int i = 1; i <= n; i++) {
			if(i == 1) printf("%d", P[i]);
			else printf(" %d", P[i]);
		}
		printf("\n");
		return;
	}
	for(int x = 1; x <= n; x++){
		if(hashTable[x] == false) {
			P[index] = x;
			hashTable[x] = true;
			generateP(index + 1);
			hashTable[x] = false;
		}
	}
}

int main()
{
	scanf("%d", &n);
	generateP(1);
	return 0;
}
