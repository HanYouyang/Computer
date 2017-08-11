//2016年2月16日19时03分12秒
//2016年2月16日19时11分22秒
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	bool hashTable[130] = {false};
	for(string::iterator it = str2.begin(); it != str2.end(); it++){
		hashTable[*it] = true;
	}
	for(string::iterator it = str1.begin(); it != str1.end(); it++){
		if(!hashTable[*it]) cout << *it;
	}
	return 0;
}
