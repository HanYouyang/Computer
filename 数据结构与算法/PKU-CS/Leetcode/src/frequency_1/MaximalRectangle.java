package frequency_1;
//Given a 2D binary matrix filled with 0's and 1's, 
//find the largest rectangle containing all ones and return its area. 面积 
import java.util.Arrays;
import java.util.Stack;
 
public class MaximalRectangle {
//这题目要联系 Largest Rectangle in Histogram 一起看
//	char[][] matrix = {{'0', '0', '1', '0'},
//	                   {'0', '1', '1', '0'},
//	                   {'0', '1', '1', '1'},
//	                   {'1', '0', '1', '0'},
//	                   {'0', '1', '1', '1'},};
//把原来的1010矩阵变成直方图矩阵
//比方说这个矩阵有5行 我们第一列的时候 最大的矩阵就是  Largest Rectangle in Histogram题种0010;  
//然后第二行插入的时候就变成了  Largest Rectangle in Histogram0120; 第三行变成 0231; 
//当第四行插入的时候 matrix[3][1]和[3][3]是0  所以 此时histogram 被更新成 1040 
//最后一行跟新成0151  每新建好一行都可以调用 Largest Rectangle in Histogram来测算当前最大矩阵面积
//然后动态更新
 
	  public int maximalRectangle(char[][] matrix) {
	      if(matrix==null||matrix.length==0||matrix[0].length==0){
	    	  return 0;
	      }  
	  int rows=matrix.length;//几行
	  int columns=matrix[0].length;//几列
	  int max=0;
int[][] histogram=new int[rows][columns];
//第一行 --相当于初始dp
for(int j=0;j<columns;j++){
	if(matrix[0][j]=='1'){
		histogram[0][j]=1;
	}}
max = Math.max(max, largestRectangleArea(histogram[0]));
//dp部分 其实这里的2个for循环很简单就是把1010换算成高度 eg 0120--0231
//把原来的1010矩阵变成直方图矩阵
for(int i=1;i<rows;i++){ //从第二行开始
	for(int j=0;j<columns;j++){
		if(matrix[i][j]=='0'){
			histogram[i][j]=0;
		}else{
			histogram[i][j]=histogram[i-1][j]+1;
		}
	}
	max = Math.max(max, largestRectangleArea(histogram[i]));
}
return max; 	
	
}
	  
	  
	 
	  
	  public int largestRectangleArea(int[] height) {
	        if(height==null||height.length==0){
		    	  return 0;
		      }  
		Stack<Integer> stack=new Stack<Integer>();
		int max=0;
		
		for(int i=0;i<=height.length;i++){
			  
			int currentHeight=(i==height.length)?-1:height[i];
			 
			while(!stack.isEmpty()&&currentHeight<=height[stack.peek()]){
			 
				int h=height[stack.pop()];
			 
				int w=stack.isEmpty()?i:i-stack.peek()-1;
		        max=Math.max(max,h*w); 
			}
		       stack.push(i);  
		      
		}
		
	return max;	
	    }
}
