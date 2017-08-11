#include "iostream"
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
	int array[5][5];
	int temp;
	int n, m;
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			cin >> array[i][j];
	cin >> n >> m;
	if(n < 0 || n > 4 || m < 0  || m > 4)
		cout<< "error" << endl;
	else{ 
		for (int i = 0; i < 5; ++i)
		  {
		  	 temp = array[m][i];
			 array[m][i] = array[n][i];
			 array[n][i] = temp;
		  }
        for (int i = 0; i < 5; ++i)
            {
            for (int j = 0; j < 5; ++j)
                cout<< setw(4) << array[i][j];
            cout << endl;
            }
 		}
	return 0;
}