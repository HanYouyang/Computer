package frequency_3;

//
//                      1  
//                    1  
//                  1
//                1
//                                  1
//                                1 
//                              1
//-------------------->       <------------每次要么正常前/后四分之一二分 要么往当中逼近（指向start-end当中的后四分之三或者前四分之三）
// 第一刀mid如果划在第一段 那么 A[mid] 肯定比start大
// 如果划在第二段 肯定比 end 小
//变种的2分发 用九章算法模板来做 
// 详见cc 9.3

//九章算法的BS模板来做 --改动 这题无非是吧一个 递增的数组切成2段 前半段高 递增，后半段低 但是也递增。
//而关键就是在mid=start + (end - start) / 2; 这个mid切在第一段还是第二段。
//如果他切在第一段并且start<=target<=mid 则说明在前四分之一直接bs即可。Else就是在后四分之三 start=mid 。
//反之如果mid在第二段 如果mid<=target<=end 就是在后四分之一直接bs else就是在前四分之三 然后||不
//管是前后那个四分之三  mid都会被重新计算 然后最后会往当中逼近  最后像模板一样2个if检查即可
//
public class SearchinRotatedSortedArray {

	public int search(int[] A, int target) {
		// 以下是binary search九章算法的模板
		int start = 0;
		int end = A.length - 1;
		int mid;
		while (start + 1 < end) {
			mid = start + (end - start) / 2;
			if (A[mid] == target) {
				return mid;
			}
			// 情况1 Astart比Amid小 说明mid在前半段
			if (A[start] < A[mid]) {
				// 如果进下一个if循环说明target在第一段且在start和mid之间
				// 在前四分之一
				if (A[start] <= target && target <= A[mid]) {
					end = mid;
				} else {// 说明target小于start或者大于mid  总之在后四分之三
					start = mid;
				}
			} else {// 这里打else的情况 说明A[start]大于A[mid] A[mid]在后半段
				if (A[mid] <= target && target <= A[end]) { // 说明A在后半段的后半段
															// mid和end之间
					start = mid;// 后四分之一
				} else {
					end = mid; // 在前四分之三
				}
			}
		}
		if (A[start] == target) {
			return start;
		}
		if (A[end] == target) {
			return end;
		}

		return -1;

	}

}
