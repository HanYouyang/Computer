package template;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
//所有排列组合类的做法
public class 排列组合 {

	public ArrayList<Integer> permute(int[] num){
		Arrays.sort(num);
		ArrayList<ArrayList<Integer>> results=new ArrayList<ArrayList<Integer>>();
		ArrayList<Integer> path=new ArrayList<Integer>();
		permuteHelper(results,path,num/*?*/);
		return results;
	}
	
	private void permuteHelper(ArrayList<ArrayList<Integer>> results,ArrayList<Integer> path,int[] num){
		if(path.size()==num.length){ //是方法结束的条件
			results.add(new ArrayList<Integer>(path));
			return;
		}
		for(int =/*?*/;i<numm.length;i++){
			//提议要求要跳过那些条件 
			path.add(num[i]);
			permuteHelper(results, path, num);
		 path.remove(path.size()-1);
		}
	}
	
}
