package frequency_2;
//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice?
//
//For example,
//Given sorted array A = [1,1,1,2,2,3],
//
//Your function should return length = 5, and A is now [1,1,2,2,3]. 

//remvoe 1是简单去重 双指针即可
//remove 2是 最多允许两个重复的 
//既然如此 还是要利用sorted的特性 +双指针 size(左) 和  i(右)  
//浮动窗口 从左往右扫 扫到符合条件的size++
//因为size是下标  最后返回长度size+1;

public class RemoveDuplicatesFromSortedArrayII {
	
	public int removeDuplicates(int[] A) {
		if(A==null||A.length==0){
			return 0;
		}
		int size=0;
		
		for(int i=1;i<A.length;i++){
		//A[i]==A[size]&&A[size-1]==A[size] 就是size左边已经有2个相同的数了 那么这次i就不能插了
			if(A[i]==A[size]&&A[size-1]==A[size]&&size>0){
				continue;
			}
			A[++size]=A[i];
		}
		return size+1;
	 }
}
