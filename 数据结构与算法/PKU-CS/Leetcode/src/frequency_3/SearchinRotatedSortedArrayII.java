package frequency_3;
//Follow up for "Search in Rotated Sorted Array":
//What if duplicates are allowed?
//
//Would this affect the run-time complexity? How and why?
//
//Write a function to determine if a given target is in the array.
//因为是rotated 又是有重复 所以基本没法用bs了 所以就是遍历数组找target
public class SearchinRotatedSortedArrayII {
	 public boolean search(int[] A, int target) {
	       for (int i = 0; i < A.length; i ++){
	            if (A[i] == target) {
	return true;
	     }
	        }
	        return false;
	    }
	}