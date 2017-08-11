package frequency_2;

import java.util.ArrayList;
import java.util.Arrays;

import org.omg.CORBA.PUBLIC_MEMBER;

//Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//Each number in C may only be used once in the combination.
//
//Note:
//
//   All numbers (including target) will be positive integers.
//   Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//   The solution set must not contain duplicate combinations.
//
//For example, given candidate set 10,1,2,7,6,1,5 and target 8,
//A solution set is:
//[1, 7]
//[1, 2, 5]
//[2, 6]
//[1, 1, 6] 
//给一个数组 里面可以有重复元素，但是每个元素最多用一次 
//让你返回所有元素组合 which 组合的sum==target


public class CombinationSumII {
	  private ArrayList<ArrayList<Integer>> results;
	public ArrayList<ArrayList<Integer>> combinationSum2(int[] num, int target) {
	   		  if(num.length<1){
	   			  return results;
	   		  }
		  ArrayList<Integer> path=new ArrayList<Integer>();
		 //sort后从小到大排序 后面 for循环加的时候 不会重复。eg 13123 不sort会有2个123 123
		  Arrays.sort(num);
		  results=new ArrayList<ArrayList<Integer>>();
		  combinationSumHelper(path,num,target,0);
		  return results;
		  }
		                                               //path只有一个 
		  private void combinationSumHelper(ArrayList<Integer> path,int[] num,int sum,int pos) {
			  //dfs结束条件1  达到SUM 
			  if(sum==0){  //path里面东西丢到新的一个arraylist里面再加到 result里
				  results.add(new ArrayList<Integer>(path));
				 }
			  //  结束条件2 pos超过num长度了 or sum超过了
			  if(pos>=num.length||sum<0){
				  return;
			  }
			  int prev=-1;
			  for(int i=pos;i<num.length;i++){
				  if(num[i]!=prev){ //如果 本次的这个值和之前不一样
					  path.add(num[i]);
					  combinationSumHelper(path, num, sum-num[i], i+1);
					  prev=num[i];
					  path.remove(path.size()-1);
				  }
			  }
		}
    }

