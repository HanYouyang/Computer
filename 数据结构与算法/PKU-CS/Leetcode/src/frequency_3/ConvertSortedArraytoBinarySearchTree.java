package frequency_3;

import java.util.zip.Inflater;

import frequency_3.FlattenBinaryTreetoLinkedList.TreeNode;

//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//先想 假如不是编程 这题目应该怎么做？
//一个平衡的BST 就是左边 右边一样高。。元素一样多
//那么 就像binary search一样 mid 是 root 然后前半段mid 是root.left 后半段mid是root.right
//	root.left = helper(num, low, mid - 1);
//root.right = helper(num, mid + 1,high);

public class ConvertSortedArraytoBinarySearchTree {
	public TreeNode sortedArrayToBST(int[] num) {
		if (num == null || num.length == 0) {
			return null;
		}
		return helper(num, 0, num.length - 1);
	}

	private TreeNode helper(int[] num, int low, int high) {

		if (low > high) {
			return null;
		}
		int mid = low + (high - low) / 2;
		TreeNode root = new TreeNode(num[mid]);
		root.left = helper(num, low, mid - 1);
		root.right = helper(num, mid + 1, high);
		return root;
	}
}