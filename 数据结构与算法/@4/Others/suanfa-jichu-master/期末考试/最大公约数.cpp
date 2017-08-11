#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int m, n;
	int temp;
	while(cin >> m >> n){
		temp = m % n;
		while(temp != 0){
			m = n;
			n = temp;
			temp = m % n; 
		}
		cout << n << endl;
	}
	return 0;
}