package frequency_2;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;

//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//For example,
//[1,1,2] have the following unique permutations:
//[1,1,2], [1,2,1], and [2,1,1]. 
//给你有一个可能重复的数组  你要给出所有不重复的premutation
//这题十分类似 combination sum 只不过不用给出和是target的 
public class Permutations2 {
	public ArrayList<ArrayList<Integer>> permuteUnique(int[] num) {
	        ArrayList<ArrayList<Integer>> result= new ArrayList<ArrayList<Integer>>();
	 if(num==null||num.length==0){
		 return result;
	 }   
	 ArrayList<Integer> list=new ArrayList<Integer>();
	 int[] visited=new int[num.length];
	 Arrays.sort(num);//排序后所有相同的都相邻
	 helper(result,list,visited,num);  //visited 是一种去重的手段 防止出现重复排列
	 return result;
	 }
	// 总共也是只有list作为 dfs一个质押的缓存。然后符合条件了（枝桠到底了 ）
	// 
 public void helper(ArrayList<ArrayList<Integer>> result,ArrayList<Integer> list, int[] visited, int[] num){
	 if(list.size()==num.length){
		 result.add(new ArrayList<Integer>(list));
		 return;
	 }
	 
	 for(int i=0;i<num.length;i++){
		 //重复的情况 不用递归下去了 （类似combination sum）
		//为什么要 i!=0&&num[i]==num[i-1]&&visited[i-1]==0
		 //比方说 当 112222  第一个dfs枝桠就只会触及visited[i]==1
		 //但是第一个枝桠完了 基本上吧全排列弄的差不多了
		 //当到第二个和以后的permutation的枝桠 比方说visited[i-1]==0 并且num[i]==num[i-1]那么 num[i-1]已经被判定为不需要加了
		 //那么和他相同的num[i]也不需要加了 加了重复 
		 if(visited[i]==1||(i!=0&&num[i]==num[i-1]&&visited[i-1]==0)){
		 continue;
		 }
		 visited[i]=1; //道理和combination sum一样  
		 list.add(num[i]);
		 helper(result,list,visited,num);//进入递归后 又从头开始 遍历 但是要检查visited 
		 list.remove(list.size()-1);
		 visited[i]=0;
	 }
	 
 }
	
	public static void main(String[] args) {
     		int[] num={1,1,1,2,2,2,3};
     		new Permutations2().permuteUnique(num);
	}

}
