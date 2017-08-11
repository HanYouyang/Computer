package frequency_3;

import org.omg.CORBA.Current;

//Given a singly linked list where elements are sorted in ascending order,
//convert it to a height balanced BST.

//"先判断linkedlist长度 再根据长度构造这个平衡的bst。又因为 bst用中序遍历的访问次序就是sorted ，所以利用这个特点 我们按照中序给这个bst里塞sorted linked list的值即可.  1.先遍历LL求出size 然后 if(size<=0){   return null;  }                                                                                      TreeNode left=sortedListToBSTHelper(size/2); //就是中序的逻辑 先访问左边
//TreeNode root=new TreeNode(curr.val);  //再root上塞一个LL值
//curr=curr.next;  //然后LL这个用过了 换到下一个  //再访问右，这样保证塞值按中序顺序
//TreeNode right=sortedListToBSTHelper(size-1-size/2); //因为LL里面已经少一个了
//root.left=left;   root.right=right;"

public class ConvertSortedListtoBinarySearchTree {
	private ListNode curr;

	public TreeNode sortedListToBST(ListNode head) {
		int size;
		curr = head;
		size = getListLength(head);
		return sortedListToBSTHelper(size);

	}

	// 遍历求长度
	private int getListLength(ListNode head) {
		int size = 0;

		while (head != null) {
			size++;
			head = head.next;
		}
		return size;
	}
	
	private TreeNode sortedListToBSTHelper(int size){
		if(size<=0){
			return null;
		}
		//请注意 这个方法 肯定是递归调用所以就像inorder一样 左 中右	
		//肯定是先执行  	TreeNode left=sortedListToBSTHelper(size/2);
		//所以到最后肯定会1/2 是0,return null回上层  此时curr 是head
		//root是curr(head)的值是linkedlisdlist里最小的值
		//然后curr=curr.next
		//其实这方法递归的逻辑和inorder一样 左中右，然后每次往中里面
        //填值之后 就是curr=curr.next找下一个 
		TreeNode left=sortedListToBSTHelper(size/2);
		TreeNode root=new TreeNode(curr.val);
		curr=curr.next;
		                                       //因为LL里面已经少一个了
		TreeNode right=sortedListToBSTHelper(size-1-size/2);
		root.left=left;
		root.right=right;
		return root;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
