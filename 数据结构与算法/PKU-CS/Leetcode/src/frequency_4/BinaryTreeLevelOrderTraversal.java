package frequency_4;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
//java  中 queue是接口 stack是现成类 可以用linkedlist实现 


public class BinaryTreeLevelOrderTraversal {
	// level order 每层输出一个arraylist<Interger>
	// 用bfs 就是用 queue 每次把上层节点放入 然后dequeue的时候 就 放入dequeue节点的子节点
	//
	public ArrayList<ArrayList<Integer>> levelOrder(TreeNode root) {
		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
		if (root == null) {
			return result;
		}
		 
		Queue<TreeNode> queue =new LinkedList<TreeNode>();
		queue.add(root);
		TreeNode current;
		while (!queue.isEmpty()) {
			ArrayList<Integer> arrayList = new ArrayList<Integer>();
			int num = queue.size();// 当前这个while循环有的current size
									// 一开始是root第一层 然后root
									// dequeue的时候会把第二层全放进queue
									// 然后第二层dequeue的过程中会把第三层都放进去queue
									// 所以每个while循环刚开始的时候queue里只有一层
									// 所以这才叫层次优先
			for (int i = 0; i < num; i++) {
				current = queue.remove();
				arrayList.add(current.val);
				if (current.left != null) {
					queue.add(current.left);
				}
				if (current.right != null) {
					queue.add(current.right);
				}
			}
	//一层遍历完了 把这for循环里的本层 加入result
			result.add(arrayList);
		}
return result;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
	}
}