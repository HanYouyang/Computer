package frequency_3;

import java.util.HashMap;

//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//For example,
//Given [100, 4, 200, 1, 3, 2],
//The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
//
//Your algorithm should run in O(n) complexity. 

//最长连续序列。在一个没有sort的数组里找到|连续相邻|的元素  返回相邻的长度
 
public class LongestConsecutiveSequence {
	 public int longestConsecutive(int[] num) {
         HashMap<Integer,Boolean> hs=new HashMap<Integer, Boolean>();	        
	 for(int i:num){
		 hs.put(i, false);
	 }   
	 int maxLength=1;
	 for(int i:num){
		 if(hs.get(i)==true){ //如果等于true表示已经访问过了
			 continue;
		 }
		 int temp=i;
		 int current_maxLength=1;
		 //遍历到temp时候  再hashmap里找temp+1 和temp-1 看看有没有和temp连续的
		 //如果找到了就再temp++/temp-- 看最长能连多少
		 
		 while(hs.containsKey(temp+1)){
			 temp++;
			 current_maxLength++;
			 hs.put(temp, true); //表示这个++的temp所在的那一个Consecutive Sequence已经找过 不用再找
		 }
		 //这个while块跑完后,说明比temp大的Consecutive Sequence 已经都连上
		 //现在开始找比temp小的
		 temp=i;
		 while(hs.containsKey(temp-1)){
			 current_maxLength++;
			 temp--;
		   hs.put(temp, true);
		 }
		//此时包含temp的最长 Consecutive Sequence已经找到
		 //然后再把这次连到的长度和之前连到的长度取max 就行。
		 maxLength=Math.max(maxLength, current_maxLength);
		 
	 }
	 return maxLength;
	 }
}
