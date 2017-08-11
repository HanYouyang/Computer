package frequency_3;

import java.util.ArrayList;
//dfs---循环加递归  类似 subsets 
//和九章算法的模板很像 

public class LetterCombinationsofaPhoneNumber {
	public ArrayList<String> letterCombinations(String digits) {
		String[] dict = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs",
				"tuv", "wxyz" };
		ArrayList<String> result = new ArrayList<String>(); // 这个sb相当于一个排列
		if(digits==null||digits.length()==0){
			return result;
		}
		dfs(result, digits.length(), dict, digits, new StringBuffer());
		return result;
	}

	void dfs(ArrayList<String> result, int remain, String[] dict,
			String digits, StringBuffer sb) {
		// 先设定跳出recursion的条件
		if (remain == 0) { // 说明整个digits的每个一个数字都用完了
			result.add(sb.toString());
			return;
		}
		// 这里求得的是本次递归的数字对应的string 比方说 234
		// 我先获取2 然后for循环吧2的每个对应的char 放到sb里 然后再把sb 和34 传到递归方法里 这样就等于穿了 a 34 b 34
		// c 34 给下个递归方法
		// 然后a 34 再递归循环 ad4 ae4 af4 bd4 be4 bf4 c。。。。然后再递归到下一层 直到最后用完数字
		// add到arraylist里
		// 当然 因为是dfs 所以说是循环递归到最深返回了在循环第二次
		String s = dict[digits.charAt(0) - '0']; // char的数字转int 成为字典里的下标
		for (int i = 0; i < s.length(); i++) {
			sb = sb.append(s.charAt(i));
			dfs(result, remain - 1, dict, digits.substring(1), sb);
			sb.deleteCharAt(sb.length() - 1);
		}

	}

}
