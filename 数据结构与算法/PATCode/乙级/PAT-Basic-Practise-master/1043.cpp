#include <iostream>
#include <string>
using namespace std;
int main()
{
	int s[6] = {0};
	string pat("PATest");
	string str;
	cin >> str;
	for(int i=0; i<str.length(); i++){
		if( pat.find(str[i], 0) != string::npos ){
			int k = pat.find(str[i]);
			s[k]++;
		}
	}
	int max = 0;
	for(int i=0; i<6; i++){
		if(s[i] > max)
			max = s[i];
	}
	for(int i=0; i<max; i++){
		for(int j=0; j<6; j++){
			if(s[j]-- > 0)
				cout << pat[j];
		}
	}
	cout << endl;
	return 0;
}
