#include <iostream>

using namespace std;

int main()
{
	int a, da, b, db, pa = 0, pb = 0;
	cin >> a >> da >> b >> db;
	while(a){
		if(da == a % 10)
			pa = pa * 10 + da;
		a /= 10;
	}
	while(b){
		if(db == b % 10)
			pb = pb * 10 + db;
		b /= 10;
	}
	cout << pa + pb ;
	return 0;
}
