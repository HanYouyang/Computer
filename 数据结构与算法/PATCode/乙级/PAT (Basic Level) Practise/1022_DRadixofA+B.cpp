#include <iostream>

using namespace std;

int main()
{
	int A, B, sum;
	int D;
	int num[200];
	int i = 0;
	cin >> A >> B >> D;
	sum = A + B;
	do{
		num[i++] = sum % D;
		sum /= D;
	}while(sum);
	while(i){
		cout << num[(i--)-1];
	}
	return 0;
}
