#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int array[N][N];
	int count = 0;
	int i, j;
	for (i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> array[i][j];
	i = j = 0;
	for (i = 1; i < N - 1; ++i)
		for (j = 1; j < N - 1; ++j)
			if(array[i][j] <= array[i-1][j] -50 &&
			   array[i][j] <= array[i+1][j] -50 &&
			   array[i][j] <= array[i][j-1] -50 &&
			   array[i][j] <= array[i][j+1] -50)
			   count++; 
	cout << count;
	return 0;
}