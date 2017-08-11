package frequency_1;
//没啥好说的 中序比一边 注意2个都是空树也返回true
public class SameTree {
	  public boolean isSameTree(TreeNode p, TreeNode q) {
	        if(p==null&&q==null){
	            return true;
	        }else if(q==null&&p!=null){
	            return false;
	        }else if(p==null&&q!=null){
	            return false;
	        }
	        
	        if(!isSameTree(p.left,q.left)){
	            return false;
	        }
	        if(q.val!=p.val){
	            return false;
	        }
	        
	         if(!isSameTree(p.right,q.right)){
	            return false;
	        }
	        
	        
	        
	        return true;
	    }
}
