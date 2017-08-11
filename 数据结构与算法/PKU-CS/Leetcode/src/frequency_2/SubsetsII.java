package frequency_2;

import java.util.ArrayList;
import java.util.Arrays;
//Given a collection of integers that might contain duplicates, S, return all possible subsets.
//
//Note:
//
//   Elements in a subset must be in non-descending order. //所以要sort
//   The solution set must not contain duplicate subsets.
//
//For example,
//If S = [1,2,2], a solution is:
//
//[
// [2],
// [1],
// [1,2,2],
// [2,2],
// [1,2],
// []
//]
//九章算法模板 和premutation 2很像 就是不用全部返回 每层单独丢结果给result即可
public class SubsetsII {
	public ArrayList<ArrayList<Integer>> subsetsWithDup(int[] num) {
 ArrayList<ArrayList<Integer>> result=new ArrayList<ArrayList<Integer>>();
ArrayList<Integer> list=new ArrayList<Integer>();
if(num==null||num.length==0){
	return result;
}
Arrays.sort(num);            //这个0表示当前的position
subsetsHelper(result,list,num,0);
return result;
}


private void subsetsHelper(ArrayList<ArrayList<Integer>> result, ArrayList<Integer> list,int[] num, int pos){
 //因为不是permutation 全排列 所以 不用到pos==num.length 才扔结果 每层应该直接扔
	result.add(new ArrayList<Integer>(list));
	//去重
	 for (int i = pos; i < num.length; i++) {
	if(i!=pos&&num[i]==num[i-1]){
		continue;}
	list.add(num[i]);
	subsetsHelper(result, list, num, i+1);
	list.remove(list.size()-1);
	 
	 
	 }
	
}


}