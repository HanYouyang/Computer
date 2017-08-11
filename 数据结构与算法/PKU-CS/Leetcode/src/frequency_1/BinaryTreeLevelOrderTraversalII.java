package frequency_1;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

//Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
//		(ie, from left to right, level by level from leaf to root).

//level order traversal 但是返回最底下一层 再返回 倒数第二层。。最后返回root
//标准bfs做法 但是每次把curr层的结果加到总result的0位置 
//这样每次越下面的层就加到最前去了
public class BinaryTreeLevelOrderTraversalII {
public ArrayList<ArrayList<Integer>> levelOrderBottom(TreeNode root) {
        ArrayList<ArrayList<Integer>> result=new ArrayList<ArrayList<Integer>>();
     
        
		if (root == null) {
			return result;
		}
		 
		Queue<TreeNode> queue =new LinkedList<TreeNode>();
		queue.add(root);
		TreeNode current;
		while (!queue.isEmpty()) {
			ArrayList<Integer> arrayList = new ArrayList<Integer>();
			int num = queue.size();
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

        	result.add(0,arrayList);
       
        }
return result;    
}
}





//方诗元解法 就是每次递归先调用把下一层加入总结果 再加入本层
//这样会最先加入最后一层，再递归return 回来 加到数第二层
//最后加root
//public class BinaryTreeLevelOrderTraversal2_V1 {
//public static ArrayList<ArrayList<Integer>> levelOrderBottom(TreeNode root) {
//    Queue<TreeNode> queue = new LinkedList<TreeNode>();
//    queue.offer(root);
//    return rec(queue);
//}
//
//private static ArrayList<ArrayList<Integer>> rec(Queue<TreeNode> queue) {
//    ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
//    if (queue.isEmpty()) {
//        return ret;
//    }
//    Queue<TreeNode> newQ = new LinkedList<TreeNode>();
//    ArrayList<Integer> list = new ArrayList<Integer>();
//    while (!newQ.isEmpty()) {
//		TreeNode tmp =  queue.poll();
//        newQ.offer(tmp.left);
//        newQ.offer(tmp.right);
//        list.add(tmp.left.val);
//        list.add(tmp.right.val);
//    }
//    ret.addAll(rec(newQ));
//    ret.add(list);
//    return ret;
//}
//
//public static class TreeNode {
//	int val;
//	TreeNode left;
//	TreeNode right;
//
//	TreeNode(int x) {
//		val = x;
//	}
//}
//
//public static int maxDepth(TreeNode root) {
//	if (root == null)
//		return 0;
//	int lmax = maxDepth(root.left);
//	int rmax = maxDepth(root.right);
//	return lmax > rmax ? (lmax + 1) : (rmax + 1);
//}
//
//public static void main(String[] args) {
//	TreeNode node1 = new TreeNode(1);
//	TreeNode node2 = new TreeNode(2);
//	TreeNode node3 = new TreeNode(3);
//	TreeNode node4 = new TreeNode(4);
//	TreeNode node5 = new TreeNode(5);
//	TreeNode node6 = new TreeNode(6);
//	TreeNode node7 = new TreeNode(7);
//
//	node1.left = node2;
//	node1.right = node3;
//	node2.left = node4;
//	node2.right = node5;
//	node3.left = node6;
//	node3.right = node7;
//
//	ArrayList<ArrayList<Integer>> a = levelOrderBottom(node1);
//	for (int i = 0; i < a.size(); i++) {
//		for (int j = 0; j < a.get(i).size(); j++) {
//			System.out.print(a.get(i).get(j) + " ");
//		}
//		System.out.println();
//	}
//}
//}
