#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int max(int *a, int low, int high){
	int maxindex;
	if (a[low] == a[low - 1]){
		return max(a, low + 1, high);
	}
	else{
		maxindex = low;
	}
	for (int i = low+1; i <= high; i++){
		if (a[i] != a[low - 1] && a[i] > a[maxindex]){
			maxindex = i;
		}
	}
	return maxindex;
}
int second(int *a, int low, int high){
	int max1 = low;
	int max2 = low;
	for (int i = low+1; i<=high; i++){
		if (a[i]>a[max1]){
			max2 = max1;
			max1 = i;
		}
		else if (a[i]>a[max2] && a[i]<a[max1]){
			max2 = i;
		}
	}
	if (max1 == low&&max2 == low){
		return max(a, low+1, high);
	}
	else{
		return max2;
	}
}
int main3(){
	char str[501] = { 0 }; cin >> str; int a[26] = {0}; int i = 0;
	while (str[i] != 0){
		if (str[i] >= 'a'&&str[i] <= 'z'){
			a[str[i] - 97]++;
		}
		if (str[i] >= 'A'&&str[i] <= 'Z'){
			a[str[i] - 65]++;
		}
		i++;
	}
	int secondindex = second(a, 0, 25); int res[26] = { -1 }; int count = 0;
	for (int i = 0; i < 26; i++){
		if (a[i] == a[secondindex]){
			res[count] = i; count++;
		}
	}
	int len = strlen(str),flag=1;
	for (int i = 0; i < len&&flag; i++){
		for (int j = 0; j < count; j++){
			if (str[i] - 97 == res[j] || str[i] - 65 == res[j]){
				char big = res[j] + 65, small = res[j] + 97; int number = a[res[j]];
				cout << big << "+" << small << ":" << number << endl;
				flag = 0;
				break;
			}
		}
	}
	system("pause");
	return 0;
}
int main2(){
	int a[6] = { 3, 3, 2, 2, 1, 1 };
	cout << second(a, 0, 5);
	system("pause");
	return 0;
}