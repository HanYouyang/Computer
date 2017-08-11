package frequency_2;

import org.omg.CORBA.PRIVATE_MEMBER;

//Two elements of a binary search tree (BST) are swapped by mistake.
//
//Recover the tree without changing its structure.就是说只用换val就行了

//BST里面2个node被swap了 破坏了 bst  你要那这个树恢复成BST

//用九章算法模板 

//设想 这题要是不coding的话,按照正常人的逻辑怎么算呢？ 这么找到这错换的节点呢？

//就好比在一个sorted数组里（bst中序遍历就是sorted数组） 如果有2个数位置换过了
//那么肯定要打破sort （sort状态下 本root肯定大于上一个root） 那么这里本root小于inorder递归的上一个root 肯定就是错的node 
//有2个node 会打破这点 （）  所以中序遍历+检查 即可
public class RecoverBinarySearchTree {

	private TreeNode firstElement=null;
	private TreeNode secondElement=null;
	//初始的lastElement是 最小值。用于标记 
	private TreeNode lastElement=new TreeNode(Integer.MIN_VALUE);
	
	
	public void recoverTree(TreeNode root) {
	       //traverse and get two elements
		
		traverse(root);
		//swap the wrong ordered element 然后把2个打破的swap一下即可 
		int temp=firstElement.val;
		firstElement.val=secondElement.val;
		secondElement.val=temp;
	    }
	
	//in-order traverse
	private void traverse(TreeNode root){
		if (root==null) {
			return;
		}
		traverse(root.left);
		if(firstElement==null&&root.val<lastElement.val){//本层递归的root和 中序遍历的上个node比看看打不打破sort
			firstElement=lastElement;  //第一个打破的sort的node
		}
		if(firstElement!=null&&root.val<lastElement.val){//本层递归的root和 中序遍历的上个node比看看打不打破sort
			secondElement=root;  //第二次打个打破的sort的node
		}
		lastElement=root; // 每次中序遍历的上一个node  
		traverse(root.right);
	}

     

}
