//start：09时35分55秒
//end：09时43分57秒
#include <iostream>

using namespace std;

int main()
{
	int N;
	int counta = 0, countb = 0;
	int a, b, c, d;
	cin >> N;
	while(N--){
		cin >> a >> b >> c >> d;
		if(b == a + c && d != a + c)
			countb++;
		else if(b != a + c && d == a + c)
			counta++;
	}
	cout << counta << ' ' << countb;
}
