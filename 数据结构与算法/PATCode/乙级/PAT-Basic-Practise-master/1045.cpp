#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n], cpa[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cpa[i] = a[i];
	}
	sort(a, a + n);
	//����������ԭ������ȣ�λ�ò�������߶�����С��Ϊ��Ԫ
	int max = 0;
	int res[n], j = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == cpa[i] && cpa[i] > max)
			res[j++] = cpa[i];
		cpa[i] > max ? max = cpa[i] : max = max;
	}
	cout << j << endl;
	for(int i = 0; i < j; i++){
		if(i != 0)
			cout << " ";
		cout << res[i];
	}
	cout << endl;
	return 0;
}
