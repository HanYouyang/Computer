ppackage frequency_2;

//Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
//You may assume no duplicates in the array.
//
//Here are few examples.
//[1,3,5,6], 5 → 2
//[1,3,5,6], 2 → 1
//[1,3,5,6], 7 → 4
//[1,3,5,6], 0 → 0 

//本来是和普通的binary search 是一样的,但是如果没找到的话不是返回-1
//而是返回 你这个target如果要插在数组里的 插在的那个下标的位置
//所以九章算法BS模板 就是为了很好的meet这个问题而来的。

public class SearchInsertPosition {
	public int searchInsert(int[] A, int target) {
		int start = 0;
		int end = A.length - 1;
		int mid;
		// A 是sorted
		if (target < A[0]) {
			return 0;
		}
		// 九章bs模板,找比target小的最大的那个数 如果相等就找到了
		// 如果不相等，那么插入的位子应该就在这个数的下标的后一位。
		while (start + 1 < end) {
			mid = start + (end - start) / 2;
			if (A[mid] == target) {
				return mid;
			} else if (A[mid] < target) {
				start = mid;
			} else {
				end = mid;
			}
			if (A[end] == target) {
				return end;
			}
		}
		if (A[end] < target) {
			return end + 1;
		}
		if (A[start] == target) {
			return start;
		}
		return start + 1;
	}
}
