package newQuestion;

import java.util.ArrayList;
//普通的preorder traverse 结果放arraylist里面
//用九章算法的模板来做 
public class BinaryTreePreorderTraversal {
public ArrayList<Integer> preorderTraversal(TreeNode root) {
      ArrayList<Integer> result= new ArrayList<Integer>();
      preorder(root,result);
      return result;
    }

private void preorder(TreeNode root,ArrayList<Integer> result){
	if(root==null){
		return;
	}
	result.add(root.val); //对root的访问放在这 前序
	preorder(root.left,result);
	//对root的访问放在这 中序
	preorder(root.right,result);
	//对root的访问放在这 后序

}


}

class TreeNode {
	    int val;
	     TreeNode left;
	    TreeNode right;
	     TreeNode(int x) { val = x; }
	 }