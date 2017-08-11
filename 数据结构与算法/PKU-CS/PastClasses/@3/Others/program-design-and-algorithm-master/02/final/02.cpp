#include<iostream>
#include<ctype.h>

using namespace std;

int main() {
	char s[500] = { '\0' };
	int num[26] = { 0 };
	int max = 0;
	int smaller = 0;
	char ch[26] = { '\0' };
	bool found = false;

	cin.getline(s, 501);

	for (int i = 0; i < 500; i++)
	{
		if (s[i] == '\0')
			break;

		s[i] = toupper(s[i]);

		if (s[i] >= 65 && s[i] <= 90)
		{
			num[s[i] - 65]++;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (num[i] > max)
			max = num[i];
	}

	for (int i = 0; i < 26; i++)
	{
		if (num[i] < max && num[i] > smaller)
			smaller = num[i];
	}

	for (int i = 0; i < 26; i++)
	{
		if (num[i] == smaller)
		{
			ch[i] = i + 65;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		for (int j = i + 1; j < 26; j++)
		{
			if (ch[i] == '\0' && ch[j] != '\0')
			{
				char tmp = ch[j];
				ch[j] = ch[i];
				ch[i] = tmp;
			}
		}
	}

	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (ch[j] == '\0')
				break;

			if (s[i] == ch[j])
			{
				char lower = s[i] + 32;
				cout << s[i] << '+' << lower << ':' << num[s[i] - 65] << endl;
				found = true;
				break;
			}
		}
		if (found)
			break;
	}

	return 0;
}