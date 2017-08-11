#include "iostream"
#include <string.h>
#include <stdio.h>
using namespace std;
const int kMaxN = 255;
int main(int argc, char const *argv[])
{
	long long int result[kMaxN][kMaxN];
	int number;
	memset(result, 0, sizeof(result));
	for (int i = 0; i < kMaxN; ++i)
	{
		result[0][i] = 1;
		result[i][i] = 1;
	}
	for (int i = 1; i < kMaxN; ++i)
	{
		for (int j = kMaxN - 1; j > 0; --j)
		{
			if (i < j)
				result[i][j] = 0;
			else if (i >= 2 * j)
				result[i][j] = result[i - 2 * j][j] + result[i][j + 1];
			else if (i > j)
				result[i][j] = result[i][j + 1];
		}
	}
	while(scanf("%d", &number)){
		if (number == 0)
			break;
		else
			cout << number << " " << result[number][1] << endl;
	}
	return 0;
}