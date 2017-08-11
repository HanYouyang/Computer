#include <iostream>
using namespace std;
int array[100];
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> array[i];
	}
	while (n--){
		cout << array[n];
		if (n > 0) cout << " ";
	}
	return 0;
}