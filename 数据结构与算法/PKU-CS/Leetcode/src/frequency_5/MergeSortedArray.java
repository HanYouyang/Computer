package frequency_5;
//Given two sorted integer arrays A and B, merge B into A as one sorted array.
//
//Note:
//You may assume that A has enough space to hold additional elements from B. 
//这句话是说 A有个元素 B有n个元素
//The number of elements initialized in A and B are m and n respectively.
//A，B不是都sorted了吗，我们不从头开始比谁小，我们从A，B的尾巴开始比谁大
//谁大，谁就放到A的[(a最后一个有数据的下标)+(b.length)],然后该--下标的--,接下去就和普通mergesort一样

//和cc里9_1完全一样
public class MergeSortedArray {
	public void merge(int[] A, int m, int[] B, int n) {
		// index here
	
		if (n != 0 && m != 0) {
			int lastA = m - 1;
			int lastB = n - 1;
			int lastResult = m + n - 1;

			while (true) {
				if (A[lastA] <= B[lastB]) {
					A[lastResult] = B[lastB];
					lastResult--;
					lastB--;
					if (lastB < 0) {
						break;
					}
				} else if (A[lastA] > B[lastB]) {
					A[lastResult] = A[lastA];
					lastResult--;
					lastA--;
					if (lastA < 0) {
						break;
					}
				}
			}
			if (lastA < 0) {
				for (int i = lastB; i >= 0; i--) {
					A[lastResult] = B[lastB];
					lastResult--;
					lastB--;
				}
			}
			if (lastB < 0) {
				for (int i = lastB; i >= 0; i--) {
					A[lastResult] = A[lastA];
					lastResult--;
					lastA--;
				}
			}
		}
		if(m==0||A.length==0||A==null){
			for (int i = 0; i < n; i++)
	       { A[i] = B[i];}
			}
		}

	public static void main(String[] args) {

	}

}
