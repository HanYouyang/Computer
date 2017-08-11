#include<iostream>
#include <iomanip>

using namespace std;

int main() {
	int m = 0;
	float a = 0.0, max = 0.0;
	char no[50][4] = { '\0' };
	char *p[50] = { NULL };
	float sick[50] = { 0.0 };
	bool found = false;

	cin >> m >> a;

	for (int i = 0; i < m; i++)
	{
		cin >> no[i] >> sick[i];
		p[i] = no[i];
	}

	for (int i = 0; i < m; i++)
	{
		max = sick[i];
		for (int j = i; j < m; j++)
		{
			if (sick[j] > max)
			{
				max = sick[j];
				float tmp = sick[i];
				sick[i] = sick[j];
				sick[j] = tmp;

				char *po = p[i];
				p[i] = p[j];
				p[j] = po;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (sick[i] > a)
		{
			cout << p[i] << ' ' << fixed << setprecision(1) << sick[i] << endl;
			found = true;
		}
	}

	if (!found)
		cout << "None." << endl;

	return 0;
}