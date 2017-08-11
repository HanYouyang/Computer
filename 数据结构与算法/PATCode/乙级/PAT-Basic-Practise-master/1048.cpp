#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int len1 = s1.length();
	int len2 = s2.length();
	int len;
	if(len1 > len2){
		len = len1;
		s2.insert(0, len1-len2, '0');
	} else if(len2 > len1){
		len = len2;
		s1.insert(0, len2-len1, '0');
	} else {
		len = len1;
	}
	int k;
	string res;
	for(int i = 0; i < len; i++){
		if((len-i) % 2 == 1){
			//ÆæÊýÎ»
			k = (s1[i] - '0' + s2[i] - '0') % 13;
			if(k >= 0 && k <= 9)
                res += (k + '0');
            else if (k == 10)
                res += 'J';
            else if (k == 11)
                res += 'Q';
            else
                res += 'K';
		} else {
			k = s2[i] - s1[i];
            if (k < 0)
                k += 10;
            res += k + '0';
		}
	}
	cout << res << endl;
	return 0;
}
