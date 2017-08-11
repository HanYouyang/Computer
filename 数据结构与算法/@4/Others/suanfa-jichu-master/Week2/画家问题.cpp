#include "iostream"
#include <memory.h>
#include <stdio.h>
using namespace std;
const int MAXSIZE = 20;
int paint[MAXSIZE][MAXSIZE], wall[MAXSIZE][MAXSIZE];
int result;
void guess(int size){
	int c, r;
	int count = 0;
	for(int k = 1; k < size + 1; k++){  //第一行
        if(paint[1][k] == 1)
            count++;
    }


    for(r = 1; r < size; r++)
    {
       for(c = 1; c < size + 1; c++)
        {
            paint[r+1][c] = (wall[r][c] + paint[r][c] + paint[r][c-1] + paint[r][c+1] + paint[r-1][c]) % 2;
            if(paint[r+1][c] == 1)
                count++;
        }

    }

    for(c = 1; c < size + 1; c ++) //最后一行校验
    {
        if((paint[size][c] + paint[size][c-1] + paint[size][c+1] + paint[size-1][c])%2 != wall[size][c])
            return;
    }
    if(count < result)
        result = count;
    return;
}


int main(int argc, char const *argv[])
{
	int cases, n, k;
	int c;
	char temp;
	scanf("%d",&cases);
	for (int i = 0; i < cases; ++i)
	{
		scanf("%d", &n);
		memset(wall, 0, sizeof(wall));
		memset(paint, 0, sizeof(paint));
		//读入数据
		for (int i = 1; i < n + 1; ++i)
			for (int j = 1; j < n + 1; ++j)
			{
				cin >> temp;
				if (temp == 'y')
					wall[i][j] = 0;
				else
					wall[i][j] = 1;
			}
		//
		result = 401;  //置初值
		k = (1 << n); //2的n次方
		while(k--){
			guess(n);
			paint[1][1]++;
			c = 1;
			while (paint[1][c] > 1) {
				paint[1][c] = 0;
				c++;
				paint[1][c]++;
			}
		}
		//输出结果
		if (result == 401)
			printf("inf\n");
		else
			printf("%d\n", result);
	}
	return 0;
}