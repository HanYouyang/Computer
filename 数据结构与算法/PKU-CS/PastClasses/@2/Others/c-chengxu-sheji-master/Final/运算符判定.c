#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int a,b,c;
	char temp;
	cin >> a >> temp >> b >> temp >> c;
	if (a + b == c)
		cout << '+';
	else if(a - b == c)
		cout << '-';
	else if(a * b == c)
		cout << '*';
	else if(a / b == c)
		cout << '/';
	else if(a%b == c)
		cout << '%';
	else 
		cout << "error";
	return 0;
}