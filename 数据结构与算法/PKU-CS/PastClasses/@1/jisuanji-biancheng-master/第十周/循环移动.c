#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	//假定共有n个整数，则要使前面各数顺序向后移m个位置，并使最后m各数变为最前面的m各数。
	int n, m, temp;
	cin >> n >> m; 
	int array[n];
	for (int i = 0; i < n ; ++i){
		cin >> array[i];
	}

	//全部倒序
	for (int i = 0; i < n / 2 ; ++i){
		temp = array[i];
		array[i] = array[n - 1 - i];
		array[n - 1 - i] = temp;
	}

	// cout << "all inverted" <<endl;
	// for (int i = 0; i < n ; ++i){
	// 	cout << array[i] << " ";
	// }
	// cout << endl;


	//后n-m个元素倒序
	for (int i = m; i < m + (n - m)/2 ; ++i){
		temp = array[i];
		array[i] = array[n + m - 1 - i];
		array[n + m - 1- i] = temp;
	}

	// cout << "last " << n - m << " elements inverted" <<endl;
	// for (int i = 0; i < n ; ++i){
	// 	cout << array[i] << " ";
	// }
	// cout << endl;	

	//前m个元素倒序
	for (int i = 0; i < m / 2 ; ++i){
		temp = array[i];
		array[i] = array[m - 1 - i];
		array[m - 1 - i] = temp;
	}

	// cout << "first " << m << " elements inverted" <<endl;
	// for (int i = 0; i < n ; ++i){
	// 	cout << array[i] << " ";
	// }
	// cout << endl;

	//输出
	for (int i = 0; i < n ; ++i){
		cout << array[i] << " ";
	}
	return 0;
}
