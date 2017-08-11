package frequency_2;
//Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
//n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
//Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container
// 比方说数组height[n]里  n是 x(轴) height[n] y 轴  
//
//                |                      height[3]=4           //短板原理
//                |     height[2]=2        |            那么 water的面积 就是 (4-2)*Min(height[2],height[3])=2*2=4
//                |       |                |
//                |       |                |         
//                |—————————————————————————————————————————
//                        2                4
//                                                 宽度                
//所以:给定一个数组height[n];i,j都是数组的下标，找到（j-i）*min(heigth[i],height[j])最大的数。

//双指针 i从左向右扫描 j从右向左扫描 

public class ContainerWithMostWater {
public int maxArea(int[] height) {
   int i=0;
   int j=height.length-1;
   int maxArea=0;
   while(i<j){
	   //左指针i这边的高度短，根据水桶原理,短边决定面积 那么 长边怎么样是对面积
	   //无影响的所以短边向右 看看能不能更高
	   if(height[i]<height[j]){
		   if((j-i)*height[i]>maxArea){
			   maxArea=(j-i)*height[i];}
			   i++;
		   }else{  //右指针 j那边的高度矮
			   if((j-i)*height[j]>maxArea){
				   maxArea=(j-i)*height[j];}
				   j--;
			   }
		 
   }
return maxArea;
			
		
		
    }
}
