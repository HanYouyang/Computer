#include<iostream>

using namespace std;

char queue[100] = { '\0' };
char b = '\0', g = '\0';

void fun(int n, int m) {
	if (queue[0] != '0')
	{
		if (queue[n] == b && queue[m] == g)
		{
			cout << n << ' ' << m << endl;
			queue[n] = '0';
			queue[m] = '0';
			fun(0, 1);
		}
		else if (queue[n] == b && queue[m] == '0')
		{
			fun(n, m + 1);
		}
		else if ((queue[n] == b && queue[m] == b) || queue[n] == g)
		{
			fun(n + 1, n + 2);
		}
		else if (queue[n] == '0' && queue[m] == '0')
		{
			fun(n + 2, n + 3);
		}
	}

}

int main() {
	cin.getline(queue, 101);

	b = queue[0];

	for (int i = 0; i < 100; i++)
	{
		if (queue[i] != b)
		{
			g = queue[i];
			break;
		}
	}

	fun(0, 1);
	return 0;
}