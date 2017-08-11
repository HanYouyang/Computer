#include <iostream>
#include <cmath>
#include <map>
using namespace std;


int main()
{
	int n;
	cin >> n;
	
	int id, f;

	typedef multimap<int, int, less<int> > mmid;
	mmid pairs;
	mmid::const_iterator i;
	mmid::const_iterator a;
	mmid::const_iterator b;
	pairs.insert(mmid::value_type(1000000000, 1));

	int x, y, z;

	while (n-- > 0)
	{
		cin >> id >> f;
		i = pairs.insert(mmid::value_type(f, id));
		if (i == pairs.begin())
		{
			b = ++i;
			i--;
			cout << i->second << ' ' << b->second << endl;
		}
		else
		{
			a = --i;
			i++;
			b = ++i;
			i--;
			if(b == pairs.end())
				cout << i->second << ' ' << b->second << endl;
			else
			{
				if ((i->first - a->first < b->first - i->first) || (i->first - a->first == b->first - i->first))
					cout << i->second << ' ' << a->second << endl;
				else
					cout << i->second << ' ' << b->second << endl;
			}
		}
	}

	return 0;
}