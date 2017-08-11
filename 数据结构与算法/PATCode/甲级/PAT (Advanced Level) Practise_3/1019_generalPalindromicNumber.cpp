//2016年1月31日15时11分35秒
//2016年1月31日15时40分36秒

#include <iostream>

using namespace std;

bool judge(int s[], int num)
{
	for(int i = 0; i <= num / 2; i++){
		if(s[i] != s[num - 1 - i])
			return false;
	}
	return true;
}

int main()
{
	int n, b, num = 0;
	int s[35];
	cin >> n >> b;
	do{
		s[num++] = n % b;
		n /= b;
	}while(n);
	bool flag = judge(s, num);
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	for(int i = num - 1; i >= 0; i--){
		cout << s[i];
		if(i) cout << ' ';
	}
	return 0;
}
