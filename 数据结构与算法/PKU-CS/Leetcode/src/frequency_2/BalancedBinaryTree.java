package frequency_2;
//
//Given a binary tree, determine if it is height-balanced.
//
//For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
//这提要求每一个子树的高度都一样 而不是一整棵树 所有有点不同
//不是CC原题 我们用九章的模板来做   (和cc做法稍微不一样，cc是求树的最深node和最浅node的差 )
//我们这 是每次recursive求左子树的高度和右子树的高度，（还记得高度怎么求么 叶子节点往下null返回0 然后叶子节点返回0+1 再上就返回1+1）但是如果左/右子树已经不平衡了 或者 两者高度相差大于1了 就返回-1
//然后就一层层网上返回-1 最后false
//递归   比较左子树和右子树的高度 差《=1就是true 》1就是false
//随便在纸上画个不平衡的树你就明白
public class BalancedBinaryTree {
	
	 public boolean isBalanced(TreeNode root) {
	      return maxDepth(root)!=-1;  
	    }
	 
	 private int maxDepth(TreeNode root){
		 if(root==null){
			 return 0;
		 }
	 
	 int left=maxDepth(root.left);
	 int right=maxDepth(root.right);
	 if(left==-1||right==-1||Math.abs(left-right)>1){
		 return -1;  //我的左右子树不平衡了 就 返回-1
	 }
	 
	 return Math.max(left,right)+1;
}
}


 class TreeNode {
	     int val;
	    TreeNode left;
	     TreeNode right;
	    TreeNode(int x) { val = x; }
	 }
