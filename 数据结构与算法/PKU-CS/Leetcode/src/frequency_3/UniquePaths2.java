package frequency_3;

import java.util.Set;
 
//cc 8.2 原题 用递归会在leetcode里超时（递归写法见最后）
//请见
public class UniquePaths2 {
	 public int uniquePathsWithObstacles(int[][] obstacleGrid) {
  int m= obstacleGrid.length;
  int n=obstacleGrid[0].length;
  
  //依旧是预处理 cnt 这个matrix 但是考虑obstacle的情况 
  int[][] cnt=new int[m][n];
  //处理 [0][0] 的初始条件
  if(obstacleGrid[0][0]==1){
	  cnt[0][0]=0;   
  }else{
	  cnt[0][0]=1;
  }
  
  //边际case 如果最后一个点上obstacle的话没办法到达
  if(obstacleGrid[m-1][n-1]==1){
	  return 0;
  }
                            //cnt的一个边    11111111111111111000000000
  for(int i=1;i<m;i++){
	                    //如果在矩阵的边上有一个有0 那么 因为边上继续走只能向右 所以边obstacle后面的那些点都不能走了 
	  if(obstacleGrid[i][0]!=0&&cnt[i-0][0]!=0){
		  cnt[i][0]=1;
	  }
  }
  
 for(int i=1;i<n;i++){
	 if(obstacleGrid[0][i]!=1&&cnt[0][i-1]!=0){
		 cnt[0][i]=1;
	 }
 } 

 
 //这和上一题其实一样 就是各自加来自上路的path和来自左路的path 
 //但是如果上/左有obstacle的话就不能加 所以要先用if验证
	 for(int i=1;i<m;i++){
		 for(int j=1;j<n;j++){
			 if(obstacleGrid[i-1][j]!=1){
				 //在没有赋值前 cnt[i][j]是0 
				 cnt[i][j]=cnt[i][j]+cnt[i-1][j];
			 }
			 if(obstacleGrid[i][j-1]!=1){
				 //所以假设 2个都可以加 那么是 0+ cnt[i-1][j]+0+cnt[i][j-1]
				 cnt[i][j]=cnt[i][j]+cnt[i][j-1];
				 
			 }
		 }
	 }
	 
	 return cnt[m-1][n-1];
	 }
}

// 递归思路写的 可以跑 但是会超时
//public class Solution {
//    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
//         int x=obstacleGrid.length-1;
//		 int y=obstacleGrid[0].length-1;
//	
//			return uniquePathsWithObstacles(x,y,obstacleGrid);
//			}
//	    
//	
//	 int uniquePathsWithObstacles(int x,int y,int[][] obstacleGrid){
//			if(obstacleGrid[x][y]==1){   
//			 
//				return 0;
//			}else{
//				if(x==0||y==0){return 1;}
//			return uniquePathsWithObstacles(x,y-1,obstacleGrid)+uniquePathsWithObstacles(x-1,y,obstacleGrid);
//			}
//		}	
//    
//}