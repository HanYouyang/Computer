#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	int len = s.length();
	int sum = 0;
	for(int i = 0; i < len; i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			sum += (s[i] - 'A' + 1);
		} else if(s[i] >= 'a' && s[i] <= 'z'){
			sum += (s[i] - 'a' + 1);
		}
	}
	int zero = 0, one = 0;
	while(sum != 0){
		if(sum % 2 == 0)
			zero++;
		else
			one++;
		sum /= 2;
	}
	cout << zero << " " << one << endl;
	return 0;
}
