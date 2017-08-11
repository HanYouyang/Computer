package frequency_1;
//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest
//path from the root node down to the nearest leaf node.

//       1
//      /
//     2  是两层高度   
public class MinimumDepthofBinaryTree {
	 public int minDepth(TreeNode root) {
	     if(root==null){
	    	 return 0;
	     }
	   int left=minDepth(root.left);//左子树的最小深度
	   int right=minDepth(root.right);//右子树的最小深度
	   if(left==0){
		   return right+1;
	   }
	   if(right==0){
		   return left+1;
	   }
	   return Math.min(left, right)+1;
		 
	    }
}
