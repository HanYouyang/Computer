package frequency_2;

import frequency_4.SingleNumber;

//找出一个数树的一条path，这条path的node的和为最大值，并且这个path可以从任何一个node开始，/\也可以 （上去再下来也算一条path）
//只要连着就行
//左子树的单路就是做root。Left出发 然后到下面path的一条路路径  右子树的单路也是一样
//然后你可以再看看吧他们用root连起来之后 是不是 会更大 
//用九章的模板来做-devided and concer 模板
//           single path 单边的链条
//            /    or \
//           /         \
//            maxPath    双边但是连在一起的
//             /\
//            /  \
//           /    \
public class BinaryTreeMaximumPathSum {
	private class ResultType{
		int singlePath,maxPath;
		public ResultType(int singlePath,int maxPath) {
			this.singlePath=singlePath;
			this.maxPath=maxPath;
		}
	}
	
	public int maxPathSum(TreeNode root){
		ResultType result=helper(root);
		return result.maxPath;
	}
	
	public ResultType helper(TreeNode root) {
	    if(root== null){
	    	return new ResultType(0, Integer.MIN_VALUE);
	    } 
		//devided 分治法 先分 把问题全部递归给左子树和右子树 最后在在本层处理左子树和右子树返回的东西
	    ResultType left=helper(root.left);
	    ResultType right=helper(root.right);
	    
	    //conquer 在本层处理左子树和右子树返回的东西
	    //single Path指的是左/右子节点往下的path中取出大的那个+(连上)root 的值
	    int singlePath=Math.max(left.singlePath, right.singlePath)+root.val;
	    //singlePath如果是负的就舍弃（有点像maxium sub array）
	    singlePath=Math.max(singlePath, 0);
	    //maxPath先是比左右子树内部的双边链 那个大就取那个
	    int maxPath=Math.max(left.maxPath,right.maxPath);
	    //然后在连上本次递归的root成为的双边链 看看那个大
             
	    maxPath=Math.max(maxPath,left.singlePath+right.singlePath+root.val);
	    return new ResultType(singlePath, maxPath);
	    		
	 }
}
