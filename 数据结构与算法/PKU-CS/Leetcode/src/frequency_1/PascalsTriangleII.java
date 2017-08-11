package frequency_1;

import java.util.ArrayList;

//Given an index k, return the kth row of the Pascal's triangle.
//
//For example, given k = 3,
//Return [1,3,3,1].
//
//Note:
//Could you optimize your algorithm to use only O(k) extra space?

//杨辉三角形II 要求给层数返回三角形第N层,尽量少用空间 
//和I的解法一样 其实每层的数字只都是有上一层计算得来
//那么实际上只要保留上一层的就可以 计算出本层，计算出本层后上一层就可以丢了
//然后本层的数字作为新的“上一层”来计算本层下面的那层
//K神的做法已经做到只用一层的空间 。。
public class PascalsTriangleII {
	public ArrayList<Integer> getRow(int rowIndex) {
		
		ArrayList<Integer> lastLevel = new ArrayList<Integer>();
		lastLevel.add(1);
		for (int i = 1; i <= rowIndex; i++) {
			ArrayList<Integer> currentLevel = new ArrayList<Integer>();
			currentLevel.add(1);
			for (int j = 0; j < lastLevel.size() - 1; j++) {
					currentLevel.add(lastLevel.get(j) + lastLevel.get(j + 1));
				}
				currentLevel.add(1);
				lastLevel = currentLevel;
		
		}
		return lastLevel;

	}
}
