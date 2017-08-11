package frequency_2;
//Determine whether an integer is a palindrome. Do this without extra space.
//判断注意一个数组是不是回文
//不允许有额外空间 看看是不是负数 (本题负数不是 但是面试时候你应该去问面试官)
//不看编程 最基础的逻辑,如果是回文的话 那么这个int 应该== reverse(int)
public class PalindromeNumber {
	  public boolean isPalindrome(int x) {
	        if(x<0){
	        	return false;
	        }
	        return x==reverse(x);
	    }

	  //eg: x=321
	  // result=0*10+ 1  x=32
	  // =1*10+2=12      x=3
	  //= 12*10+3 =123
	  
private int reverse(int x){
	int result=0;
	while(x!=0){
		result=result*10+ x%10;
		x=x/10;	}
return result;
}

}
