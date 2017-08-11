#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int m,k;
	cin >> m >> k;
	int count = 0;
	if (m % 19 != 0)
		cout << "NO";
	else{
	while(m != 0){
		if(m%10 == 3)
			count++;
		m = m / 10;
	}
	if(count == k)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	}
	return 0;
}