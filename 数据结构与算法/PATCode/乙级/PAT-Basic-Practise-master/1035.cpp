#include <iostream>
#include <algorithm>

// TODO 有一个测试点不通过：浮点错误 

using namespace std;
int cmp(int a, int b) {
    return a < b;
}
int main()
{
	int n;
	cin >> n;
	int v[n];
	int t[n];
	for(int i = 0; i < n; i++)
		cin >> v[i];
	for(int i = 0; i < n; i++)
		cin >> t[i];
	
	int i, j;
	for(i = 0; i < n-1 && t[i] < t[i+1]; i++) ;
	for(j = i+1; j < n && v[j] == t[j]; j++) ;
	if(j == n){
		//插入排序是前面有序，后面与原序列一致 
		cout << "Insertion Sort" << endl;
		sort(v, v + i + 2, cmp); 
	} else {
		cout << "Merge Sort" << endl;
		int k = 1;
        int flag = 1;
        while(flag) {
            flag = 0;
            for (i = 0; i < n; i++) {
                if (v[i] != t[i])
                    flag = 1;
            }
            k = k * 2;
            for (i = 0; i < n / k; i++){
                sort(v + i * k, v + (i + 1) * k, cmp);
            }
            for (i = n / k * k; i < n; i++){
            	sort(v + n / k * k, v + n, cmp);
            } 
        }
	}
	
	for (j = 0; j < n - 1; j++) {
        cout << v[j] << " ";
    }
    cout << v[n - 1] << endl;
	return 0;
}
