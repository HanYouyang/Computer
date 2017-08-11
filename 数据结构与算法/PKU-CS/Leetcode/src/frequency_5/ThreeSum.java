package frequency_5;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

import javax.naming.spi.DirStateFactory.Result;

//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note:
//
//    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
//    The solution set must not contain duplicate triplets.
//
//    For example, given array S = {-1 0 1 2 -1 -4},
//
//    A solution set is:
//    (-1, 0, 1)
//    (-1, -1, 2)

//还记得2sum是要么用hashmap 要么用头尾2个指针么？
//这里可以改动下 第二种做法 做3Sum 
//有了twoSum的启发，threeSum所有做的事，只需加上排序，和一层循环。经测试AC。
public class ThreeSum {

	 ArrayList<ArrayList<Integer>> result=new ArrayList<ArrayList<Integer>>();
	
	  public ArrayList<ArrayList<Integer>> threeSum(int[] num) {
	      Arrays.sort(num); 
	      if(num.length<3){return result;
	      }else if(num.length==3){
	    	  if((num[0]+num[1]+num[2])==0){
	    		  Arrays.sort(num);
	    		  ArrayList<Integer> tmpList=new ArrayList<Integer>();
					 
					tmpList.add(num[0]);
					tmpList.add(num[1]);
					tmpList.add(num[2]);
	    		  result.add(tmpList);
	    	  }else{return result;}
	      }else{   
	      for(int i=0;i<num.length-3;i++){
	    	if(i!=0&&num[i]==num[i-1]){
	    		//he solution set must not contain duplicate triplets.
	    		//所以当num[i]==num[i-1] 时候 要跳掉
	    		//继续循环下一个
	    		continue;
	    	}
	    	judgeAndPut(num,i,i+1,num.length-1);
	    	
	      }
	     
	 }
		return result;
	      
	      }
	        // 也是逼近的方法 本质和2sum一样 
	          // 因为数组是排好序的                    //i    //i+1
	       private void judgeAndPut(int[] num,int i,int j ,int end ){
	    	   while (j<end) {
				if(num[i]+num[j]+num[end]<0){
					j++;  //其实本质和双层循环j=i+1 j++查不多
				}else if(num[i]+num[j]+num[end]>0){
					end--;
				}else if(num[i]+num[j]+num[end]==0){
					ArrayList<Integer> tmpList=new ArrayList<Integer>();
					//注意题目要求 小的在前
					tmpList.add(num[i]);
					tmpList.add(num[j]);
					tmpList.add(num[end]);
					result.add(tmpList);
				j++;
				end--;
				//he solution set must not contain duplicate triplets.
				// 所以arraylist数组里有同样的时候 需要跳掉处理
				//ps 这段需要放在else里面 而不是else外面 因为 只有else里面真实的往arraylist里面添加了triplets
				//所以只有在此时才有必要跳
				while ((j < end) && num[j] == num[j - 1]) {
					j++;
				}
				while ((j < end) && (end<num.length-1)&&num[end] == num[end + 1]) {
					end--;
				}

				}
			
		}
	} 
	        
	        
	     
	
	
	public static void main(String[] args) {
		 int num[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};  
	        System.out.println(new ThreeSum().threeSum(num));  

	}

}
