#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int low = 0;
	int high = s.length() - 1;
	while(low < high){
		if(s[low++] != s[high--]){
      cout << "NO";
      return 0;
      //first submission there is no "return 0;"
    }
	}
	cout << "YES";
	return 0;
}
