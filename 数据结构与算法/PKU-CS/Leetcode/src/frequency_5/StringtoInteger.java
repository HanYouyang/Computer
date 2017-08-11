package frequency_5;
import java.lang.reflect.Array;

//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
//
//spoilers alert... click to show requirements for atoi.
//Requirements for atoi:
//
//The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
//
//The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
//
//If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
//
//If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

//这题考研在要求很多的情况下 是否能做到条理清晰 有条不紊
public class StringtoInteger {
	public static int atoi(String str) {
		str = str.trim();
	long value=0;
	if(str.equals("")){return 0;}
	boolean isPositive=true;
	for(int i=0;i<str.length();i++){
      //在第一位的状态下先处理第一位  注意这种写法 很巧妙 逻辑很清晰
		if(i==0&&(str.charAt(i)=='+'||str.charAt(i)=='-')){
			if(str.charAt(i)=='-'){
				isPositive=false;
			}
			continue;} //continue的意思是 continue下面的都不执行了 直接进行下一轮循环
		//你看 利用ASCII 码比大小,你不用吧具体的码背出来
		//只要比0小 比9大的 都不是数字,避免了使用正则表达式
		//而且只有string可以用正则，char不可以直接用
		if(str.charAt(i)<'0'||str.charAt(i)>'9'){break;}
		//这里更巧妙了 因为是从左到右读取 上次的值x10+本次的值 就是current值
		//eg：123=  /1/1*10+2/12x10+3 =123
		value=10*value+str.charAt(i)-'0';
		}
	if(isPositive==false){value=value*-1;}
	if(value>Integer.MAX_VALUE){ return Integer.MAX_VALUE;
	}else if(value<Integer.MIN_VALUE){ return Integer.MIN_VALUE;
	}else{return (int)value; }//反正已经在正常int范围内了
	
	}
		


public static void main(String[] args) {
	System.out.print(atoi("  -233"));
}

}
