package frequency_3;

public class SearchA2DMatrix {

//第二轮log(m+n)做法
	
	 public boolean searchMatrix2(int[][] matrix, int target) {
		 int rows=matrix.length;
		 int cols=matrix[0].length;
		 int start=0;
		 //把这个二维数组拉成1维  1 2
		 //                     3 4 
		 //变成 1 2 3 4 后 还是sorted的  所以可以正常binary search
		 int end=rows*cols-1;  //ends就是一维数组的end了
		 while(start<=end){
			 int mid=start+(end-start)/2;
			 //把1维的 index重新映射到2维上
			 if(matrix[mid/cols][mid%cols]==target){
				 return true;
			 }else if(matrix[mid/cols][mid%cols]>target){ //在一维数组的前半段
				 end=mid-1;
			 }else{
				 start=mid+1;
			 }
		 }
		 return false;
	 }
	
	
	
	
	// 在一个二维矩阵里找数组 cc原题 这个矩阵其实是sorted的 --每行sort 下一行最小比上一行最大
	// [
	// [1, 3, 5, 7],
	// [10, 11, 16, 20],
	// [23, 30, 34, 50]
	// ]
	//
	// Given target = 3, return true.
	// cc原题 做法就是比最后一列 如果target比他小就扫描本列

	public boolean searchMatrix(int[][] matrix, int target) {
		if (matrix == null || (matrix.length == 0 && matrix[0].length == 0)) {
			return false;
		}

		int row = matrix.length;
		int column = matrix[0].length;
		int currentRow = 0;
		int currentColumn = column - 1;

		// 这个循环就是让target和每一列的最后比
		// 如果等于就是true
		// 如果target比row最后大 就说明 在 target可能在下一行 所以currentRow++
		// 如果target比row最后小 就说明target可能在本行 所以currentColumn--
		// 跳出while了 还找到就是false
		while (currentRow < row - 1 && currentColumn >= 0) {
			if (matrix[currentRow][currentColumn] == target) {
				return true;
			} else if (matrix[currentRow][currentColumn] > target) {
				currentColumn--;
			} else {
				currentRow++;
			}

		}

		return false;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
