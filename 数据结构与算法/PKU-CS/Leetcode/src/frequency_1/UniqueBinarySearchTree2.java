package frequency_1;

import java.util.ArrayList;
//Given n, generate all structurally unique BST's (binary search trees) that store values 1...n
//
//For example,
//Given n = 3, there are a total of 5 unique BST's.
//
// 1         3     3      2      1
//  \       /     /      / \      \
//   3     2     1      1   3      2
//  /     /       \                 \
// 2     1         2                 3

import javax.management.loading.PrivateClassLoader;

//1~n  要全部储存在bst里 有几种肯能的树？
//用dfs的思想  当root为1时候 root为2时候 root为3时候循环 一直到n 这就是for
//然后当root为1时候 左边不能放 右边放2~n   root为2时候  左边放1 右边放3～n
//总之 当 root为 i时候 左边放1～i-1  右边放1+1～n　所以这里就是dfs
//循环就是1～n

public class UniqueBinarySearchTree2 {
	public ArrayList<TreeNode> generateTrees(int n) {

		return numTrees(0, n-1);
	}

	// dfs
	private ArrayList<TreeNode> numTrees(int start, int end) {
		ArrayList<TreeNode> result = new ArrayList<TreeNode>();
		if (start > end) {
			result.add(null);
			return result;
		}

		for (int i = start; i <= end; i++) {
			// 当root=i时候 all possible left subtree最后都会返回到leftChild
			ArrayList<TreeNode> leftChild = numTrees(start, i - 1);
			// 当root=i时候 all possible right subtree最后都会返回到rightChild
			ArrayList<TreeNode> rightChild = numTrees(i + 1, end);
			// 因为此时还在大的i循环里 所以root就是i
			// 那么当root 是i的时候 所有的可能性是
			// i连上左子树的所有可能 × i连上右子树的所有可能
			for (int j = 0; j < leftChild.size(); j++) {
				for (int k = 0; k < rightChild.size(); k++) {
					TreeNode root = new TreeNode(i + 1);// that store values
														// 1...n. 没有0
					root.left = leftChild.get(j);
					root.right = rightChild.get(k);
					result.add(root);
				}
			}
		}
		return result;
	}
}
