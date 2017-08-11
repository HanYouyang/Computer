//2016年1月31日15时46分09秒
//2016年1月31日15时55分07秒
#include <iostream>

using namespace std;

int main()
{
	char map[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
	int red, green, blue;
	cin >> red >> green >> blue;
	cout << "#";
	cout << map[red / 13] << map[red % 13];
	cout << map[green / 13] << map[green % 13];
	cout << map[blue / 13] << map[blue % 13];
	return 0;
}
