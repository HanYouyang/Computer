#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	/**
	 * ÿ�ζ������ӳ��ȶ�����룬��Խ��������
	 * Խ����룬����ʹ�ý��� 
	 * ע�����ֻ��һ������ ���� 
	 */
	sort(a, a + n);
	double sum = a[0];
	for(int i = 1; i < n; i++){
		sum = (sum + a[i]) / 2.0;
	}
	cout << floor(sum) << endl;
	return 0;
}
