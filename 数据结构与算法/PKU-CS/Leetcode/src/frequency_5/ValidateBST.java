package frequency_5;
 



 

// Assume a BST is defined as follows:
//
//    The left subtree of a node contains only nodes with keys less than the node's key.
//    The right subtree of a node contains only nodes with keys greater than the node's key.
//    Both the left and right subtrees must also be binary search trees.

//即如果一棵二叉树是BST，那么它的中序遍历是一个递增的数组。所以可以对中序遍历算法稍加修改，
//每次遍历，记录上一个元素，并跟当前节点元素值比较。
//空树是bst,但是ltcd里面认为bst 不可以有重复值
public class ValidateBST {
	
	//本质就是中序遍历 只不过让自己的左右子树都返回boolean
	static int lastVisit=Integer.MIN_VALUE;
	  public boolean isValidBST(TreeNode root) {
		if(root==null){	return true;}
		if(!isValidBST(root.left)){return false;}
		if(root.val<=lastVisit){return false;}
	    lastVisit=root.val;
		if(!isValidBST(root.right)){return false;}
	  return true;
	  
	  }
		 
	
	
	public static void main(String[] args) {
		TreeNode root=new TreeNode(0);
		TreeNode left=new TreeNode(-1);
		root.left=left;
		System.out.print((new ValidateBST()).isValidBST(root));
	}

}

 
class TreeNode {
    int val;    
    TreeNode left;
     TreeNode right;
     TreeNode(int x) { val = x; }
 }
