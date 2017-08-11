package frequency_2;

import java.util.HashMap;

//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
//For example,
//S = "ADOBECODEBANC"
//T = "ABC"
//
//Minimum window is "BANC".
//
//Note:
//If there is no such window in S that covers all characters in T, return the emtpy string "".
//
//If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 
//在source里面找能包含target所有字符 的最小的那段(子集)

//1.先把target里有那些char 各有几个 存到hashmap里
//2.然后再建一个minWindow的hashmap存这个Source -window sliding区间里有哪些char 几个（当然不在target里的就continue不要存了）
//3.然后for循环遍历Source, window的leftbound就是lb rightbound就是for循环的i。
//4.如果charAt(i) 不在t里就continue 在的话就存入minWindow的hashmap
//5.记录现在在window里的char的种类和数量是否已经够了 (见右边格子)
//6.如果够了 tCount == T.length() window 里的char的数量和种类都满足 target了 所以开始
//7.压缩window求 minwindow。此时lb为0 7.1a如果S.charAt(lb) 不是target里的char 直接lb++ 。
//7.1b如果S.charAt(lb) 在minWindow里的数量超过target的数量 也lb++ （minwindow里此char要-1）然后continue继续大for循环。
//8.如果7.1a已经循环完了但是又不是7.1b的执行条件 就break掉大的for循环 此时已经找到。然后minWindow = S.substring(leftBound, i + 1); 
//(记得检查window 长度合法性 ) 然后如果是null的话return ""


public class MinimumWindowSubstring {
	public String minWindow(String S, String T) {
		if (S == null || S.length() == 0) {
			return S;
		}
		if (T == null || T.length() == 0) {
			return "";
		}
		// 吧target里面的char 的种类 个数 都放到hashmap里
		HashMap<Character, Integer> charInTCounter = new HashMap<Character, Integer>();
		for (int i = 0; i < T.length(); i++) {
			Character c = T.charAt(i);
			if (charInTCounter.containsKey(c)) {
				charInTCounter.put(c, charInTCounter.get(c) + 1);
			} else {
				charInTCounter.put(c, 1);
			}
		}

		// 用九章 window sliding的做法 window的左边就是leftBound 右边就是i
		// 这个minWindowCounter是存 出现在window sliding里的window的char里面都有吗 有几个
		HashMap<Character, Integer> minWindowCounter = new HashMap<Character, Integer>();
		String minWindow = null;
		int tCount = 0;
		int leftBound = 0;
		for (int i = 0; i < S.length(); i++) {
			Character c = S.charAt(i);
			// 如果s的第i个char是 target里没有 继续看下一个char
			if (!charInTCounter.containsKey(c)) {
				continue;
			}
			if (minWindowCounter.containsKey(c)) {
				minWindowCounter.put(c, minWindowCounter.get(c) + 1);
			} else {
				minWindowCounter.put(c, 1);
			}
			// 比方说 T是ccc 然后s是 cbcccdd 然后第一个c的时候 tCount++ 第二个t的时候tCount
			// 第三个T时候也是tCount++ 所以 如果全包含的情况下 tCount应该等于 target的length
			if (minWindowCounter.get(c) <= charInTCounter.get(c)) {
				tCount++;
			}

			// 双指针，动态维护一个区间。尾指针不断往后扫，当扫到有一个窗口包含了所有T的字符后，
			// 然后再收缩头指针，直到不能再收缩为止。最后记录所有可能的情况中窗口最小的

			// 这个表明 target里面的char在source里面都有了 (!注意 此时不一定扫完整个source了)
			if (tCount == T.length()) {
				
				// 初始leftBound=0
				// 如果当前lb所在的那个char不是target里的字母 直接向右 并且循环
				while (leftBound < S.length()) {
					Character ch = S.charAt(leftBound);
					if (!charInTCounter.containsKey(ch)) {
						leftBound++;
						continue;
					}

					// 如果到ch( ch=S.charAt(leftBound);)的时候ch已经比target里要求的数量还多了
					if (minWindowCounter.get(ch) > charInTCounter.get(ch)) {
						minWindowCounter.put(ch, minWindowCounter.get(ch) - 1);
						leftBound++;// 那么当前的leftbound++就可以被跳过
						continue;
					}
					// 上面这2个if块就是为了缩小这个window的
					// 如果已经缩到不能缩了
					break;// for循环 已经有结果了
				}
				// 检查leftbound 和rightbound(i)的合法性
				if (minWindow == null || i - leftBound + 1 < minWindow.length()) {
					minWindow = S.substring(leftBound, i + 1);
				}
			}
		}

		if (minWindow == null) {
			return "";
		}
		return minWindow;

	}
}
