#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;
	int array[n];
	for (int i = 0; i < n; ++i)
		cin >> array[i];
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			if(array[i] + array[j] == k)
			{
				cout << "yes";
				return 0;
			}
		}
	cout << "no";
	return 0;
}