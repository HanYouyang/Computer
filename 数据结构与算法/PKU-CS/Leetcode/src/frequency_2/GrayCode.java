package frequency_2;

import java.util.ArrayList;

//The gray code is a binary numeral system where two successive values differ in only one bit.
//
//Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
//
//For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
//
//00 - 0
//01 - 1
//11 - 3
//10 - 2
//
//Note:
//For a given n, a gray code sequence is not uniquely defined.
//
//For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

//格雷码转换  输入二进制长度  输出 一条从头转到底的路径
//格雷码定义就是在二进制数字变换时候 不管你有多少bit 每次只能变一个 bit
//像上面的例子一样  如果是2位bit 那么一共就是2*2种=4种数字 你返回的结果一定要把四种数字的int值都返回 但是每2个之间最多变一位 bit
//比方说 n=4时候 需要返回16个数字 从0000开始 但是相邻数字 每次之变1 bit 。 返回一种顺序即可。
//00 - 0
//01 - 1
//11 - 3
//10 - 2
//
//Try one more example, n = 3:
//
//000 - 0
//001 - 1
//011 - 3
//010 - 2
//110 - 6
//111 - 7
//101 - 5
//100 - 4 
//看出规律了么 n = 2: [0,1,3,2] and n=3: [0,1,3,2,6,7,5,4]
//前面是一样的  后面6754 就是  [2+4,3+4,1+4,0+4] 0132反过来2310 +4  (3-1)^2
//所以每次递归找出前一层然后再反过来 +(n-1)^2即可  

public class GrayCode {
	  public ArrayList<Integer> grayCode(int n) {
	    ArrayList<Integer> result = new ArrayList<Integer>();
		  if(n==0){  //递归的结束条件 0bit就是0 就这么规定
			  result.add(0);
			  return result;
		  }
		 ArrayList<Integer> preResult=grayCode(n-1);
		 result.addAll(preResult);
		 //新加的部分把上一层结果反着加。
		 for(int i=preResult.size()-1;i>=0;i--){
			result.add(preResult.get(i)+(int) Math.pow(2, n-1));
		 }
		return result;  
	    }
}
