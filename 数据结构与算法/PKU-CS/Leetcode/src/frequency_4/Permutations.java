package frequency_4;

import java.util.ArrayList;

//
//Given a collection of numbers, return all possible permutations.
//
//For example,
//[1,2,3] have the following permutations:
//[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
//给你一个数组 让你返回所有不同的组合
//这就是 求字符串全排列的问题
// 这是典型的递归求解问题，递归算法有四个特性：

//必须有可达到的终止条件，否则程序陷入死循环
//子问题在规模上比原问题小
//子问题可通过再次递归调用求解
//子问题的解应能组合成整个问题的解
//参考cc150 8——4
public class Permutations {

	public ArrayList<ArrayList<Integer>> permute(int[] num) {

		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
		ArrayList<Integer> temp = new ArrayList<Integer>();
		if (num == null) {
			return null;
		}
		// num为里面只有一个元素 返回这个元素
		if (num.length == 1) {
			temp.add(num[0]);
			result.add(temp);
			return result;
		}
		int[] numless = new int[num.length - 1];
		int currentFirst = num[0];
		System.arraycopy(num, 1, numless, 0, num.length - 1);
		ArrayList<ArrayList<Integer>> retrieving = permute(numless);

		for (ArrayList<Integer> combo : retrieving) {
			// 每个arraylist都插入上次保存的头
			// //length()+1的原因是 比方说 0插入 abc a之前要插入 c之后也要插入 所以要+1
		 
			ArrayList<Integer> tep=(ArrayList<Integer>) combo.clone();
			for (int i = 0; i < combo.size() + 1; i++) {
				combo.add(i, currentFirst);
				result.add(combo);
			 //这样每个combo进第二个for循环加current的时候，备份一次，就避免了加current后引起的combo.size变化 导致的错误
				//为什么 不是remove i 呢 因为可能会引发内部的优化的错误 可能会报错。
				//所以这样保留原始的combo
				combo = (ArrayList<Integer>) tep.clone();
			}
		}
		return result;
	}

	public static void main(String[] args) {
		int[] num = { 0,1,3,5};
		System.out.println((new Permutations()).permute(num));

	}

}
