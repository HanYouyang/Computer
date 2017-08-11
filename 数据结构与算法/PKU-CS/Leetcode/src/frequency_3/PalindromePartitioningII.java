package frequency_3;

//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return the minimum cuts needed for a palindrome partitioning of s.
//
//For example, given s = "aab",
//Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. 
//如果要把这个割成每部分都是回文 最小割几刀

public class PalindromePartitioningII {
	// 九章算法 2 sequence dp模板
	// 先向PalindromePartitioning 做一个2sequence dp 预处理
	//在 isPalindrome中 如果 [x][y]是ture 表示 String s 的charAt(x) 到 charAt(y)是回文(前闭后闭)
    //因为 每个字母都是自己的回文 所以 这个2sequence dp的base case就是 [i][i]就是true
	//然后 如果char At i=i+1 那么 aa bb也是回文 然后 isPalindrome[i][i + 1] = (s.charAt(i) == s.charAt(i + 1)); 
	// 然后 /start和start+length这一段是不是回文？（前闭后闭）
	// 如果 start+1和start+length-1 是回文
	//并且 s.charAt(start)=s.charAt(start+length) 那么 start,start+length也是回文
	//eg： baab中 如果aa是回文那么又 b=b 所以baab也是回文
	//这个dp是从对角线中间往两边扩散
	//然后再在矩阵里里面找min cut 做一个1维dp  cut[i] 表示 string到i位位置切成回文的最小切割术+1
//	for (int j = 1; j <= i; j++) {
//		 //如果string的i-j位到i-1位是回文      eg i=5 j=2 那么就是String(3,4)是palindrom
//			if (isPalindrome[i - j][i - 1]
//				//并且 cut[3]是能切成回文的 那么表示cut[i]也能切成回文
//					&& cut[i - j] != Integer.MAX_VALUE) {
//				cut[i] = Math.min(cut[i], cut[i - j] + 1);
	
	
//     a     a      b   //这矩阵只有又上三角是有意义的。因为[0],[1] 代表 aa  [1][0]啥都不代表
//  a true  true  false 
//  a false true  false 
//  b false false true 


	private boolean[][] getIsPalindrome(String s) {
		boolean[][] isPalindrome = new boolean[s.length()][s.length()];
		// 初始dp
		//在 isPalindrome中 如果 [x][y]是ture 表示 String s 的charAt(x) 到 charAt(y)是回文 前后都是闭区间[][]
		// 每个字母都是他自己的回文
		for (int i = 0; i < s.length(); i++) {
			isPalindrome[i][i] = true;
		}
		for (int i = 0; i < s.length() - 1; i++) {
			// 如果s.charAt(i) == s.charAt(i + 1) eg aa bb cc
			//那么 [0][1],[2][3],[4][5] 也都是回文
			isPalindrome[i][i + 1] = (s.charAt(i) == s.charAt(i + 1));

		}

		for (int length = 2; length < s.length(); length++) {
			// start为回文开始的char length为回文长度 
			for (int start = 0; start + length < s.length(); start++) {
	           //start和start+length这一段是不是回文？（前闭后闭）
				// 如果 start+1和start+length-1 是回文
				//并且 s.charAt(start)=s.charAt(start+length) 那么 start,start+length也是回文
				//eg： baab中 如果aa是回文那么又 b=b 所以baab也是回文
				//这个dp是从对角线中间往两边扩散
				isPalindrome[start][start + length] = isPalindrome[start + 1][start
						+ length - 1]
						&& s.charAt(start) == s.charAt(start + length);
			}
		}

		for (int i = 0; i <isPalindrome.length; i++) {
			 System.out.println("");
			 for (int j = 0; j < isPalindrome[0].length; j++) {
			 System.out.print(isPalindrome[i][j]+" ");
			 }
			}

		return isPalindrome;

	}

	public int minCut(String s) {
		if (s == null || s.length() == 0) {
			return 0;
		}

		int[] cut = new int[s.length() + 1];
		boolean[][] isPalindrome = getIsPalindrome(s);
		cut[0] = 0;// 一维dp cut[i]表示 当S到charAt(i)位时候 最少几刀能看成全是回文的
		for (int i = 1; i <= s.length(); i++) {
			cut[i] = Integer.MAX_VALUE;
			for (int j = 1; j <= i; j++) {
			 //如果string的i-j位到i-1位是回文      eg i=5 j=2 那么就是String(3,4)是palindrom
				if (isPalindrome[i - j][i - 1]
					//并且 cut[3]是能切成回文的 那么表示cut[i]也能切成回文
						&& cut[i - j] != Integer.MAX_VALUE) {
					cut[i] = Math.min(cut[i], cut[i - j] + 1);
				}
			}
		}
		return cut[s.length()] - 1;
	}
public static void main(String[] args) {
	new PalindromePartitioningII().minCut("aab");
}
}
