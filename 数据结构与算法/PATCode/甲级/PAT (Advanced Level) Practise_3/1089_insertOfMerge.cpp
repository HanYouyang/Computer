//2016年2月20日13时48分16秒
//2016年2月20日14时58分49秒
//改进版
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 110;
int origin[maxn], temp[maxn], changed[maxn];
int n;


bool isEqual(int a[], int b[])
{
	for(int i = 1; i <= n; i++){
		if(a[i] != b[i]) return false;
	}
	return true;
}


void printArray(int a[]){
	for(int i = 1; i <= n; i++){
		if(i != 1) printf(" ");
		printf("%d", a[i]);
	}
}

bool insertSort()
{
	bool flag = false;
	int i, j;
	for(i = 2; i <= n; i++){
		if(i != 2 && isEqual(temp, changed)) flag = true;
		temp[0] = temp[i];
		for(j = i; j > 1 && temp[0] < temp[j - 1]; j--) temp[j] = temp[j - 1];
		temp[j] = temp[0];
		if(flag) return true;
	}
	return false;
}

bool mergeSort()
{
	bool flag = false;
	for(int step = 2; step / 2 <= n; step *= 2){
		if(step != 2 && isEqual(temp, changed)) flag = true;
		for(int i = 1; i <= n; i += step){
			//sort的第二个参数容易写
			sort(temp + i, temp + min(n + 1, i + step));
		}
		if(flag) return true;
	}
	return false;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", origin + i);
		temp[i] = origin[i];
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", changed + i);
	}
	if(insertSort()){
		printf("Insertion Sort\n");
		printArray(temp);
	} else {
		for(int i = 1; i <= n; i++) temp[i] = origin[i];
		mergeSort();
		printf("Merge Sort\n");
		printArray(temp);
	}
	return 0;
}
