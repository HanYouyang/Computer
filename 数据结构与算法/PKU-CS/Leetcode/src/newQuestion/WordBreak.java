package newQuestion;

import java.util.Set;
//Given a string s and a dictionary of words dict, determine 
//if s can be segmented into a space-separated sequence of 
//one or more dictionary words.
//
//For example, given
//s = "leetcode",
//dict = ["leet", "code"].
//
//Return true because "leetcode" can be segmented as "leet code". 
//要切出来的所有东西都在词典里才算true

 

public class WordBreak {
	// 也是预处理一个一维数组
	// dp[i]的意思是这个string从0位到i位是可以(以某种割法能valid break的) 然后再从i的后面判断是否能valid break
	// 就好象公交车换成，前面已经换成的3辆车可以不用管 。你只要管后面的能合法换到终点站就可以了
	//  leetcode
	// 012345678 //dp[0] 是DP基础状态 表示dp[0]之前都是ok的了 只用从1开始考虑问题就可以了
 // dp[TFFFTFFFT] return dp[8]

	// 大厨写的简单方法 基础DP 便于理解 优化方法见后
	public boolean wordBreak(String s, Set<String> dict) {
		int length = s.length();
		boolean[] dp = new boolean[length + 1];
		dp[0] = true; //这个0是很重要的DP[0]是这个DP的初始条件 相当于 0位（和之前。。如果有的话 是可分的）所以你从1开始考虑问题就好了 所以i=1 开始循环
		
		for (int i = 1; i <= length; i++) {
				for (int j = 0; j < i; j++) {
	//这个if判断就相当于 当dp[j]是true 时候 表示j和j之前的词是valid word ，比方说第一个内循环就是 substring(0,1)返回的是 l 然后l词库里没有 
					//然后j==i 然后就下一次外循环，然后直到j=0,i=4的时候 词典里有leet 所以 dp[4]就是 ture  以此类推
					if (dp[j] && dict.contains(s.substring(j, i))) { // (eg,substring (1,3) 0位char就会被遗漏  所以从0位开始
					dp[i] = true;
					break; 
				}
			}
		}
		return dp[length];
	}

}






















//
// public boolean wordBreak(String s, Set<String> dict) {
// if (s == null || s.length() == 0) {
// return false;
// }
// // 这方法是求字点里最长的字是几个字母
// int maxLength = getMaxLength(dict);
// boolean[] canSegment = new boolean[s.length() + 1];
// //这个0是很重要的canSegment[0]是这个DP的初始条件
// canSegment[0] = true;
// for (int i = 1; i <= s.length(); i++) {
// canSegment[i] = false;
// // 内循环是循环在1-i位 并且1-i的长度不大于maxlength()
// // 然后看看j位到i位这个subsring可以割么 如果不可以就j后移一位
// for (int j = 1; j <= maxLength && j <= i; j++) {
// //[i-j] 4-1=3 第二轮 4-2=2 第三轮 4-3=1
// if (!canSegment[i - j]) {
// continue;
// }
//
// String word = s.substring(i - j, i);
// if (dict.contains(word)) {
// canSegment[i] = true;
// break;
// }
// }
// }
// return canSegment[s.length()];
// }
//
// private int getMaxLength(Set<String> dict) {
// int maxLength = 0;
// for (String word : dict) {
// maxLength = Math.max(maxLength, word.length());
//
// }
// return maxLength;
// }
