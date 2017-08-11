package frequency_2;
//Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//For example,
//Given n = 3,
//You should return the following matrix:
//
//[
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
//]

//给你 一个n 让你把1～n^2按照上面这种螺旋矩阵的格式输出
public class SpiralMatrixII {
	 public int[][] generateMatrix(int n) {
	        if(n<0){
	        	return null;
	        }
	        int[][] result=new int[n][n];
	        int xStart=0;
	        int yStart=0;
	        int num=1;  //从1开始 1～n
	        while(n>0){
	        	if(n==1){
	        		result[yStart][xStart]=num++;
	  
	        		break; //循环结束                    
	        	}
	        	//假设n=3
	        for(int i=0;i<n-1;i++){
	        	result[yStart][xStart+i]=num++; //第一个for完了 [0][1]=3
	            print(result);
	        }
	   
	        for(int i=0;i<n-1;i++){                       //最右边的一条边
	        	result[yStart+i][xStart+n-1]=num++;  //[0][2]=3 [1][2]=4  [2][2]=5
	            print(result);
	        }
	        
	   	 
	        for (int i = 0; i < n-1; i++) {                //低下一条边 从右到左输出            
				result[yStart+n-1][xStart+n-1-i]=num++;//[2][1]=6 [2][0]=7
			      print(result);
			}
	         
	        for(int i=0;i<n-1;i++){               //左边一条边从下到上输出
	        	result[yStart+n-1-i][xStart]=num++;
	            print(result);
	        }
	         
	        xStart++;
	        yStart++;
	        n=n-2;
	        }
      		print(result);
	 return result;   
	 }
	 
	 public static void main(String[] args) {
		new SpiralMatrixII().generateMatrix(3);
	}

private static void print(int[][] result){
	for (int i = 0; i <result.length; i++) {
  		 System.out.println("");
  		 for (int j = 0; j < result[0].length; j++) {
  		 System.out.print(result[i][j]+" ");
  		 }
  		}
}
}
