#include "iostream"
#include <cmath>
using namespace std;
const int kMaxM = 13000;
const int KMaxN = 3500;
int main(int argc, char const *argv[])
{
	int result[kMaxM] = {0}; //重量为i的项链的最大价值
	int N, M; //N是charm的个数，M是总重量
	int W[KMaxN], D[KMaxN]; //W是每个charm的重量，D是每个charm的价值
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> W[i] >> D[i];
	}

	for (int i = 0; i < N; ++i) //逐渐添加charm，新添加进去以后比较加不加这个charm哪个价值比较大
	{
		for (int j = M; j >= W[i]; --j) //j代表重量的限制
		{
			result[j] = max(result[j], result[j - W[i]] + D[i]); //前面是还没加charm i，后面是加入charm i
		}
	}
	cout << result[M] << endl;
	return 0;
}