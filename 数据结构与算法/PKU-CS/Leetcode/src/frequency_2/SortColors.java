package frequency_2;

//Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively. 
//1个只有012的乱序数组 按照012 排序 
//O(n)解法 三个指针
//3point 一次遍历可以搞定。0的指针从头开始 2的指针从尾巴开始   扫描到0就 curr和0指针的数换位置 然后0指针++ 
//扫描到2就就curr和2换位置 然后2--  如果等A[curr]=1 就curr++
public class SortColors {
	public void sortColors(int[] A) {
		 if(A==null||A.length==0){
	            return;
	        }
	        int zero=0;
	        int two=A.length-1;
	        int i=0;
	        while(i<=two){
	            if(A[i]==0){
	                swap(A,zero,i);
	                zero++;
	                i++;
	            }else if(A[i]==1){
	                i++;
	            }else{
	                swap(A,two,i);
	                two--;
	            }
	            
	        }
	    }

	public void swap(int[] A, int a, int b) {
		int temp = A[a];
		A[a] = A[b];
		A[b] = temp;
	}

}
