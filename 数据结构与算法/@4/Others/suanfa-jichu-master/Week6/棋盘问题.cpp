#include "iostream"
#include <stdio.h>
#include <memory.h>
using namespace std;
int chessboard[15][15];
int result;
int n, k;
int haschess[15];
void dfs(int line, int number){
	if(number == k){
		result++;
		return;
	}
	for (int i = line; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (chessboard[i][j] == 1 && haschess[j] != 1){
				haschess[j] = 1;
				dfs(i + 1, number +1);
				haschess[j] = 0;
			}
		}
	}

}

int main(int argc, char const *argv[])
{
	char c;
	while(cin >> n >> k){
		if ((n == -1) && (k == -1))
			break;
		memset(chessboard, 0, sizeof(chessboard)); //全部置0
		memset(haschess, 0, sizeof(haschess));
		result = 0;

		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < n; ++j)
			{
				cin >> c;
				if (c == '#')
					chessboard[i][j] = 1;  //读入数据
			}
		dfs(0, 0);
		cout << result << endl;
	}
	return 0;
}