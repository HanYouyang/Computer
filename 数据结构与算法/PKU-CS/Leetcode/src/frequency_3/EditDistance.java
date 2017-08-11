package frequency_3;

//Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
//
//You have the following 3 operations permitted on a word:
//
//a) Insert a character
//b) Delete a character
//c) Replace a character

//把A词变位B词需要最少几步？
//这题思路和机器人左上到右下是一样的  预处理矩阵 
//你可以想象在一个矩阵里 word1是i长度 word2 是j长度 那么矩阵里 matrix[i][j]的值就是 word1 i位到word2 j位变换的距离  
//那比方说 矩阵里[i-1][j-1]就是 word1 i-1位到word 2 j-1位变换的次数（distance）
//那么 预处理完这个矩阵后到时候只要return 会矩阵的值就可以 （如果word1某位和word2某位的字符是一样的 那么 就不用操作）
//     比方说a换到bbc就是3次。 a换b 加一个b 再加一个b

//  那么结果就是distance[4][4] 就是
//0 1 2 3 4 
//1 1 2 3 4 
//2 2 2 3 4 
//3 3 3 3 4 
//4 4 4 4 4 
public class EditDistance {
	public int minDistance(String word1, String word2) {
		if (word1 == null || word2 == null) {
			return -1;
		}
		// [0][0] 是没东西的 所以要从[1][1]开始
		// intialize
		int[][] distance = new int[word1.length() + 1][word2.length() + 1];
		for (int i = 0; i <= word1.length(); i++) {
			distance[i][0] = i;
		}
		for (int j = 0; j <= word2.length(); j++) {
			distance[0][j] = j;
		}

		// dp
		for (int i = 1; i <= word1.length(); i++) {
			for (int j = 1; j <= word2.length(); j++) {
				// 下一个词无非要么从[i-i][j]过来要么从[i][j-1]过来 那个少就取那个因为求minimal
				distance[i][j] = Math.min(distance[i - 1][j],
						distance[i][j - 1]) + 1; // 如果char不一样就不用变换了
				distance[i][j] = Math
						.min(distance[i][j],
								distance[i - 1][j - 1]
										+ (word1.charAt(i - 1) == word2
												.charAt(j - 1) ? 0 : 1));

			}
		}
		
		//
		 for (int i = 0; i <distance.length; i++) {
		 System.out.println("");
		 for (int j = 0; j < distance[0].length; j++) {
		 System.out.print(distance[i][j]+" ");
		 }
		}

		
return distance[word1.length()][word2.length()];
	}

	public static void main(String[] args) {
		System.err.println( new EditDistance().minDistance("bbbb", "aaaa"));
		
	}
}
 