#include<iostream>

using namespace std;

int count(char s[]) {
	int i = 0;
	while (i < 40 && s[i] != '\0')
	{
		i++;
	}

	return i;
}

int main() {
	char text[1000][40] = { '\0' };
	int len[1000] = { 0 };
	int n = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> text[i];
		if (*text[i] == '\n')
			break;
	}

	for (int i = 0; i < n; i++)
	{
		len[i] = count(text[i]);
	}

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += len[i];
		if (sum + 1 + len[i + 1] <= 80)
		{
			cout << text[i] << ' ';
			sum++;
		}
		else
		{
			cout << text[i] << endl;
			sum = 0;
		}
	}
	cout << endl;
	return 0;
}