package frequency_5;

//这题和CC150上1_7类似 但是cc 150的解法是用了 rows 和columns2个数组来储存0的坐标，比如matrix[i][j]=0  columns[i]++ rows[j]++,
//然后再次遍历这个matrix,当if(columns[i]!=0||rows[j]!=0)这个matrix[i][j]=0， leetcode上要求不需求辅助空间  
//那么我们就把matrix的第0行和第0列当做columns[] rows[] 来存0 (注意 如果原有x行0列是0 那么x行还是要是0 反之亦然)
//请注意当matrix只有1行1列的情况
public class SetMatrixZeroes {
	public void setZeroes(int[][] a) {
		// 先判断第0行 第0列有没有0
		boolean row0has0 = false;
		boolean column0has0 = false;
		for (int k = 0; k < a[0].length; k++) {
			// 第0行第k列 所以从左开始到右扫
			if (a[0][k] == 0) {
				row0has0 = true;
				break;
			}

		}

		for (int k = 0; k < a.length; k++) {
			// 第k行第0列 所以从上开始向下扫
			if (a[k][0] == 0) {
				column0has0 = true;
				break;
			}

		}
		// 当matrix大于1行 大于一列时候
		if (a.length > 1 && a[0].length > 1) {
			for (int i = 1; i < a.length; i++) {
				for (int j = 1; j < a[0].length; j++) {
					// most important line
					if (a[i][j] == 0) {
						a[i][0] = 0;
						a[0][j] = 0;
					}
				}
			}
			// 既然已经把0行0列和1行1列分开记录了 那么处理时候也应该分开
			for (int i = 1; i < a.length; i++) {
				for (int j = 1; j < a[0].length; j++) {

					// 核心在这里！！！
					if (a[i][0] == 0 || a[0][j] == 0) {
						a[i][j] = 0;

					}

				}
			}
		} else
		// 当matirx等于1行x列或者x行1列的时候
		if (a.length == 1 || a[0].length == 1) {
			if (row0has0 || column0has0) {
				for (int i = 0; i < a.length; i++) {
					for (int j = 0; j < a[0].length; j++) {

						a[i][j] = 0;
					}
				}
			}
		}
		if (row0has0) {
			for (int k = 0; k < a[0].length; k++) {

				a[0][k] = 0;
			}
		}
		if (column0has0) {
			for (int k = 0; k < a.length; k++) {
				a[k][0] = 0;
			}
		}
	}

	public static void main(String[] args) {
		// int[][] b = new int[4][5];
		int[][] b = { { 0, 0, 0, 5 }, { 4, 3, 1, 4 }, { 0, 1, 1, 4 },
				{ 1, 2, 1, 3 }, { 0, 0, 1, 1 } };

		// for (int i = 0; i < 5; i++) {
		// for (int j = 0; j < 4; j++) {
		// b[i][j] = 2;
		//
		// }
		// }
		// b[2][3] = 0;
		// b[1][1] = 0;

		for (int s = 0; s < 5; s++) {
			System.out.println("");
			for (int j = 0; j < 4; j++) {
				System.out.print(b[s][j] + " ");
			}
		}
		System.out.println("");
		(new SetMatrixZeroes()).setZeroes(b);
		System.out.println("");

		for (int s = 0; s < 5; s++) {
			System.out.println("");
			for (int j = 0; j < 4; j++) {
				System.out.print(b[s][j] + " ");
			}
		}

	}

}
