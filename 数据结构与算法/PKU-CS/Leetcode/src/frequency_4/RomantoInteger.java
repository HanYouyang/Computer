//Given a roman numeral, convert it to an integer.
//(eg:2123=MMCXXIII)
//Input is guaranteed to be within the range from 1 to 3999.
//给罗马数字的string 然后求integer
package frequency_4;

//但是和刚刚那题I转R有点不一样
//罗马字符可能是单独是一个字母表示 或者两个在一起是一个数字
// 
//如果当前比前一个大，说明这一段的值应该是当前这个值减去上一个值。比如IV = 5 – 1
//否则，将当前值加入到结果中，然后开始下一段记录。比如VI = 5 + 1， II=1+1
//

public class RomantoInteger {
	 public int romanToInt(String s) {
 
	   int result=0;
	 char[] array=s.toCharArray();
	 for(int i=0;i<array.length;i++){
		//这里体现第十行逻辑
		   //防止i-1数组越界      //如果后一位比前一位大这一段的值应该是当前这个值减去上一个值。比如IV = 5 – 1
		 if(i>0&&getChar(array[i])>getChar(array[i-1])){
			 result=result+(getChar(array[i])-2*getChar(array[i-1]));
		 }else{//正常换算 计数
			 result=result+getChar(array[i]);
		 }
	 }
	 
	 return result;
	 }
	 
	 public int getChar(char c){
		    switch(c){
		        case 'I': return 1;
		        case 'V': return 5;
		        case 'X': return 10;
		        case 'L': return 50;
		        case 'C': return 100;
		        case 'D': return 500;
		        case 'M': return 1000;
		    }
		    return 0;
	 
	 
}}
