package frequency_3;
//A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
//How many possible unique paths are there?
//机器人从左上到右下 cc原题
//无非是每一步向左走一种可能 向下走一种可能 recursion
//结束条件就是走到终点x y==0 算是一种qnique的走法

//recursion解法leetcode超时
//下面研究预处理的方法 
//因为题目告诉你M N不会大于100 我们就吧到这个最多100x100的矩阵给预处理了
//右下角到某个格子的矩阵 此时有多少种可能的path 比方说ways[5,10]就是一个长6宽11的矩阵的unique path数量

public class UniquePaths {
	
	  public int uniquePaths(int m, int n) {
		int[][] ways=new int[m][n];
		ways[0][0]=1; //初始 一种走法  
		// 因为从左上到右下和从右下到左上 path数是一样的 所以0 0就设为终点
		for(int i=0;i<m;i++){
			ways[i][0]=1;  // 顶点相邻的两条边 到顶点只有1条路 沿着边走
		}
		
		for(int j=0;j<n;j++){
			ways[0][j]=1;
		}
		
		for(int i=1;i<m;i++){
			for(int j=1;j<n;j++){
				//因为走到i j无非2种可能  从[i-1][j]走了一步过来
				//或者从 [i][j-1]走了一步过来
				//那么 无非是把他们2种的走过来的所有的情况加起来。 就是i j可能的unique path数量
				ways[i][j]=ways[i-1][j]+ways[i][j-1];
			}
		}
		return ways[m-1][n-1]; //-1 是因为下标的关系
	  }
	  
	  
	  
//	   这种做法是对的 但是leetcode里会超时
//	  public int uniquePaths(int m, int n) {
//			// 为什么是x==0||y==0呢？因为走到边了只有只有沿着边走着一条路径了 所以return 1
//			  if(m==0&&n==0){
//		        	return 1;
//		        }
//		  return (uniquePaths(m-1, n)+uniquePaths(m, n-1));  
//		  }


	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
