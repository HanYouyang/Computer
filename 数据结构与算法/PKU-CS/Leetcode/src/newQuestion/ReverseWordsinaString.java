package newQuestion;

import frequency_1.LengthofLastWord;
//Given an input string, reverse the string word by word.
//
//For example,
//Given s = " the sky is blue ",
//return " blue is sky the ". 

//
//What constitutes a word?
//A sequence of non-space characters constitutes a word.

//Could the input string contain leading or trailing spaces?
//Yes. However, your reversed string should not contain leading or trailing spaces.

//How about multiple spaces between two words?
//Reduce them to a single space in the reversed string.

public class ReverseWordsinaString {
//	正统的做法就是自己去逐个找到每个单词，从前往后还是从后往前其实都差不多，
//	都要翻转：要么是翻转字母（从后往前）、要么翻转单词（从前往后）。
//
//	这里给出的是用java自带的split方法，帮助我们以“ ”进行切割，代码看上去会比较简洁明了。
	 public String reverseWords(String s) {
		if(s==null||s.length()==0){
			return "";
		} 
		String[] array=s.split(" +");   //表示1~n个空格 split 2个 5个都split一次
		StringBuilder sb=new StringBuilder();
		for(int i=array.length-1;i>=0;i--){  //从数组最后一个词往前遍历
			sb.append(array[i]).append(" "); //放一个词后加一个空
		}
		return sb.length()==0?"":sb.toString().trim();
	  }
}
