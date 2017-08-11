//2016年2月1日20时36分00秒
//2016年2月1日20时43分52秒
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	int n, num[10] = {0};
	cin >> s;
	n = s.length();
	while(n--)
		num[s[n]-'0']++;
	for(int i = 0; i < 10; i++){
		if(num[i])
			cout << i << ':' << num[i] << endl;
	}
	return 0;
}
