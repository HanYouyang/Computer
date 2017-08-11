package frequency_1;

import java.util.ArrayList;

//Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
//For example, given the following triangle
//
//[
//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
//]
//
//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//Note:
//Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 
//典型的DP题 你不觉得和GPS 规划路劲 
public class Triangle {
//bottom up 做法 	
	                          //第一个arraylist表示三角形的高度(深度)/第二个arraylist表示本层的宽度
	public int miniumTotal(ArrayList<ArrayList<Integer>> triangle){
		if(triangle==null||triangle.size()==0){
			return 0;
		}
		int n=triangle.size(); //高度
		//预处理矩阵里[][]格子是到这个格子 所造成的最小sum
		int[][] sum=new int[n][n];
       //和机器人从左上到右下那题一样 做一个预处理矩阵
		
		//把triangle最后一行复制到预处理矩阵的最后一行   [4,1,8,3]
		for(int i=0;i<n;i++){
			sum[n-1][i]=triangle.get(n-1).get(i);
		}
		 
		//然后矩阵里再根据最后一行开始向上DP.看看一层层往上的格子走到这格需要最少多少sum 
	//   [6,5,7],
	//  [4,1,8,3]  eg 6这个格子就是取 4+6和1+6的min 然后全部往上一层层DP 直到sum[0][0]
	         //每层从下到上遍历上去
		for(int i=n-2;i>=0;i--){
			      //从左到右遍历过去
			for(int j=0;j<triangle.get(i).size();j++){
				
				sum[i][j]=Math.min(sum[i+1][j], sum[i+1][j+1])+ triangle.get(i).get(j);
			}
		}
		return sum[0][0];
		
		
		
		
		
		//sum数组最后会变成这样
//	    [2],         [0][0]由[1][0]和[1][1]中小的得出
//	    [3,4],       [1][0]和[1][1]由[2][0],[2][1]和[2][1],[2][2]中得出 以此类推
	//  [6,5,7],
	//  [4,1,8,3]
		
		
		
		
		
		
	}
	
	
	
	

}
