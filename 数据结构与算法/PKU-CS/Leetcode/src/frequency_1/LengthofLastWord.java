package frequency_1;
//Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non-space characters only.
//
//For example,
//Given s = "Hello World",
//return 5. 


public class LengthofLastWord {
	  public int lengthOfLastWord(String s) {
	        
		 int length=0;
		 char[] chars=s.toCharArray();
		 //倒着从string最后往前检查
		 for(int i=s.length()-1;i>=0;i--){
			 if(length==0){
				 if(chars[i]==' '){
					 continue;
				 }else{
					 length++; // 找到第一个非空的 字母 计数开始
				 }
			 }else{
				 if(chars[i]==' '){
					 break;  //第二个空格了 说明最后一个词结束了 break for循环
				 }else{
					 length++;
				 }
			 }
		 }
		  return length;
	    }
}
