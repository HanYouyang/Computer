package frequency_1;

import java.util.Arrays;

import frequency_2.SortColors;

//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
//For example, given array S = {-1 2 1 -4}, and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//找在数组中找三个元素 要求他们的和 是离target最接近的
//假设一个数组里只有一个solution是离target最近的

public class ThreeSumClosest {
//先sort数组
//然后设一个初始closet 为max_value/2
//然后 for循环从 0～i-2
//每次for循环后 左指针=i+1, 右指针 是length-1 //因为从小达到 所以 此时 lp最小rp最大
//while(left<right) sum=num[i]+num[左]+num[右]
//如果sum==target,就找到了 如果sum<target 说明总sum小了 所以left++ ,反之right--
//然后每次循环最后   closet=Math.abs(sum-target)<Math.abs(closet-target)?sum:closet;
//如果之前的closet离target进 就保留 如果本次for循环算出来的sum离target进 就用本次sum更新closet

	
public int threeSumClosest(int[] num, int target) {
     if(num==null||num.length<3){
    	 return Integer.MAX_VALUE;
     }  
     Arrays.sort(num); //从大到小排列  这样方便“类binary search”
    int closet=Integer.MAX_VALUE/2; // otherwise it will overflow for opeartion (closet-target) 
    //eg:如果 closet为负数 (如果target是Max_value) 那么closet-target 就为负溢出。 
    for(int i=0;i<num.length-2;i++){
    	int left=i+1; //左指针
    	int right=num.length-1; //右指针
    	while(left<right){
    		int sum= num[i]+num[left]+num[right];
            if(sum==target){return sum;
            }else if(sum<target){
                left++;
            }else{right--;}
            closet=Math.abs(sum-target)<Math.abs(closet-target)?sum:closet;

    	}
    }
     return closet;
    }
}
