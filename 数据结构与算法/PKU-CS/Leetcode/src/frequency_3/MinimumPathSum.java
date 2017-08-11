package frequency_3;

//Given a m x n grid filled with non-negative numbers, 
//find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.
//给你一个矩阵 里面 好多非负数
//然后要你从左上到右下找一条path 使得path的内的合最小 然后返回和

//九章DP模板 matrixDP 预处理矩阵。最后返回sum[rows-1][cols-1] 
//sum这个矩阵里每一格都存左上走到这步所需的最少sum。
//1.先initial 两个边  sum[0][col] = sum[0][col - 1] + grid[0][col];
//然后2.DP (双重循环 然后    sum[row][col]=Math.min(sum[row-1][col],sum[row][col-1])+grid[row][col];) Math.min的存在 有因为 只能从左上到右下，所以当前格子的sum. 是到我这个节点最少的path 

public class MinimumPathSum {
	public int minPathSum(int[][] grid) {
		// 2d matrix里 grid.length==0和 grid[0].length==0 里面都是相当于空集 不能存元素
		if (grid == null || grid.length == 0 || grid[0].length == 0) {
			return 0;
		}

		int rows = grid.length;
		int cols = grid[0].length;
		int[][] sum = new int[rows][cols];
		//initialize 
		sum[0][0] = grid[0][0];
		 
		for (int row = 1; row < rows; row++) {
			// 前一个的sum加本个grid[][]的 value就是本格的sum
			sum[row][0] = sum[row - 1][0] + grid[row][0];
		}

		for (int col = 1; col < cols; col++) {
			sum[0][col] = sum[0][col - 1] + grid[0][col];
		}
		// dp
		for (int row = 1; row < rows; row++) {
			for (int col = 1; col < cols; col++) {
				//因为 有 Math.min的存在 有因为 只能从左上到右下，所以当前格子
				//的sum. 是到我这个节点最少的path 
         sum[row][col]=Math.min(sum[row-1][col],sum[row][col-1])+grid[row][col];
          }
		}
return sum[rows-1][cols-1];
	}
}
