package frequency_4;

import java.util.ArrayList;

//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return all possible palindrome partitioning of s. 

//就是把string的所有按照回文分割（有多种可能 ）
//比方说 aab 可以分成 aa b 和 a a  b 要求每个都是回文 也起来都是词
public class PalindromePartitioning {

	ArrayList<ArrayList<String>> result = new ArrayList<ArrayList<String>>();

	public ArrayList<ArrayList<String>> partition(String s) {
		result.clear();
		ArrayList<String> al = new ArrayList<String>();
		dfs(s, 0, al);
		return result;
	}

	// string的下标
	void dfs(String s, int start, ArrayList<String> al) {
		if (start == s.length()) { // 已经全部切光了 String全部用完
			result.add((new ArrayList<String>(al))); // 用al构造al
			return;
		}
		// 这个for循环很重要 考察的是string的string下标到i下标之间的事情
		// for循环遍历start~ start+1-1(i-1)开始直接到字段最后（所以是i<=s.length()）
		// 如果是start到i-1回文 就copy add到AL里 然后再递归调用本方法 然后 再把I当作新的start 在递归调用本方法
		for (int i = start + 1; i <= s.length(); i++) {
			if (isPalin(s, start, i - 1)) { // 如果字段里 的从start到i-1这一小段是回文就 加入
				al.add(s.substring(start, i));

				dfs(s, i, al);// 注意 涵盖substing的 al已经被传到递归的字方法里去了
				al.remove(al.size() - 1); // 所以这里要remove掉最新加的这个 因为 al相当于缓存
											// 如果不remove 这个for循环就会把
				// 这个string里从start到字段最后的所有回文会重复加 ！！这里al相当与一个缓存
			}
		}
	}

	// 检查这词是不是回文 从两头往当中比对 调用这方法的方法会把i j 安排到string头尾
	boolean isPalin(String s, int i, int j) {
		while (i < j) {
			if (s.charAt(i) != s.charAt(j)) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
