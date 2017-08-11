#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int N, S; //N是week数，S是存储价格
	int price[10000];
	int amount[10000];
	long long int result = 0;
	int best_price;
	cin >> N >> S;
	for (int i = 0; i < N; ++i)
	{
		cin >> price[i] >> amount[i];
	}
	best_price = price[0];
	result += amount[0] * price[0];
	for (int i = 1; i < N; ++i)  //从第二周开始算
 	{
		if (price[i] < best_price + S)
			best_price = price[i];
		else
			best_price = best_price + S;
		result += best_price * amount[i]; 
	}
	cout << result;
	return 0;
}