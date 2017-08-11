#include<iostream>
#include<vector>
#include<algorithm>
struct mooncake
{
	double storage;//注意库存量的精度！！
	double price;
};
bool compare(const mooncake&a,const mooncake &b)
{
	return ((double)a.price / a.storage > (double)b.price / b.storage);
}
int main()
{
	int type, n_w;
	std::cin >> type >> n_w;
	mooncake moon;
	std::vector<mooncake> vec;
	for (int i = 0; i < type; ++i)
	{
		std::cin >> moon.storage;
		vec.push_back(moon);
	}
	std::cin.get();
	for (int i = 0; i < type; ++i)
	{
		std::cin >> moon.price;
		vec[i].price = moon.price;
	}
	std::sort(vec.begin(), vec.end(),compare);

	int K = 0, S = 0;
	for (K; K < vec.size() && S <= n_w; ++K)
	{
		S += vec[K].storage;
	}
	S = S - vec[K - 1].storage;
	double total=0.0;
	for (int i = 0; i < K-1; ++i)
	{
		total += vec[i].price;
	}
	if ((S + vec[K - 1].storage) < n_w)
		total += vec[K - 1].price;
	else
		total += vec[K - 1].price / vec[K - 1].storage*(n_w - S);
	printf("%.02f", total);
	return 0;
}
