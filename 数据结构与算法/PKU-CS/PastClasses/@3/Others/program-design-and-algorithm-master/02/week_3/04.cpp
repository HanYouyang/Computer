#include<iostream>

using namespace std;

char queue[100][100] = { '\0' };
int len = 0;

void fun(int j, int n, int m) {
	if (queue[j][n] == '(' && queue[j][m] == ')')
	{
		queue[j][n] = ' ';
		queue[j][m] = ' ';
		fun(j, 0, 1);
	}
	else if (queue[j][n] == '(' && queue[j][m] == ' ')
	{
		if (m == len - 1)
		{
			queue[j][n] = '$';
			fun(j, 0, 1);
		}
		else
			fun(j, n, m + 1);
	}
	else if (queue[j][n] == '(' && queue[j][m] == '(')
	{
		fun(j, m, m + 1);
	}
	else if (queue[j][n] == '(' && queue[j][m] == '$')
	{
		queue[j][n] = '$';
		for (int i = n - 1; i >= 0; i--)
		{
			if (queue[j][i] == '(')
				queue[j][i] = '$';
			else if (queue[j][i] == ')')
				fun(j, i - 1, i);
		}
	}
	else if (queue[j][n] == ' ' && queue[j][m] == ')')
	{
		if (n == 0) {
			queue[j][m] = '?';
			fun(j, 0, 1);
		}
		else
			fun(j, n - 1, m);
	}
	else if (queue[j][n] == ')' && queue[j][m] == ')') {
		fun(j, n - 1, m);
	}
	else if (queue[j][n] == '?' && queue[j][m] == ')')
	{
		queue[j][m] = '?';
		for (int i = n; i < len; i++)
		{
			if (queue[j][i] == '(')
				fun(j, i, i + 1);
			else if (queue[j][i] == ')')
				fun(j, i - 1, i);
		}
	}
	else if (queue[j][n] == '?' || queue[j][n] == '$' || queue[j][m] == '?' || queue[j][m] == '$')
	{
		fun(j, n + 1, n + 2);
	}
	else if(queue[j][n] == ' ' && queue[j][m] == ' ')
	{
		fun(j, m, m + 1);
	}
	else if (queue[j][n] == ' ' && queue[j][m] == '(')
	{
		fun(j, m, m + 1);
	}
}

int main() {
	int j = 0;
	while (cin.getline(queue[j], 101))
	{
		// print original string
		for (int i = 0; i < 100; i++)
		{
			if (queue[j][i] != '\0')
				len = i + 1;
		}

		for (int i = 0; i < len; i++)
		{
			cout << queue[j][i];
		}
		cout << endl;

		for (int i = 0; i < len; i++)
		{
			if (queue[j][i] != '(' && queue[j][i] != ')')
				queue[j][i] = ' ';
		}

		//pre check
		if (queue[j][0] == ')')
			queue[j][0] = '?';
		if (queue[j][len - 1] == '(')
			queue[j][len - 1] = '$';


		fun(j, 0, 1);

		for (int i = 0; i < len; i++)
		{
			cout << queue[j][i];
		}
		cout << endl;
		
		j++;
	}

	return 0;
}