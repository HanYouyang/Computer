#include "iostream"
#include <stdlib.h>
#include <memory.h>
using namespace std;
struct trash_sturuct
{
	int x;
	int y;
	int amount;
}trash[25];

int main(int argc, char const *argv[])
{
	int T, d, n;
	int best_result, count;
	int result;
	cin >> T;
	//T = 1;
	while(T--){
		cin >> d >> n;
		memset(trash, 0, sizeof(trash));
		count = 0;
		best_result = -1;
		for (int i = 0; i < n; ++i)
			cin >> trash[i].x >> trash[i].y >> trash[i].amount; 
		for (int i = 0; i < 1025; ++i)
			for (int j = 0; j < 1025; ++j){
				result = 0;
				for (int k = 0; k < n; ++k){
					if (abs(trash[k].x - i) <= d && abs(trash[k].y - j) <= d )
						result += trash[k].amount;
				}
				if (result == best_result)
					count++;
				else if (result > best_result)
				{
					best_result = result;
					count = 1;
				}

			}
		cout << count << " " << best_result << endl;
		}
		

	return 0;
}