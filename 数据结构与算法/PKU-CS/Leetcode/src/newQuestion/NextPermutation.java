package newQuestion;

import frequency_4.SwapNodesinPairs;

//implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
//The replacement must be in-place, do not allocate extra memory.
//
//Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//1,2,3 → 1,3,2
//3,2,1 → 1,2,3
//1,1,5 → 1,5,1
//找一个比輸入排列更大的排列里面最小的 。
//如果不可以就 返回最小的排列
public class NextPermutation {
	// 从尾到头遍历 找到第一个前面比后面小的index
	// 后面一定是递减的
	// // 例如 “547532“
	// 　　1. “547532”， 4是下降沿。
	// 　　2. “547532”， 5是要替换的元素， 替换后得到 “ 557432”
	// 3. "557432",
	// 再从尾到头遍历，找到第一个比那个index里的内容大的index2
	// eg 那个index是 1 值是4 所以第一个找到的是5 比四大 所以swap 4和5
	// 把index后1 的全部reverse 7432反转，得到 “552347”。

	// 特殊情况是一开始index遍历到头都是递减的，那就直接reverse全array就行了

	public void nextPermutation(int[] num) {
		if (num == null || num.length <= 1) {
			return;
		}
		// 1. 从后往前找falling edge，下降沿。eg “547532”， 4是下降沿。
		int edge = -1;
		for (int i = num.length - 2; i >= 0; i--) {
			if (num[i] < num[i + 1]) {
				edge = i;
				break;
			}
		}
		// 2. 再从尾到头遍历，找到第一个比那个index里的内容大的index2
		// eg “547532”， 2--3--5 就是找他
		// 然后swap 下降沿和这个找到的值   换4 和 5 
		if (edge > -1) {
			for (int i = num.length - 1; i > edge; i--) {
				if (num[i] > num[edge]) {
					swap(num, i, edge);
					break;
				}
			}
		}

		// reverse下降沿后面的所有元素。 如果全降序的话edge就是-1
		// anyway 这里只要从egde+1开始反转起就好
		int i = edge + 1;
		int j = num.length - 1;
		while (i < j) {
			swap(num, i, j);
			i++;
			j--;
		}
	}

	private void swap(int[] num, int a, int b) {
		int temp = num[a];
		num[a] = num[b];
		num[b] = temp;
	}
}
