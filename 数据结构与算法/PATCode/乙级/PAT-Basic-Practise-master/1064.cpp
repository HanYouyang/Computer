#include <iostream>
#include <set>
using namespace std;
int getFriendNum(int num) {
    int sum = 0;
    while(num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int main()
{
	int n, temp;
	cin >> n;
	set<int> s;
	for(int i = 0; i < n; i++){
		cin >> temp;
		s.insert(getFriendNum(temp));
	}
	cout << s.size() << endl;
	bool flag = false;
	set<int>::iterator it;
	for(it = s.begin(); it != s.end(); it++){
		cout << (flag ? " " : "") << *it;
		flag = true;
	}
	cout << endl;
	return 0;
} 
