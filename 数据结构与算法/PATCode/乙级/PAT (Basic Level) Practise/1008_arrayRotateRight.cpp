// (14 point)This version is wrong with two testpoint
#include <stdio.h>

#define maxn 105

void reverse(int * a, int low, int high){
	while(low < high){
		int temp = a[low];
		a[low] = a[high];
		a[high] = temp;
		low++;
		high--;
	}
}

int main()
{
	int N, M;
	// int tag = 1;
	int array[maxn];
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++){
		scanf("%d", &array[i]);			//The way of input array
	}
	M %= N;
	reverse(array, 0, N-1);
	reverse(array, 0, M-1);
	reverse(array, M, N-1);
	for(int i = 0; i < N-1; i++){
		// if(1 == tag){
		// 	printf("%d", array[i]);
		// 	tag = 0;
		// }
		printf("%d ", array[i]);
	}
	printf("%d", array[N-1]);
	//printf("\n");
	return 0;
}

// //use list
// #include <iostream>
// #include <list>

// using namespace std;

// int main()
// {
// 	int N, M;
// 	list<int> mylist;
// 	cin >> N >> M;
// 	while(N--){
// 		int temp;
// 		cin >> temp;
// 		mylist.push_back(temp);
// 	}
// 	while(M--){
// 		int temp = mylist.back();
// 		mylist.pop_back();
// 		mylist.push_front(temp);
// 	}
// 	bool first = true;
// 	for(list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it){
// 		if(first){
// 			cout << *it;
// 			first = false;
// 		}
// 		else
// 			cout << ' ' << *it;
// 	}
// 	return 0;
// }


