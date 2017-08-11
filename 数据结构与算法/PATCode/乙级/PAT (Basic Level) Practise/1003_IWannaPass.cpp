#include <iostream>
#include <string>

using namespace std;

// string length must be greater than or equal to 3
int gt3(string s)
{
	if(s.length() < 3)
		return 0;
	return 1;
}
// Must only include 'P' 'A' 'T', 'P' and 'T' can appear only once
int onlyPAT(string s)
{
	for(string::iterator it = s.begin(); it != s.end(); ++it){
		if(!(*it == 'P' || *it == 'A' || *it == 'T'))
			return 0;
	}
	return 1;
}
// if a string exit "PAT", print YES
int exitPAT(string s)
{
	string str = "PAT";
	int pos = s.find(str);
	//APATAA is NO also;
	if(pos >= 0 && pos < s.length() && s.find('P') == (s.length()-s.find('T')-1))
		return 1;
	return 0;
}
// p_position*(t_position-p_position-1) == len(s)-t_position
int position(string s)
{
	//APT is NO;
	if(s.find('T')-s.find('P') == 1)
		return 0;
	if(s.find('P')*(s.find('T')-s.find('P')-1) == s.length()-s.find('T')-1)
		return 1;
	return 0;
}

int main()
{
	int n;
	string s;
	cin >> n;
	while(n--){
		cin >> s;
		int isone = (gt3(s) && onlyPAT(s));
		if(isone)
		{
			if(exitPAT(s)){
				cout << "YES" << '\n';
				continue;
			}
			if(position(s)){
				cout << "YES" << '\n';
			}
			else
				cout << "NO" << '\n';
				continue;
		}
		else
			cout << "NO" << '\n';
	}
	return 0;
}
