#include <iostream>

using namespace std;

const int maxn = 10010;

int prime[maxn];

//快速某个数是不是素数，只需要判断这个数是否可以被小于这个数的平方根的素数整除即可
//Judging whether a number is a prime or not, only need to judge whether 
//the number can be divided with no remainder by those prime which is 
//less than the square root of the number.
bool isPrime(int candidate, const int index){
	for(int i = 1; prime[i]*prime[i] <= candidate && i < index; i++){
		//If use expression:prime[i] <= sqrt(candidate)[included smath.h]
		//then there will be some error on pat
		if(candidate % prime[i] == 0)
			return false;
	}
	return true;
}

int main()
{
	int M, N;
	int j = 3;
	int line = 0;
	bool first = true;
	cin >> M >> N;
	prime[1] = 2;
	prime[2] = 3;
	for(int i = 5; j <= N; i += 2){
		if(isPrime(i, j)){
			prime[j++] = i;
		}
	}
	for(int i = M; i <= N; i++){
		if(first){
			first = false;
			cout << prime[i];
		}
		else
			cout << ' ' << prime[i];
		if((++line) == 10){
			line = 0;
			first = true;
			cout << endl;
		}
	}
	return 0;
}