package frequency_3;
//Given a sorted array of integers, find the starting and ending position of a given target value.
//Your algorithm's runtime complexity must be in the order of O(log n).
//If the target is not found in the array, return [-1, -1].
//For example,
//Given [5, 7, 7, 8, 8, 10] and target value 8,
//return [3, 4].
//在一个有重复值的sorted array里面 找key 返回这个key的所有下标 
//用2次BS 一次找左下标 一次找右下标
//怎么保证找到的是最左/最右呢？  
//比方说找左就是在A[mid]=target时候 end=mid 这样就保证在答案范围内mid越来越左边 直到start+1<end 跳出
// 最后在检查if的时候start就是result[0].。除非此时start不是了 那么说明只有一个数字符合答案 就是A[end]=end
// 反之亦然
public class SearchForARange {

	public int[] searchRange(int[] A, int target) {
	     //用2分法(sorted-lgn) 9章算法的模板
	      if(A.length==0||A==null){
	          int[] result={-1,-1};
	          return result;
	      }
	      int[] bound = new int[2]; 
	      int start=0;
	      int end=A.length-1;
	      int mid=0;
	      //找答案的左下标
	      while(start+1<end){
	         mid=start+(end-start)/2;
	          //所以当mid=terget时候 end=mid了 就让新mid在往老mid的左边找  
	          if(A[mid]==target){
	              end=mid;
	               
	          }else if(A[mid]<target){
	           start=mid;
	          }else{
	              end=mid;
	          }
	      }
	      if(A[start]==target){
	    	  bound[0]=start;
	      }else if(A[end]==target){
	    	  bound[0]=end;
	      }else{
	    	  bound[0]=bound[1]=-1;
	    	  return bound;
	      }
	      //search for right bound
	      start=0;
	      end =A.length-1;
	      while(start+1<end){
	    	  mid=start+(end-start)/2;
	    	  if(A[mid]==target){
	    		  start=mid; //	    所以当mid=terget时候 start=mid了 就让新mid在往老mid的右边找
	    	  }else if(A[mid]<target){
	    		  start=mid;
	    	  }else{
	    		  end=mid;
	    	  }
	    		  
	      }
	      if(A[end]==target){
	    	  bound[1]=end;
	      }else if(A[start]==target){
	    	  bound[1]=start;
	      }else{
	    	  bound[0]=bound[1]=-1;
	    	  return bound;
	      }
	      return bound;
	    }
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
