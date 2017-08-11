package frequency_4;

import javax.naming.spi.DirStateFactory.Result;

//Given an array of integers, every element appears twice except for one. Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//一个数组里面 都是一堆一堆相同的数字，但是只有一个单个的 
//不用另外空间(其实指的是空间复杂度是0(1))

//用0去异或数组里所有东西
//比方说0^1101=1101    1101^1101=0000  所以成对的异或最后都是0了
//所以最后变成0^单一的那个 而 0^任意=任意 所以直接return
public class SingleNumber {

	public int singleNumber(int[] A) {
	  
	    int result=0^A[0];
		for(int i=1;i<A.length;i++){
	      result=result^A[i];
	     }
	   return result; }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
