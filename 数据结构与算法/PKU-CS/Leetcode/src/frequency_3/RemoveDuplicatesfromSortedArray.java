package frequency_3;
//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//For example,
//Given input array A = [1,1,2],
//
//Your function should return length = 2, and A is now [1,2]. 
//2个指针快慢遍历，当fast扫到2个相邻的不一样时候 slow 才动 
public class RemoveDuplicatesfromSortedArray {

	  public int removeDuplicates(int[] A) {
	      
		  if (A == null || A.length <= 1) {
		      return A == null ? 0 : A.length;
		    }
		    int index = 1; //index为慢指针
		    //i是快指针
		    for (int i = 1; i < A.length; ++i) {
		      if (A[i] != A[i - 1]) {//快扫描到不同时候 慢才加
		        A[index++] = A[i];
		      }
		    }
		    return index;}
	public static void main(String[] args) {


	}

}
