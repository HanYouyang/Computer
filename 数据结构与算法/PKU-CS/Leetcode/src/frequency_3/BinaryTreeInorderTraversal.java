package frequency_3;

import java.util.ArrayList;
import java.util.Stack;

//recursive 不写了 题目要求 iterator写法 
//中序  左 中 右  先最左 再中 再最右
public class BinaryTreeInorderTraversal {
	public ArrayList<Integer> inorderTraversal(TreeNode root) {
		ArrayList<Integer> result = new ArrayList<Integer>();
		if (root == null) {
			return result;
		}
		Stack<TreeNode> stack=new Stack<TreeNode>();
		TreeNode curr=root;
		while(curr!=null||!stack.isEmpty()){
			if(curr!=null){
				                       //如果是pre order就是在这里加入结果
				stack.push(curr);
				curr=curr.left;
			}else{
				curr=stack.pop();
				result.add(curr.val); 
			curr=curr.right;
			}
		}
		
return result;	}
}

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
	}
}