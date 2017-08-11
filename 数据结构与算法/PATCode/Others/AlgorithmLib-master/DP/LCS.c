//LCS 最长公共子序列
//Miibotree
//2015.2.17
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char s1[101], s2[101];
int len1, len2;
int dp[101][101];

int main()
{
	while(scanf("%s%s", s1, s2) != EOF)
	{
		len1 = strlen(s1);
		len2 = strlen(s2);

		for(int i = 0; i <= len1; i++)
			dp[i][0] = 0;
	
		for(int i = 0; i <= len2; i++)
			dp[0][i] = 0;

		for(int i = 1; i <= len1; i++)
		{
			for(int j = 1; j <= len2; j++)
			{
				if(s1[i-1] == s2[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		printf("%d\n", dp[len1][len2]);
	}
	return 0;
}