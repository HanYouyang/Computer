package frequency_3;

//you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
//把一个二叉树按照pre order的顺序  变成一个单叉树 
//    1
//   / \
//  2   5
// / \   \
//3   4   6
// 所以改写pre order traverse
//The flattened tree should look like:
//  全部都是右儿子 。
//  1
//   \
//    2
//     \
//      3
//       \
//        4
//         \
//          5
//           \
//            6

public class FlattenBinaryTreetoLinkedList {
	// 这个lastNode就是在排单链树的时候上层的node
	// last.right就是本层要放的节点 比方说 放1的时候 lastnode是null
	// 放2的时候lastnode是1 。。。放6的时候lastNode是5
	// 所以每次把本层root放上去的时候 lastNode就是 root
	private TreeNode lastNode = null;

	public void flatten(TreeNode root) {
		if (root == null) {
			return;
		}

		if (lastNode != null) {
			lastNode.left = null;
			lastNode.right = root;//把本递归层的root挂钩到上层的右节点
		}
     //这一段里就是 类似preorder排序的模板 
		lastNode = root;
		TreeNode right = root.right;
	//	先处理 lastNode=root 然后在递归调用node
		
		flatten(root.left);
		flatten(right); //为什么不能root。right 这样的话 如果root.right没有left节点 他就会 在39行root.right（lastNode。right） =root（实际上还是root。right）
		//然后变成每次lastnode都是进入死循环的那个root。left所以会死循环 （一直在root。right这一同一个节点上加）

	}

	public static void main(String[] args) {
		TreeNode one=new TreeNode(1);
		TreeNode two=new TreeNode(2);
		TreeNode three=new TreeNode(3);
		
		one.left=two;
		one.right=three;
	  (new FlattenBinaryTreetoLinkedList()).flatten(one);
	}

	static class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;

		TreeNode(int x) {
			val = x;
		}
	}
}
