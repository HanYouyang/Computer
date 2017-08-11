package frequency_2;

import java.util.Arrays;

//Given a non-negative number represented as an array of digits, plus one to the number.
//                                        (位数最大的)
//The digits are stored such that the most significant digit is at the head of the list.
//一个数组eg[9,9,9] 代表999 然后要+1 最后一数组的形式返回 
//做法 本位 进位 和 linkedlist相加思路差不多
//注意 当 +1后n位变n+1位后 要返回一个长度更长的新数组
public class PlusOne {
	 public int[] plusOne(int[] digits) {
	   if(digits==null){return null;}
	   int current=digits.length-1; //eg [9,9,9] 是从最后一位加起。
	 boolean overflow=false;   

	 while(current>=0){
		 if(digits[current]+1>9){
			 digits[current]=0;
			 overflow=true;
			current--;
		 }else{     //4 7 9  +1 之后 4 7 0  7+1=9《0 所以 return 480
			 digits[current]=digits[current]+1;
			 return digits; 
		 }
	 }
		 //如果到这里 还没return 说明 首位 +1大于0  需要扩充位数
		 if(overflow){
			 int[] newDigits=new int[digits.length+1];
			 System.arraycopy(digits,0,newDigits,1,digits.length);
			 newDigits[0]=1;
			 newDigits[1]=0;
			 return newDigits;
			 
			 
		 }
		 
	 
	return digits;
		  }
	 public static void main(String[] args) {
		 int[] digits = {9,9,9};  
	//   int[] digits = {0};  
	     System.out.println(Arrays.toString(new PlusOne().plusOne(digits))); 		
	}
 
}

