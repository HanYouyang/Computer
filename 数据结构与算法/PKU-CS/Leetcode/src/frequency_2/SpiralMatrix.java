package frequency_2;

import java.util.ArrayList;

//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
//For example,
//Given the following matrix:
//
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//
//You should return [1,2,3,6,9,8,7,4,5]. 

//按照螺旋顺序打印一个矩阵  思路和 Spiral Matrix2 很像

public class SpiralMatrix {
	public ArrayList<Integer> spiralOrder(int[][] matrix) {
		ArrayList<Integer> result = new ArrayList<Integer>();
		if (matrix == null || matrix.length <= 0 ) {
			return result;
		}
		// 因为是,mxn的矩阵 所以
		int rows = matrix.length;
		int cols = matrix[0].length;
		int count = 0; 
		while (count * 2 < rows && count * 2 < cols) {
			// 横着读取第一行（最外层上边）
			for (int i = count; i < cols - count; i++) {
				result.add(matrix[count][i]);
			} 
			for (int i = count + 1; i < rows - count; i++) {
				result.add(matrix[i][cols - count - 1]);// 从第二行开始读最外层右边
			}
			// 如果只有一个col/row了
			if (rows - 2 * count == 1 || cols - 2 * count == 1) {
				break;
			}
			// 最外层下边从右(倒数第二右)到左 输入
			for (int i = cols - count - 2; i >= count; i--) {
				result.add(matrix[rows - count - 1][i]);
			}
              //最外层左边输从下到上输入(从倒数第二个输入到正数第二个 )
			for (int i = rows - count - 2; i >= count + 1; i--) {
				result.add(matrix[i][count]);
			}
			count++; // 往里一层
		}
		return result;
	}

}
