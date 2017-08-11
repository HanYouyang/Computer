package frequency_5;
import java.util.Arrays;
import java.util.HashMap;

//Given an array of integers, find two numbers such that they add up to a specific target number.
//
//The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
//
//You may assume that each input would have exactly one solution.
//
//Input: numbers={2, 7, 11, 15}, target=9
//Output: index1=1, index2=2 

//这题和cc上类似 不过有点不一样
//1.不过CC是要返回所有符合target的解 这题只需要 一个解即可
//2.他要求返回原数组的下标 而不是排序后的值的和
//3.下标从1开始
//做法 排序然后下标++ --
//再去原数组里找？ 再去原书组找就太费时间了 复杂度过不了。所以要在排序时候再创一个数组记录原始位置和新位置  
//就好象一个mapping的表 麻烦的很. 所以可以参见用hashmap的做法二
public class TwoSum {
	
	 public int[] twoSum(int[] numbers, int target) {
	        int[] result =new int[2];
	        int[] newNumbers=numbers.clone();
	        Arrays.sort(newNumbers);
	        int first=0;
	        int last=newNumbers.length-1;
	        int result1=0;
	        int result2=0;
	        while(first<last){
	        	if(newNumbers[first]+newNumbers[last]==target){
	        		for(int i=0;i<numbers.length;i++){
	        			if(newNumbers[first]==numbers[i]){
	        				result1=i;
	        			}
	        			if(newNumbers[last]==numbers[i]){
	        				 result2=i;
	        			}
	        		if(result1!=0&&result2!=0){
	        			if(result1<result2){
		        			result[0]=result1+1;
			        		result[1]=result2+1;
			        		return result;
		        		}else{
		        			result[1]=result1+1;
			        		result[0]=result2+1;
			        		return result;
		        		}
	        		}
	        		}
	        		}else if(newNumbers[first]+newNumbers[last]>target){
	        		--last;
	        	}else{++first;}
					
				}
	        	
	        	
	        return null;	
	        }
	    
    
	 public int[] twoSum2(int[] numbers, int target) {
		 HashMap<Integer, Integer> map=new HashMap<Integer, Integer>();
		 
		 int[] result =new int[2];
		 int len = numbers.length;  
		  assert(len >= 2);  //assert验证numbers至少有2个树
		  //因为题目已经告诉你是唯一的 所以不存在重复的value 所以数组的value可以当key index可以当 value
	   for(int i=0;i<numbers.length;i++){//i++是整个for跑完之后才++的
		   //如果map里已经有所缺的另一个数字了 那就返回结果，如果没有，那就把本numbers[i], i 存入数组
		   //因为一开始肯定是空的,所以肯定是比方说i=50的时候找到了i=20和他匹配 所以 i是后面的  map.get(target-numbers[i]) 是前面的
		  if(map.containsKey(target-numbers[i])){
			  result[1]=i+1;
      	    	result[0]=map.get(target-numbers[i])+1;
		      return result;
		  }else{
		   
		   map.put(numbers[i], i);
		  }}
	return null;
	 
	 
	 }
	 
	 
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
