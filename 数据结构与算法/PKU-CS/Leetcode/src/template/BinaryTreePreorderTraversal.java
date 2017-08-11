package template;

import java.util.ArrayList;

public class BinaryTreePreorderTraversal {

	
	//模板
	 public ArrayList<Integer> preorderTraversal(TreeNode root) {
	     ArrayList<Integer> result=new ArrayList<Integer>();
		 traversal(root,result);
		 return result;
		 }
		 
	 
	public void  traversal(TreeNode root, ArrayList<Integer> result){
	if(root==null){
		return;
	}	 
	//do sth with the root(eg:print  visit  result.add(root.val);)  前序这一行
	traversal(root.left,result);
	//do sth with the root(eg:print  visit  result.add(root.val);) 中序在一样
	traversal(root.right,result );
	//do sth with the root(eg:print  visit  result.add(root.val);)  后序在者一样
	
	 
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