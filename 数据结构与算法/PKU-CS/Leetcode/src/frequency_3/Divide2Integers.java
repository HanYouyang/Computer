package frequency_3;

//Divide two integers without using multiplication, division and mod operator. 
//让两个整数相除 不用 乘 除 和余 %
//就说说可以用位运算 减法
//注意 位运算>>1就是往后移一位 除以2
public class Divide2Integers {
	// 被除数 //除数
	public int divide(int dividend, int divisor) {
      //返回的是int 所以去掉小数
		if (divisor == 0 || dividend == 0) {
			return 0;
		}
		// 2个都正/副 false 不一样才true
		boolean nagative = (dividend < 0) ^ (divisor < 0);
		long a = Math.abs(dividend);
		long b = Math.abs(divisor);
		int finalCount = 0;
		int count = 0;
		//注意这个while循环 是让被除数的1倍 2倍 4倍 8倍去和除数去比
		//count做商的
		while (a >= b) { // 被除数大于除数
			count = 1;
			b = Math.abs(divisor);
			long sum = b;//b是除数
            //logn的算法，每次将被除数翻倍，这样加快计算的速度。 
			//注意这个的判断 是sum+sum<=a 不是sum小于等于a
			//所以跳出这个while循环的时候是sum>=a/2 
			while (sum + sum <= a) {
				//每次将被除数翻倍，这样加快计算的速度。 
				sum = sum + sum;
				count = count + count;
			}
			//然后a-sum 剩下的a如果大于等于b的话继续大while循环
			a=a-sum;
			finalCount=finalCount+count;//把这部分商加入总商
		}
			if (nagative) {
				return 0 - finalCount;
			} else {
				return finalCount;
			}
		
	}
	
	//ps 好像在oj里 用math。abs就过不了 用这个就能过
	 private long abs(int num){  
	        if(num < 0){  
	            return -(long)num;  
	        }  
	        return (long)num;  
	    }  


	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
