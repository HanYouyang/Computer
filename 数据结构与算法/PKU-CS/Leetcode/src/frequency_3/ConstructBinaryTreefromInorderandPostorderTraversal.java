package frequency_3;

//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree. 
//知道后序和中序构造树
/*
 *             5
 *            /  \          
 *           2    7 
 *          / \  / \
 *         1  3 6   8     
 *中序     1235678
 *后序     1326875  所以root是后序最后一个 val是5
 *然后 去中序数组里找 5的position 5左边的 都是左子树，5右边的都是右子树
 在后续里面 132	(poststart, poststart + position - instart - 1)是左子树 687position-inend+postend, postend-1)是右子树 
 *再递归调用找本方法  myBuildTree找左右子树的root,就是 总root的5的left和right  
 *最后return root
 */

public class ConstructBinaryTreefromInorderandPostorderTraversal {

	public TreeNode buildTree(int[] inorder, int[] postorder) {
		if (inorder.length != postorder.length) {
			return null;
		}
		return myBuildTree(inorder, 0, inorder.length - 1, postorder, 0,
				postorder.length - 1);
	}

	private TreeNode myBuildTree(int[] inorder, int instart, int inend,
			int[] postorder, int poststart, int postend) {
		if (instart > inend) {
			return null;
		}
		// post 左右中 所以 总root是post order最后一个
		TreeNode root = new TreeNode(postorder[postend]);
		// 所以我们现在找到的root的val 我们要在中序里面找到root在中序数组第几位
		// 因为中序是左中右，所以 在中序里面找到root后
		// root的左边都是左子树，右边都是右子树。
		int position = findPosition(inorder, instart, inend, postorder[postend]);
		root.left = myBuildTree(inorder, instart, position - 1, postorder,
				poststart, poststart + position - instart - 1);
		root.right = myBuildTree(inorder, position + 1, inend, postorder,
				position - inend + postend, postend - 1);
		return root;
	}

	private int findPosition(int[] arr, int start, int end, int key) {

		for (int i = start; i <= end; i++) {
			if (arr[i] == key) {
				return i;
			}
		}
		return -1;
	}

}
