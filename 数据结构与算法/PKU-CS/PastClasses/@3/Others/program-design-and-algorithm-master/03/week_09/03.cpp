#include <iostream>
#include <string>
#include <set>
using namespace std;


int main()
{
	int n, x;
	string op;
	multiset<int> ms;
	set<int> ax;
	set<int>::iterator i;

	cin >> n;
	
	while (n-- > 0)
	{
		cin >> op >> x;
		if (op == "add")
		{
			ms.insert(x);
			ax.insert(x);
			cout << ms.count(x) << endl;
		}
		else if (op == "del")
		{
			cout << ms.count(x) << endl;
			ms.erase(x);
		}
		else if (op == "ask")
		{
			i = ax.find(x);
			cout << ((i == ax.end()) ? 0 : 1) << ' ' << ms.count(x) << endl;
		}
	}
	
	return 0;
}