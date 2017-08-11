#include<iostream>

using std::cout;
using std::cin;
int arr[100] = { 0 };
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = N - M%N; i < N; ++i)
		cout << arr[i]<<' ';
	for (int i = 0; i < N - M%N; ++i)
	{
		cout << arr[i];
		if (i != N - M%N - 1)
			cout << ' ';
	}

	return 0;
}