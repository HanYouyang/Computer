package frequency_2;

import java.util.LinkedList;
import java.util.Queue;

//Follow up for problem "Populating Next Right Pointers in Each Node".
//
//What if the given tree could be any binary tree? Would your previous solution still work?
//
//Note:
//
//You may only use constant extra space.
//第二题：不一定是满二叉树了 就是 普通的二叉树 
//还是让每一层的节点指向右边的节点。 
////eg   1 -> NULL
//      /  \
//     2 -> 3 -> NULL
//    / \    \
//   4-> 5 -> 7 -> NULL


//更简易的思路 类似 level order
//利用level order 特性， while (!queue.isEmpty()) {   int size = queue.size();（当前queue里 二叉树当前层的元素个数得到后）for循环，
//是先poll当前层的一个node 然后把当前poll出来加左右儿子，然后 如果此时如果for循环的i<size-1， 
//说明current这个node后面还有本层的其他node 所以  current.next = queue.peek()
public class PopulatingNextRightPointersinEachNodeII {
	public void connect(TreeLinkNode root) {
		if (root == null) {
			return;
		}
           
		Queue<TreeLinkNode> queue = new LinkedList<TreeLinkNode>();
		queue.add(root);
		while (!queue.isEmpty()) {
			int size = queue.size();  //表示当前level的size
			for (int i = 0; i < size; i++) {
				TreeLinkNode current = queue.poll();
				if (current.left != null) {//把左右儿子 加入queue
					queue.add(current.left);
				}
				if (current.right != null) {
					queue.add(current.right);
				}
				if (i < size - 1) {//在for循环里 是在遍历本层queue里面的node 然后当 current node还没到最后一个的时候
					                //current.next指向queue  里下一个  queue.peek();
					current.next = queue.peek();
				}
			}
		}
	}
}

class TreeLinkNode {
	int val;
	TreeLinkNode left, right, next;

	TreeLinkNode(int x) {
		val = x;
	}
}