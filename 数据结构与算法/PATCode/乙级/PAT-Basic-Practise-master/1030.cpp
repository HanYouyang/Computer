#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n;
	long long int p;
	cin >> n >> p;
	vector<long long int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int num = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + num; j < n; j++){
			if(v[j] > p * v[i])  //当前完美数列的长度比上次小
                break;
            if(j - i + 1 > num)
                num = j - i + 1;
		}
	}
	cout << num << endl;
	return 0;
}
