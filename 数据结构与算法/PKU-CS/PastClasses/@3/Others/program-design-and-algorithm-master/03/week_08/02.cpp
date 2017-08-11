#include <iostream> 
#include <list> 
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

vector< list<int> > v(10000);

int main() {
	int n = 0;
	cin >> n;
	cin.get();
	char cmd[7];
	int id, id1, id2, num;
	for (int i = 0; i < n; i++)
	{
		cin.getline(cmd, 7, ' ');
		if (cmd[0] == 'n')
		{
			cin >> id;
			v[id] = list<int>();
		}
		else if (cmd[0] == 'a')
		{
			cin >> id >> num;
			v[id].push_back(num);
		}
		else if (cmd[0] == 'm')
		{
			cin >> id1 >> id2;
			v[id1].merge(v[id2]);
		}
		else if (cmd[0] == 'u')
		{
			cin >> id;
			v[id].sort();
			v[id].unique();
		}
		else if (cmd[0] == 'o')
		{
			cin >> id;
			v[id].sort();
			list<int>::iterator i;
			for (i = v[id].begin(); i != v[id].end(); i++)
			{
				if (i != v[id].begin())
					cout << " ";
				cout << *i;
			}
			cout << endl;
		}
		cin.get();
	}

	return 0;
}