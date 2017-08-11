#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	int n, output[3] = {0};
	int k = 0;
	while(cin >> n)
	{
		k = 0;

		for (int i = 0; i < 3; ++i)
		{
			output[i] = 0;
		}

		if(n%3 == 0){
			output[k] = 3;
			k++;
		}
		if(n%5 == 0){
			output[k] = 5;
			k++;
		}
		if(n%7 == 0){
			output[k] = 7;
			k++;
		}
		if(k == 0)
			cout << 'n';
		else
			for (int i = 0; output[i] != 0 && i < 3; ++i)
			{
				if(i>0)
					cout << " ";
				cout << output[i];
			}
		cout << endl;
	}
	return 0;
}