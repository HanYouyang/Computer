package frequency_2;
//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//For example,
//Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
//http://oj.leetcode.com/problems/trapping-rain-water/
public class TrappingRainWater {
	
//因为每个column都是宽度1 那么面积=面积+(当前水面高度-当前column高度)*1 traverse一边即可
//所以关键是求当前i水面高度 ,i这个column的水面高度 是由离他最近的左右节点中最高的2个的短板决定的(看题目的图就知道了)
//所以建立2个数组 一个是从左到右 1~i时候的左边最高高度
//一个是从右向左从 length-2 到i的右边最高高度
//Math.min(left[i],right[i])就是当前水面高度
public int trap(int[] A) {
      if(A.length==0){
    	  return 0;
      }
      int[] left=new int[A.length];
      int[] right=new int[A.length];
       //一维dp初始条件 		
      left[0]=A[0];
      //dp
      for(int i=1;i<A.length;i++){
    	  left[i]=Math.max(left[i-1], A[i]);
      }
      //一维dp初始条件
      right[A.length-1]=A[A.length-1];
    //dp
      for(int i=A.length-2;i>=0;i--){
    	  right[i]=Math.max(right[i+1],A[i]);
      }
      
      int sum=0;
      //头-1/尾+1 是空 所以不能蓄水
      for(int i=1;i<A.length-1;i++){
    	  sum=sum+ Math.min(left[i], right[i])-A[i];
      }
      return sum;     
}
}
