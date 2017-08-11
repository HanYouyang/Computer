package frequency_4;

import java.util.ArrayList;

//Given two binary strings, return their sum (also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100". 
//不能用系统自带的 Integer.parseInt(a, 10);  因为如果string超过32位就溢出int了 
//可以用string buffer做   (像linkedlist add 那题一样） 本位和进位 0+0=0  1+1=0进1  1+0/0+1 =1
public class BinaryAdd {
	// 因为 要从低位加到高位 所以 应该从string的最后位往前面加 加到一个stringbuffer里就可以了
	// 最后stringbuffer在reverse回去
	
	//！！判断二进制加法后是0还是1
	// carry位是/2  value位数%2
	// eg:1+1=2  2/2=1  所以carry位是1    2%2=0 所以value位是0
	
	public String addBinary(String a, String b) {
		int firstLen = a.length() - 1;
		int secondLen = b.length() - 1;
		StringBuffer result = new StringBuffer();
	int value=0;
	int carry=0;
		while (firstLen > -1 && secondLen > -1) {
		value=(((a.charAt(firstLen)-'0')+(b.charAt(secondLen)-'0'))+carry)%2;
		carry=((a.charAt(firstLen)-'0')+(b.charAt(secondLen)-'0')+carry)/2;
			result.append(value);
			firstLen--;
			secondLen--;
        }
		
		if(firstLen<0){
			while(secondLen>-1){
				value=(((b.charAt(secondLen)-'0'))+carry)%2;
			 carry=(((b.charAt(secondLen)-'0'))+carry)/2;
					result.append(value);
					secondLen--;
			}
		}else{
			while(firstLen>-1){
				value=(((a.charAt(firstLen)-'0'))+carry)%2;
			 carry=(((a.charAt(firstLen)-'0'))+carry)/2;
					result.append(value);
					firstLen--;
			}
		}
		//要注意边际情况 如果 两边都没了 但是还有一个额外的进位carry到前面 
		if(carry!=0){result.append(carry);}
result=result.reverse();
	return result.toString();}

	public static void main(String[] args) {
		System.out.print((new BinaryAdd()).addBinary("11", "1"));
	}

}

// 不能这么做 因为 给你的string可能超过32位 溢出int 而且这个做法出来的结果也不对
// int first=Integer.parseInt(a, 10);
// int second=Integer.parseInt(b, 10);
// int sum=first+second;
// String result=Integer.toBinaryString(sum);
// return result;