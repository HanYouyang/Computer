// PURE C++
// #define LOCAL
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string getPinyin(int n){
	switch(n){
		case 0 : return "ling"; break;
		case 1 : return "yi"; break;
		case 2 : return "er"; break;
		case 3 : return "san"; break;
		case 4 : return "si"; break;
		case 5 : return "wu"; break;
		case 6 : return "liu"; break;
		case 7 : return "qi"; break;
		case 8 : return "ba"; break;
		case 9 : return "jiu"; break;
	}
}

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
	string num;
	stack<int> s;
	string::iterator it;
	int total = 0;
	cin >> num;
	for(it = num.begin(); it != num.end(); it++){
		total += *it - '0';
	}
	while(total){
		s.push(total % 10);
		total /= 10;
	}
	cout << getPinyin(s.top());	// s.top():return the element of stack top and wouldn't delete it.
	s.pop();			//s.pop():delete the element of stack top but return nothing.
	while(!s.empty()){
		cout << " " << getPinyin(s.top());
		s.pop();
	}
	return 0;
}


// // Hybrid version of C & C++
// #include <iostream>
// #include <string>
// using namespace std;
// const int maxn = 100;
// void print_myself(int sum)
// {
// 	int reverse[5];
// 	int i = 0;
// 	char *name[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"};
// 	while(sum != 0){
// 		reverse[i++] = sum % 10;
// 		sum /= 10;
// 	}
// 	printf("%s", name[reverse[--i]]);
// 	while(i){
// 		printf(" %s", name[reverse[--i]]);
// 	}
// }
// int main()
// {
// 	int n = 0;
// 	int sum = 0;
// 	string s;
// 	cin >> s;
// 	n = s.length();		//get the length of string s. you can also use pointer to achieve it.
// 	while(n--){			//the starting of string's index is not 0 but 1.
// 		sum += s[n]-'0';
// 	}
// 	print_myself(sum);
// 	return 0;
// }
