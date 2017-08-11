package frequency_2;

import java.util.ArrayList;

//Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//For example:
//Given the below binary tree and sum = 22,
//
//             5
//            / \
//           4   8
//          /   / \
//         11  13  4
//        /  \    / \
//       7    2  5   1
//返回所有root到叶子 的的完整路径 where path sum是指定值
//用九章算法模板 ！

public class PathSumII {
	public ArrayList<ArrayList<Integer>> pathSum(TreeNode root, int sum) {
		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
		ArrayList<Integer> onePath = new ArrayList<Integer>();
        find_sum(result,onePath,root,sum);
	     return result;
	  }

	private void find_sum(ArrayList<ArrayList<Integer>> result, ArrayList<Integer> onePath, TreeNode root, int sum){
	if(root==null){
		return;
	}	
	sum=sum-root.val;
	//结束条件，表示已经到root节点
	if(root.left==null&&root.right==null){
		if(sum==0){ //sum里面的值正好扣完,path 的sum正好是sum 
			
			onePath.add(root.val);
			result.add(new ArrayList<Integer>(onePath));
			onePath.remove(onePath.size()-1);
		}
		return; //找到path了 这个dfs的枝桠走完到底了 结束
	}
	
	onePath.add(root.val);
	//这里没写for循环 取而代之的是 左右子树
	find_sum(result, onePath, root.left, sum);
	find_sum(result, onePath, root.right, sum);
	onePath.remove(onePath.size()-1);//把这次加的root给删了 因为onePath这个arrayList是唯一的
	//比方说随着dfs的越来越深入 onePath里面的int也越来越多。直到到叶子节点 如果是对的值放result
	//但是随着递归方法结束的返回 ,每一层都把自己加的那个值删掉，最后返回调用层的时候 那些由递归层
	//加的数字又删掉了。 比方说find_sum(result, onePath, root.left, sum); 然后 one Path里int越来越多
	//但是递归都返回的时候 又都删掉了
	//所以 find_sum(result, onePath, root.right, sum); 也从正常的位置开始加
	
	
	}
	
	static class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;

		TreeNode(int x) {
			val = x;
		}
	}

}
