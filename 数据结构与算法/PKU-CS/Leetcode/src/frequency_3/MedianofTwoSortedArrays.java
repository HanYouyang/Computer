package frequency_3;

//There are two sorted arrays A and B of size m and n respectively. 
//Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//median：如果数组有个数是奇数，那么中数的值就是有序时处于中间的数；如果数组个数是偶数的，那么就是有序时中间两个数的平均值。
//要求2个数组的中位数  就是 找到所有元素的中位数
//那么 就mergesort到 一个数组倍 sort到（m+n）/2的时候就是中位数
public class MedianofTwoSortedArrays {

	 public double findMedianSortedArrays(int a[], int b[]) {
	       if (a == null || b == null || (a.length + b.length) == 0) {return 0;}
			int pa = 0;
			int pb = 0;
			double median = 0;
		 
	 
		//这个while循环 写的很巧妙
		//因为你是求median 所以只要“类”merge sort到数组的中位即可
		//然后这样写while也不用考虑那个数组完了不完了
		//只要pa+pb=(A.length+B.length+1)/2 就跳出 出来的如果总元素是奇数的话就是median
			while (pa + pb != (a.length + b.length + 1) / 2) {
				int Ai = (pa == a.length) ? Integer.MAX_VALUE : a[pa];  
		        int Bj = (pb == b.length) ? Integer.MAX_VALUE : b[pb]; 
		        
		        if (Ai < Bj) {
		        	median = a[pa];
		        	pa++;
		        } else {
		        	median = b[pb];
		        	pb++;
		        }
			}
			if ((a.length + b.length) % 2 == 1) {
				return median;	
			} else {
				int Ai = (pa == a.length) ? Integer.MAX_VALUE : a[pa];  //pa没走完就Ai=a[pa]
		        int Bj = (pb == b.length) ? Integer.MAX_VALUE : b[pb]; //pb没走完就Bj=b[pb]
			double median2 = (Ai < Bj) ? Ai : Bj;			
				return (median + median2) / 2;
			}
				
			}
			 
		
	

	public static void main(String[] args) {

	}

}

//
//
//if(A.length==0){
//	if ((B.length) % 2 == 1){
//		return B[(B.length) % 2+1];
//	}else{
//		return (B[(B.length) % 2]+B[(B.length) % 2+1])/2;
//	}
//}else if (B.length==0){
//	if ((A.length) % 2 == 1){
//		return A[(A.length) % 2+1];
//	}else{
//		return (A[(A.length) % 2]+A[(A.length) % 2+1])/2;
//	}
//	
//	
//}
//int lengtha = A.length;
//int lengthb = B.length;
//boolean oneTarget = false;
//
//int target = 0;
//if ((lengtha + lengthb) % 2 == 1) {
//	target = (lengtha + lengthb) / 2 + 1;
//	oneTarget = true;
//} else if ((lengtha + lengthb) % 2 == 0) {
//	target = (lengtha + lengthb) / 2; // 在总数是偶数的情况下 target是 /2和 /2+1
//										// 的平均值
//	oneTarget = false;
//}
//int pointA = 0;
//int pointB = 0;
//int sum = 0;
//int[] merge = new int[lengtha + lengthb];
//while (pointA < lengtha && pointB < lengthb) {
//	if (A[pointA] <= B[pointB]) {
//		merge[sum] = A[pointA];
//		pointA++;
//		sum++;
//	} else {
//		merge[sum] = B[pointB];
//		pointB++;
//		sum++;
//	}
//	if (oneTarget) {
//		if (sum == target) {
//			return (double) merge[--sum];
//		} else {
//			if (sum == target) {
//				return (double) ((merge[sum] + merge[--sum]) / 2);
//			}
//		}
//	}
//}
//if (pointA >= lengtha) {// pointA用光
//	while (pointB < lengthb) {
//		merge[sum] = B[pointB];
//		pointB++;
//		sum++;
//		if (oneTarget) {
//			if (sum == target) {
//				return (double) merge[--sum];
//			} else {
//				if (sum == target) {
//					return (double) ((merge[sum] + merge[--sum]) / 2);
//				}
//			}
//		}
//	}
//
//} else {
//	while (pointA < lengtha) {
//		merge[sum] = A[pointA];
//		pointA++;
//		sum++;
//		if (oneTarget) {
//			if (sum == target) {
//				return (double) merge[--sum];
//			} else {
//				if (sum == target) {
//					return (double) ((merge[sum] + merge[--sum]) / 2);
//				}
//			}
//		}
//	}
//}
//return 0;
