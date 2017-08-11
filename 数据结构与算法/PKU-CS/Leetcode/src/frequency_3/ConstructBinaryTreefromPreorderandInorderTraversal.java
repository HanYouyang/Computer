package frequency_3;

//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree. 
//知道前序和中序构造树
/*
 *             5
 *            /  \          
 *           2    7 
 *          / \  / \
 *         1  3 6   8     
 *中序     1235678
 *前序    5213768  所以root是前序第一个 val是5 
 *然后 去中序数组里找 5的position 5左边的 都是左子树，5右边的都是右子树
 *在前序里面 213 ( prestart+1, prestart+position-instart) 左子树  768( prestart+position-instart+1, preend) 右子树
 *再递归调用找本方法  myBuildTree找左右子树的root,就是 总root的5的left和right  
 *最后return root
 */
public class ConstructBinaryTreefromPreorderandInorderTraversal {
	public TreeNode buildTree(int[] preorder, int[] inorder) {
		if (inorder.length != preorder.length) {
			return null;
		}
		return myBuildTree(inorder, 0, inorder.length - 1, preorder, 0,
				preorder.length - 1);

	}
	
	private TreeNode myBuildTree(int[] inorder,int instart,int inend,int[] preorder,int prestart,int preend){
		if(instart>inend){
			return null;
		}
	TreeNode root=new TreeNode(preorder[prestart]);
	int position=findPosition(inorder,instart,inend,preorder[prestart]);
	root.left=myBuildTree(inorder, instart, position-1, preorder, prestart+1, prestart+position-instart);
	root.right=myBuildTree(inorder, position+1, inend, preorder, prestart+position-instart+1, preend);
	return root;
	}
  //找 root在 inorder里的下标 
	private int findPosition(int[] arr, int start, int end, int key) {
        
        for (int i = start; i <= end; i++) {
            if (arr[i] == key) {
                return i;
            }
        }
        return -1;
    }


}
