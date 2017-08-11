//2016年2月11日14时40分36秒
//2016年2月11日15时02分07秒
#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int c = a + b;
	if(!c){
		cout << 0 ;
		return 0;
	}
	if(c < 0){
		cout << '-' ;
		c = -c;
	}
	int d[10]={0};
	int i;
	for(i = 0; c > 0 && i < 10; i++){
		d[i] = c % 10;
		c /= 10;
	}
	for(i--; i >= 0; i--){
		cout << d[i];
		if((i % 3)==0 && i){
			cout << ',';
		}
	}
	return 0;
}

