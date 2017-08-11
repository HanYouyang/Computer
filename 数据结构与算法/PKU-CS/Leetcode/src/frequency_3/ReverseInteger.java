package frequency_3;

//Example1: x = 123, return 321
//Example2: x = -123, return -321 
//反转int 

//其实不用管符号什么的 这个
//一开始res是0       每次都把上次的结果×10+ x的最后一位 然后x再除10
public class ReverseInteger {
	public int reverse(int x) {

		int res = 0;
		//eg x=123
		//res=0×10+123%3=3
	     // x=12
		//res=30+2=32
		//res=320+1=321
		
		while (x != 0) {
			res = res * 10 + x % 10;
			x = x / 10;
		}
		return res;
	}

}
