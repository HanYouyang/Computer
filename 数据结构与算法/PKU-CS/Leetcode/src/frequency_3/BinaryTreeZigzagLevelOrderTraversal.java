package frequency_3;
//Given a binary tree, return the zigzag level order traversal of its
		// nodes' values. (ie, from left to right, then right to left for the next
		// level and alternate between).
		//
		// For example:
		// Given binary tree {3,9,20,#,#,15,7},
		//
		// 3
		// / \
		// 9 20
		// / \
		// 15 7
		//
		// return its zigzag level order traversal as:
		//
		// [
		// [3],
		// [20,9],
		// [15,7]
		// ]
		// level order 但是要一层正的输出 一层反着输出
import java.util.ArrayList;
import java.util.Stack;

public class BinaryTreeZigzagLevelOrderTraversal {
// //2个stack 是怎么玩的呢 记住stack 特性 FILO
//          1
//        2   3
//       4 5 6 7
//	此normal order是true 1pop 时候,2 3到nextlevel  
//然后下一层normal order 是false 然后pop出来的顺序是 3，2 然后因为是反序,所以先push right 再push left
//此时push的顺序就是7 6 5 4 然后pop的顺序就又是 4 5 6 7 加到本层结果里面 所有有正常了 	
//
	public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode root) {
		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
		if (root == null) {
			return result;
		}

		Stack<TreeNode> currLevel = new Stack<TreeNode>();
		Stack<TreeNode> nextLevel = new Stack<TreeNode>();
		Stack<TreeNode> tep;
		currLevel.push(root);
		boolean normalOrder = true;
		while (!currLevel.isEmpty()) {
			ArrayList<Integer> currLevelResut = new ArrayList<Integer>();
			while (!currLevel.isEmpty()) {
				TreeNode node = currLevel.pop();
				currLevelResut.add(node.val);

				if (normalOrder) {
					 
					if (node.left != null) {
						nextLevel.push(node.left);
					}
					if (node.right != null) {
						nextLevel.push(node.right);
					}

				} else {
					if (node.right != null) {
						nextLevel.push(node.right);
					}
					if (node.left != null) {
						nextLevel.push(node.left);
					}
				}
			}
			result.add(currLevelResut);
			//此时 currLevel 已经pop完了 是空的 
			tep = currLevel;
			currLevel = nextLevel;
			nextLevel = tep;//所以赋值给新的nextLevel
			normalOrder = !normalOrder;
		}

		return result;

	}

}
