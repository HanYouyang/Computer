package frequency_2;

import java.util.HashSet;

//Given a string, find the length of the longest substring without repeating characters. 
//For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
//For "bbbbb" the longest substring is "b", with the length of 1.
//“滑动窗口”的做法，有点类似maximum subarray的滑动窗口。 比方说 abcabccc 当你右边扫描到abca的时候你得
//把第一个a删掉得到bca 然后"窗口"继续向右滑动，每当加到一个新char的时候，
//左边检查有无重复的（用hashmap）然后如果没重复就能正常加 有重复 的话 就左边扔掉一部分
//（从最左到重复char这段扔掉） 在后在这个过程中记录最大的

//hashset记录已经存在的char    窗口 本身并不在数组里维护
public class LongestSubstringWithoutRepeatingCharacters {
	public int lengthOfLongestSubstring(String s) {
 if(s==null||s.length()==0){
	 return 0;
 }
 HashSet<Character> set=new HashSet<Character>();
 int leftBound=0;
 int max=0;
 for(int i=0;i<s.length();i++){
	 //窗口右侧扫到重复字符了 进if块
	 if(set.contains(s.charAt(i))){
		 //这个while循环为何要这么写
		 //eg:　　ａｂｃｄｅｄ　然后窗口扫到ｄ的时候
		 //得把abc都从hashset里删了
		 while(leftBound<i&&s.charAt(leftBound)!=s.charAt(i)){
			 set.remove(s.charAt(leftBound));
			 leftBound++;  //while 里面删abc
		 }
		 leftBound++; //因为d本来是要加的 所以也不用删了再加了， //left从2到3
		 
	 }else{//没有重复的
		 set.add(s.charAt(i));
		 max=Math.max(max,i-leftBound+1);//i-leftBound+1  当前窗口长度
	 }
 }
 
 return max;
 
	}
}
