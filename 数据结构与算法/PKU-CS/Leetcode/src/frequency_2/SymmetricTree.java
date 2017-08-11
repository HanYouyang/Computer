package frequency_2;

//    1           
//   / \
//  2   2
// / \ / \
//3  4 4  3  true 左子树的右边和右子树的左边一样 mirror symmetric  不是相同子树 
//
//    1
//   / \
//  2   2
//   \   \
//   3    3
// false 虽然左右子树一样 但是不是mirror of itself

//检查一棵树是否 mirror symeetric
//devide and concur的思路 bfs
//因为root肯定只有1个 
public class SymmetricTree {
	public boolean isSymmetric(TreeNode root) {
		if (root == null) {
			return true;
		}
return isSymmetric(root.left,root.right);
	}

	public boolean isSymmetric(TreeNode left,TreeNode right) {
		if(left==null&&right==null){
			return true;
		}else if(left!=null&&right!=null){
			// 左子树的右边和右子树的左边一样 mirror symmetric  不是相同子树 
	return left.val==right.val&&isSymmetric(left.left,right.right)&&isSymmetric(left.right, right.left);
		}else{
			return false;
		}
	}
}
