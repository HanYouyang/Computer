#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

string * g_stringArr;

void printall(int n) {
	for (int i = 1; i <= n; i++)
	{
		cout << g_stringArr[i] << endl;
	}
}

int countString(string s) {
	int len = s.length(), num = 0;
	for (int i = 0; i < len; i++)
	{
		if (s.at(i) == ' ' && s.at(i + 1) != ' ')
			num++;
	}
	return num;
}

string * stringToArray(string s) {
	string * arr = new string[countString(s) + 1];
	int len = s.length(), j = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ' ')
		{
			j++;
			continue;
		}
		arr[j] += s[i];
	}
	return arr;
}

bool isNotOpe(string s) {
	return (s != "add" && s != "find" && s != "rfind" && s != "reset" && s != "copy" && s != "insert" && s != "print" && s != "printall");
}

string getNewExp(string * stringArr, int len) {
	string exp = "";
	for (int i = 0; i < len; i++)
	{
		if (stringArr[i] != "")
		{
			if (i > 0)
				exp += " ";
			exp += stringArr[i];
		}
	}
	return exp;
}

string copy(string s_n, string s_x, string s_l) {
	int n = atoi(s_n.c_str());
	int x = atoi(s_x.c_str());
	int l = atoi(s_l.c_str());
	return g_stringArr[n].substr(x, l);
}

string add(string s1, string s2) {
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1.at(i) < '0' || s1.at(i) > '9')
			return s1 + s2;
	}
	for (int i = 0; i < s2.size(); i++)
	{
		if (s2.at(i) < '0' || s2.at(i) > '9')
			return s1 + s2;
	}
	int a1 = atoi(s1.c_str());
	int a2 = atoi(s2.c_str());
	if (a1 >= 0 && a1 <= 99999 && a2 >= 0 && a2 <= 99999)
	{
		stringstream tmp;
		tmp << (a1 + a2);
		return tmp.str();
	}
	else
		return s1 + s2;
}

string find(string s, string s_n) {
	string s_r;
	stringstream tmp;
	int n = atoi(s_n.c_str());
	int result = (g_stringArr[n].find(s) != string::npos) ? g_stringArr[n].find(s) : g_stringArr[n].length();
	tmp << result;
	s_r = tmp.str();
	return s_r;
}

string rfind(string s, string s_n) {
	string s_r;
	stringstream tmp;
	int n = atoi(s_n.c_str());
	int result = (g_stringArr[n].rfind(s) != string::npos) ? g_stringArr[n].rfind(s) : g_stringArr[n].length();
	tmp << result;
	s_r = tmp.str();
	return s_r;
}

void insert(string s, string s_n, string s_x) {
	int n = atoi(s_n.c_str());
	int x = atoi(s_x.c_str());
	g_stringArr[n].insert(x, s);
}

void reset(string s, string s_n) {
	int n = atoi(s_n.c_str());
	g_stringArr[n] = s;
}

void print(string s_n) {
	int n = atoi(s_n.c_str());
	cout << g_stringArr[n] << endl;
}

void func(string exp) {
	bool last = false;
	string * chain = stringToArray(exp);
	int chainLen = countString(exp) + 1;
	for (int i = 0; i < chainLen; i++)
	{
		if (isNotOpe(chain[i]))
			continue;
		
		if (chain[i] == "copy" && isNotOpe(chain[i + 1]) && isNotOpe(chain[i + 2]) && isNotOpe(chain[i + 3]))
		{
			string result = copy(chain[i + 1], chain[i + 2], chain[i + 3]);
			chain[i] = result;
			chain[i + 1] = "";
			chain[i + 2] = "";
			chain[i + 3] = "";
			i += 3;
		}
		else if (chain[i] == "add" && isNotOpe(chain[i + 1]) && isNotOpe(chain[i + 2]))
		{
			string result = add(chain[i + 1], chain[i + 2]);
			chain[i] = result;
			chain[i + 1] = "";
			chain[i + 2] = "";
			i += 2;
		}
		else if (chain[i] == "find" && isNotOpe(chain[i + 1]) && isNotOpe(chain[i + 2]))
		{
			string result = find(chain[i + 1], chain[i + 2]);
			chain[i] = result;
			chain[i + 1] = "";
			chain[i + 2] = "";
			i += 2;
		}
		else if (chain[i] == "rfind" && isNotOpe(chain[i + 1]) && isNotOpe(chain[i + 2]))
		{
			string result = rfind(chain[i + 1], chain[i + 2]);
			chain[i] = result;
			chain[i + 1] = "";
			chain[i + 2] = "";
			i += 2;
		}
		else if (chain[i] == "insert" && isNotOpe(chain[i + 1]) && isNotOpe(chain[i + 2]) && isNotOpe(chain[i + 3]))
		{
			insert(chain[i + 1], chain[i + 2], chain[i + 3]);
			last = true;
			break;
		}
		else if (chain[i] == "reset" && isNotOpe(chain[i + 1]) && isNotOpe(chain[i + 2]))
		{
			reset(chain[i + 1], chain[i + 2]);
			last = true;
			break;
		}
		else if (chain[i] == "print" && isNotOpe(chain[i + 1]))
		{
			cout << g_stringArr[atoi(chain[i + 1].c_str())] << endl;
			last = true;
			break;
		}
	}
	if (last)
		return;
	string newExp = getNewExp(chain, chainLen);
	func(newExp);
}

int main()
{
	int n = 0;
	cin >> n;
	g_stringArr = new string[n + 1];
	string exp;
	for (int i = 1; i <= n; i++)
	{
		cin >> g_stringArr[i];
	}
	cin.get();
	while (getline(cin, exp))
	{
		if (exp == "over")
			break;

		if (exp == "printall")
			printall(n);
		else
			func(exp);
	}

	return 0;
}