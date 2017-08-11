#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main()
{
	bool first = true;
	stack<string> strOutput;
	string line;
	while(getline(cin, line)){
		string x;
		stringstream ss(line);
		while(ss >> x){
			strOutput.push(x);
		}
		while(!strOutput.empty()){
			if(first){
				first = false;
				cout << strOutput.top();
			}
			else{
				cout << ' ' << strOutput.top();
			}
			strOutput.pop();
		}
	}
	return 0;
}