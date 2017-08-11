#include "iostream"
#include <memory.h>
#include <cstdio>
using namespace std;
const int N = 60;
int dp1[N][N], dp2[N][N];
int f[N][N], g[N][N];//f[i][j]表示将i划分为j个奇数的划分数,g[i][j]表示将i划分为j个偶数的划分数
int ans[N];
int main(int argc, char const *argv[])
{
	int n, k;
	//N划分成K个正整数之和的划分数目
	for (int i = 1; i < N; ++i)  //把i分成j个正整数之和
		for (int j = 1; j <= i; ++j)
		{
			if (i == j)
				dp1[i][j] = 1;
			else //i > j
				dp1[i][j] = dp1[i-1][j-1] + dp1[i-j][j];
		}
	//N划分成若干个不同正整数之和的划分数目
	for (int i = 1; i < N; ++i)  //把i分成若干个最大为j的不同正整数之和
		for (int j = 1; j < N; ++j)
		{
			if (i < j)
				dp2[i][j] = dp2[i][i];
			else if (i == j)
				dp2[i][j] = 1 + dp2[i][j-1];
			else //i > j
				dp2[i][j] = dp2[i-j][j-1] + dp2[i][j-1];
		}
	// N划分成若干个奇正整数之和的划分数目
	f[0][0] = 1;
	g[0][0] = 1;
	for(int i = 1; i < N; i++)
        for(int j = 1; j <= i; j++) {
            g[i][j] = f[i-j][j];
            f[i][j] = g[i-j][j] + f[i-1][j-1];
        }
	for(int i = 1;i < N;i++){
        for(int j = 1;j <= i;j++){
            ans[i] += f[i][j];
        }
    }
	while(cin >> n >> k){
	    cout << dp1[n][k] << endl;
	    cout << dp2[n][n] << endl;
	    cout << ans[n] << endl;
	}
	return 0;
}