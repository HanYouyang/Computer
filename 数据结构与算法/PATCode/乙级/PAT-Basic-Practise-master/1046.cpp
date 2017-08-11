#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d, N;
	int j=0, y=0;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> a >> b >> c >> d;
		if(a+c == b && a+c != d)
			y++;
		if(a+c == d && a+c != b)
			j++;
	}
	cout << j << " " << y << endl;
	return 0;
}
