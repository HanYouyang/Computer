package frequency_1;
//求树的高度
//九章算法 模板做
public class MaximumDepthofBinaryTree {
	 public int maxDepth(TreeNode root) {
	       if(root==null){
	    	   return 0;
	       }
	       
	       int left=maxDepth(root.left);
	       int right=maxDepth(root.right);
	       return Math.max(left, right)+1;
	    }
	
}
class TreeNode {
	    int val;
	     TreeNode left;
	      TreeNode right;
	      TreeNode(int x) { val = x; }
	 }