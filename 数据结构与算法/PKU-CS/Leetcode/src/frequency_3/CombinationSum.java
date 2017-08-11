package frequency_3;

import java.util.ArrayList;
import java.util.Arrays;

//Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//The same repeated number may be chosen from C unlimited number of times. 
//
//All numbers (including target) will be positive integers.
//Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//The solution set must not contain duplicate combinations.
//For example, given candidate set 2,3,6,7 and target 7,
//A solution set is:
//[7]
//[2, 2, 3] 
//就是给你一个数组 然后 从这个数组里 选数字（一个数字可以重复用） 他们的和是 指定的那个数字
//和 2-Sum 3-sum的题类似。|||都用九章的 combination/subset的模板做|||

public class CombinationSum {
	public ArrayList<ArrayList<Integer>> combinationSum(int[] candidates,
			int target) {

		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
		if (candidates == null) {
			return result;
		}
		ArrayList<Integer> path = new ArrayList<Integer>();
		// result要求返回的都是递增的组合，那么我就sort下原始数组好了
		Arrays.sort(candidates);
		subsetsHelper(candidates, target, path, 0, result);
		return result;
	}

	private void subsetsHelper(int[] candidates, int target,
			ArrayList<Integer> path, int index,
			ArrayList<ArrayList<Integer>> result) {
		if (target == 0) {
			result.add(new ArrayList<Integer>(path));
			return;
		}
		int prev = -1;// prev指的是 上一次用了那个数
		// bfs了 循环加递归 每一个char去循环出去
		for (int i = index; i < candidates.length; i++) {
			if (candidates[i] > target) {
				break;
			}
			// 去重复 这个去重是怎么工作的呢，比方说数组是{2,2,4,4} 然后target是6.
			// 如果出了第一个2 第一个4 , 如果再来第二个2 第一个4   不就是 2个{2,4}重复了么
			// 注意这个	prev = candidates[i];是在递归方法之后的就是 第一次dfs全部遍历完了 就是第一个2+后面元素可能的解 已经都有的时候 
			// 如果第二次for循环 i=1的时候 candidates[1]==prev 还是2 那么 这个 2和后面 元素组合的可能的解 和第一个元素出来的解都是重复的
			// 所以就直接continue了	
			if (prev != -1 && prev == candidates[i]) {	
				continue;
			}
			path.add(candidates[i]); // 请注意 这个i是index 就是说递归的下一个方法还是index位
										// 因为一个数可以用多次
			subsetsHelper(candidates, target - candidates[i], path, i, result);
			path.remove(path.size() - 1);
			prev = candidates[i];
		}

	}
	public static void main(String[] args) {
		int[] candidates={2,3,6,7};
		//combinationSum(candidates, 7);
	}
}
