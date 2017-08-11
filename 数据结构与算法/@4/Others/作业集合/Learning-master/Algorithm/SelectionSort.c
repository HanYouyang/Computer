#include <stdio.h>

//选择排序，每次选择最小的一个元素放到前面 
void SelectionSort(int A[], int n) {
	int i, j, small, temp;
	for (i = 0; i < n - 1; i++) {
		small = i;
		for (j = i + 1; j < n; j++) {
			if (A[j] < A[small]) {
				small = j;
			}
		}
		temp = A[small];
		A[small] = A[i];
		A[i] = temp;
	}
}

int main() {
	int A[] = {1, 3, 4, 7, 5, 6, 9, 2, 8, 0}, n = 10;
	SelectionSort(A, n);
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	return 0;
}
