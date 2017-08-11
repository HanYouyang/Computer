package frequency_2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
//Note:
//
//    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
//    The solution set must not contain duplicate quadruplets.
//
//    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
//
//    A solution set is:
//    (-1,  0, 0, 1)
//    (-2, -1, 1, 2)
//    (-2,  0, 0, 2)
//   从数组里找所有4个数且和是target的组合 结果集要不重复而且递增
//返回值就可以 用返回下标 
//模板化了，要计算 k-sum 复杂度为O(N^(k-1)) 所以4sum 是0n3
public class FourSum {
	 public ArrayList<ArrayList<Integer>> fourSum(int[] num, int target) {
	        Set<ArrayList<Integer>> result= new HashSet<ArrayList<Integer>>();
	        Arrays.sort(num);
	        for(int i=0; i<num.length;i++){
	        	for(int j=i+1;j<num.length;j++){ // 等于再num[n]+num[]的情况下做2 sum
	        		int m=j+1;
	        		int n= num.length-1;
	        		while(m<n){  //此时数组已经排好序 
	        			if(i!=j&&j!=m&&m!=n){ //m n 像2sum一样 左右指针2头扫 和小就左指针++ 大就右指针--
	        					if(num[m]+num[n]==target-num[i]-num[j]){
	        					ArrayList<Integer> list= new ArrayList<Integer>();
	        					list.addAll(Arrays.asList(num[i],num[j],num[m],num[n]));
	        					result.add(list);
	        					m++;
	        					n--;
	        				}else if(num[m]+num[n]<target-num[i]-num[j]){
	        				m++;	        					
	        				}else{
	        					n--;
	        				}
	        			}
	        		}
	        	}
	        }
	        
	   return new ArrayList<ArrayList<Integer>>(result);     
	        
	    }
	 public static void main(String[] args) {
			int[] num = {1, 0, -1, 0, -2, 2};
			System.out.println(new FourSum().fourSum(num, 0));
		}	
}
