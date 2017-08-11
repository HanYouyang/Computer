package frequency_4;

//一个二叉树 从root到一个叶子算一个path 假设树是
//         1
//        / \
//       2   3
//那么一个path就是 12 一个path就是13 我们要返回的答案就是 12+13=15
//显然 这个就是dfs了 深度优先 搜索  循环+递归
//ps 假设有三层 1-2-4 =124 那么 就等于在下一层等于上一层x10+本层
//eg 第一层1  第二层1x10+2=12 第三层12x10+4=124

public class SumRoottoLeafNumbers {
  int res;  //写在这是成员变量 所有方法都可以操作他 或者你要通过方法传参数的情况
            // 这个res是整棵树的总和了
	public int sumNumbers(TreeNode root) {
		if (root == null) {
			return 0;
		}
		res=0;
		sumNumbers(root,0); //相当于root的“上层”是0 
		return res;
		
	}
                                                //pathsum是一条路径的值
	public void sumNumbers(TreeNode root, int pathsum){
		if(root.left==null&&root.right==null){ //已经加到path底部 pathsum完整了 加到res类里
		res=res+pathsum*10+root.val;
		}
	if(root.left!=null){
		sumNumbers(root.left,pathsum*10+root.val);
	}
     if(root.right!=null){
    	 sumNumbers(root.right,pathsum*10+root.val);
     }		 
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
