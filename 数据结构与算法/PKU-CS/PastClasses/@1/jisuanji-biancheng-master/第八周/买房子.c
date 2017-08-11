#include <iostream>
#include<math.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int N, k; //N是年薪，k是房价涨幅百分比，i是第几年
	while(cin >> N >> k){
		int i = 1;
		while( N * i < 200 * pow(1 + double(k)/100, i-1))
		{
			if(i>20)
				break;
			else
				i++;
		}
		if (i > 20)
			cout << "Impossible" << endl;
		else
			cout << i << endl;
	}
	return 0;
}