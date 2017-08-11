package newQuestion;

import java.util.ArrayList;
//普通的postorder traverse 结果放arraylist里面
//用九章算法的模板来做 "

public class BinaryTreePostorderTraversal {
	 public ArrayList<Integer> postorderTraversal(TreeNode root) {
	        ArrayList<Integer> result=new ArrayList<Integer>();
	        if(root==null){
	            return result;
	            }
	            postOrder(root,result);
	        return result;
	    }
	    
	    private void postOrder(TreeNode root, ArrayList<Integer> result){
	        if(root ==null){
	            return;
	        }
	        postOrder(root.left,result);
	        postOrder(root.right,result);
	        result.add(root.val);
	    }
}
