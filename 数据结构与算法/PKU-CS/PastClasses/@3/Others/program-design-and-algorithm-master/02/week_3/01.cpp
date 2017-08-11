#include<iostream>

using namespace std;

void convert(char s[], int i) {
	if (s[i + 1] != '\0')
		convert(s, i + 1);
	cout << s[i];
}

int main() {
	char s[500] = { '\0' };
	char words[500][500] = { '\0' };

	cin.getline(s, 501);

	int j = 0, k = 0;
	for (int i = 0; i < 500; i++)
	{
		if (s[i] != ' ' && s[i] != '\t')
		{
			if (i != 0 && (s[i - 1] == ' ' || s[i - 1] == '\t'))
				j++;
			words[j][k] = s[i];
			k++;
		}
		else if (s[i] == ' ' || s[i] == '\t')
		{
			k = 0;
			if (i != 0)
				j++;
			words[j][k] = s[i];
		}
		else {
			break;
		}
	}

	for (int i = 0; i < j + 1; i++)
	{
		if (words[i][0] != ' ' || words[i][0] != '\t')
			convert(words[i], 0);
		else if (words[i][0] == ' ' || words[i][0] == '\t')
			cout << words[i][0];
		else
			break;
	}
	cout << endl;
	return 0;
}