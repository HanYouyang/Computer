package newQuestion;
//Given an array of integers, every element appears three times except for one. Find that single one. 

//java里int始终占4个字节，32位，我们外层循环遍历32次，然后内层循环记录0-31位每一位出现的次数，内层循环结束后将结果取余于3即为当前位的值

//时间复杂度O(32 * n), 空间复杂度O(1)

// 比方说 
//1101
//1101
//1101
//0011
//0011
//0011
//1010   这个unique的   
//----
//4340  1的出现次数  
//1010  余3的话 就是那个唯一的数！
public class Singlenumber2 {
	 public int singleNumber(int[] A) {
	 int bit=0;
	 int result=0;
	 for(int i=0;i<32;i++){ //每次外循环 求得32位int里,1个位的总和
		 bit=0;
		 for(int j=0;j<A.length;j++){
			if(((A[j]>>i)&1)==1){  //比方说外循环第一次的时候0 那么就不往右平移 然后和1比 看看是不是1
				bit++;             //外循环第二次的时候往右移1位然后比第二位。
			}
		} 
		 bit=bit%3;
		 result=result|bit<<i;//每次外循环结束的时候就把bit取完余后的结果存到result里
	 }
	 return result;
	 }
	 
}
