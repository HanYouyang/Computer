#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int T, N;
	int temp;
	int k;
	int best_result;
	int result;
	cin >> T;
	//T = 1;
	while(T--){
		cin >> N;
		best_result = 1 << 30;
		for (int i = 1; i <= N / 2 +1; ++i)
		{
			if (N % i == 0)
			{
				temp = N / i;
				for (int j = 1; j <= temp / 2 +1; ++j)
					{
						if (temp % j == 0)
						{
							k = temp / j;
							result = 2 * (i * j + i * k + j * k);
							if (result < best_result)
							{
								best_result = result;
							}

						}
					}	
			}
		}
		cout << best_result << endl;
	}
	return 0;
}