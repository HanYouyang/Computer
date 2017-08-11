package frequency_3;
//Given the following perfect binary tree, 
//       1 
//     /  \ 
//    2    3 
//   / \  / \ 
//  4  5  6  7 
//After calling your function, the tree should look like: 
//     1 -> NULL 
//    /  \ 
//   2 -> 3 -> NULL 
//  / \  / \ 
// 4->5->6->7 -> NULL 

//类似level order一样的指针next 但是一层的最后指向null


public class PopulatingNextRightPointersinEachNode {
//bfs 
	
	public void connect(TreeLinkNode root) {
	     if(root==null){
	    	 return;
	     }
		 if(root.left!=null){
			 root.left.next=root.right;
		 }
		 //处理5连6的情况 
		 if(root.right!=null&&root.next!=null){
			 root.right.next=root.next.left;
		 }
			
		 connect(root.left);
		 connect(root.right);
	    }
}
 class TreeLinkNode {
	      int val;
	      TreeLinkNode left, right, next;
	      TreeLinkNode(int x) { val = x; }
	  }