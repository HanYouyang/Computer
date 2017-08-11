#include "iostream"
using namespace std;

int horizontal(int m);
int vertical(int m);

int horizontal(int m){
	if (m == 0)
		return 1;
	else if (m == 1)
		return 0; 
	else 
		return 2 * vertical(m - 1) + horizontal(m - 2);
}

int vertical(int m){
	if (m == 0)
		return 0;
	else if (m == 1)
		return 1; 
	else 
		return horizontal(m - 1) + vertical(m - 2);
}
int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		if(n == -1)
			break;
		else if ( n % 2)
			cout << 0 << endl;
		else
			cout << horizontal(n) + vertical(n) << endl;
	}

	return 0;
}