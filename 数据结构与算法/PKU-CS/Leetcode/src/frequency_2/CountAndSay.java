package frequency_2;
//The count-and-say sequence is the sequence of integers beginning as follows:
//1, 11, 21, 1211, 111221, ...
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//
//Given an integer n, generate the nth sequence.
//
//Note: The sequence of integers will be represented as a string. 

////题意是n=1时输出字符串1；n=2时，数上次字符串中的数值个数，因为上次字符串有1个1，
//所以输出11；n=3时，由于上次字符是11，有2个1，所以输出21；
//n=4时，由于上次字符串是21，有1个2和1个1，所以输出1211。
// n=5 时候就输出111221 one 1 one 2 two 1 n=6就是 31 2 211  
//6 answer312211 7 answer13112221依次类推，写个countAndSay(n)函数返回字符串。
public class CountAndSay {
	public  String countAndSay(int n) {
		//因为CountAndSay每次都是数count  countAndSay(n-1)的数字然后说本层 （dp思想）
      String lastSay="1"; //每次lastSay存的就是上层,初始lastSay就是 n=1时候说1
     
      while(n>0){
    	  StringBuilder sb=new StringBuilder(); //n层的say就存在sb里
    	  char[] oldChars=lastSay.toCharArray();//n-1的say换成char数组
    	  for(int i=0;i<oldChars.length;i++){ //遍历 lastsay  开始 count
    		  int count=1; //count是数有几个(count)个i
    		  while((i+1)<oldChars.length&&oldChars[i]==oldChars[i+1]){
    			  count++;  //这里数有几个 oldChars[i]
    			  i++;//遍历到下一位
    			 } 
    		  //while循环结束后 把当前count和oldChars[i] 加入sb 成为一部分say
    		  sb.append(String.valueOf(count)+String.valueOf(oldChars[i]));
    	  }
    	 lastSay=sb.toString();
        n--; //这样保证正好循环够次数 abs(1-n)=abs(n-1)
      }
      return lastSay;
    }
	
	public static void main(String[] args) {
		for(int i=0;i<=10;i++){
			System.out.println(i+" answer"+ new CountAndSay().countAndSay(i));
		}
	}
}
