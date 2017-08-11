package frequency_1;

import java.util.ArrayList;
import java.util.HashMap;

//You are given a string, S, and a list of words, L, that are all of the same length. 
//Find all starting indices of substring(s) in S that is a concatenation of each word 
//in L exactly once and without any intervening characters.
//
//For example, given:
//S: "  barfoo   the      man"
//L: ["foo", "bar"]
//
//You should return the indices: [0,9].
//(order does not matter). 

//在场的string里面看看有没有短string数组里面的元素 如果有就返回起始字母的下标
// all starting indices of substring(s) in S that is a concatenation of each word in L exactly once
//要求字典里每个字都匹配上 
//without any intervening characters. 要求词典里的词当中不能被其他词隔开！！ barfoo  foobar 才可
//每个字典里的词长度一样
public class SubstringwithConcatenationofAllWords {
	public ArrayList<Integer> findSubstring(String S, String[] L) {
		ArrayList<Integer> result = new ArrayList<Integer>();
		HashMap<String, Integer> dict = new HashMap<String, Integer>();
		HashMap<String, Integer> found = new HashMap<String, Integer>();
		int m = L.length;
		int n = L[0].length();// 数组里词长度都相同
		// 把L里词和出现的次数都放到hashmap里 (L的值可能有重复)
		for (int i = 0; i < m; i++) {
			if (!dict.containsKey(L[i])) {
				dict.put(L[i], 1);
			} else {
				dict.put(L[i], dict.get(L[i]) + 1);
			}
		}
		// 因为要每个词都匹配上 所以 如果小于n*m就肯定匹配不上不用检查了
		for (int i = 0; i <= S.length() - n * m; i++) {
			found.clear();
			int j;
			for (j = 0; j < m; j++) { // j<m 一共有m个词再字典里 遍历每个词
				int k = i + j * n;// 外循环 到i位了 然后 内循环到第j个词了 又n是词长度
				// 所以当前检查的匹配位是长String的 k,k+n位. 匹配当前的j词
				String currSmallWord = S.substring(k, k + n);
				if (!dict.containsKey(currSmallWord)) {
					break; // 如果当前这个词没匹配上(截取的这段字典里没有) 直接break内循环 i++检查下一位。
				}
				if (!found.containsKey(currSmallWord)) {
					found.put(currSmallWord, 1);// 把这个词放到 found 表里
				} else {
					found.put(currSmallWord, found.get(currSmallWord) + 1);
				}
				if (found.get(currSmallWord) > dict.get(currSmallWord)) {
					break; // 如果已经招够这个词了 就break 内循环
				}
			}
			// 因为without any intervening characters. 要求词典里的词当中不能被其他词隔开！！
			// barfoo foobar 才可
			// 所以当词都找全的时候 才可以 把I算一个成功的起始点
			if (j == m) {
				result.add(i);
			}
		}

		return result;
	}
}