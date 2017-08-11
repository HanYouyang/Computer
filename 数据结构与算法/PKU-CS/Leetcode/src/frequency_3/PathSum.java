package frequency_3;

//九章DFS模板  dfs的结束条件是root没有子节点（root是叶子） 
//然后 不用写for循环 因为是二叉树 只要分别递归左右子节点当新root即可。 
//记得 (不管这个递归方法是怎么结束的 因为 只有一个onePath作为单条path的缓存 
//		所以递归方法啊结束时候都要 onePath.remove(onePath.size()-1);
public class PathSum {
	public boolean hasPathSum(TreeNode root, int sum) {

		if (root == null) {
			return false;
		}

		sum = sum - root.val;
		// 结束条件 当 到叶子节点时候sum==0
		if (root.left == null && root.right == null) {
			if (sum == 0) {
				return true;
			}
		}
     if(hasPathSum(root.left,sum)){return true;}
     if( hasPathSum(root.right, sum)){return true;}
     return false; 
	}
}
