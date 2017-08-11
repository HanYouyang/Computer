package frequency_2;

import java.util.Stack;


//For example,
//Given height = [2,1,5,6,2,3],
//return 10. 
//
//比方说有一个直方图 height = [2,1,5,6,2,3],里面每个数组就是 直方图里每个数字的高度
//然后要在直方图里求最大矩形的高度  比方说在 215623里 最大的矩形就是56 2个柱子组成的  2×5=10
//用 window sliding的做法来做 类似maximum sub array
//右边一直向右遍历 然后每遍历一次看看左边的情况，用一个栈辅助(栈里面存的是index) 栈里面要维护严格递增 
//eg:比方说 数组是1432  下标是0123
//一开始push1 stack.push(index-0); 此时没进while循环 不用算面积
//然后134 都没有进while 然后 不触发算面积
//然后 到要装2的时候（此时i是3） 进了while循环 
//循环第一次 currentHeight2 比4 大 此时 h是4 w是1  max更新成4
//循环第二次 currentHeight2 比3 大 此时 h是3 w是2 max 更新成6
//然后把3也仍完了 stack里就是 1 2 然后再右边再继续 slides
public class LargestRectangleinHistogram {

	public int largestRectangleArea(int[] height) {
	      if(height==null||height.length==0){
	    	  return 0;
	      }  
	Stack<Integer> stack=new Stack<Integer>();
	int max=0;
	//slicd window
	for(int i=0;i<=height.length;i++){
		 //目前右侧滑到哪里了(i就是右届)？要是到已经越界了就是 -1 没越界高度就是height[i]   
		int currentHeight=(i==height.length)?-1:height[i];
		//这个height是严格要保持递增的 
		//比方说数组是 1342
		//我插完134之后 我要把 34都pop出来才能插2 之后就是1 2                                          index
	 	//这个while循环就是pop 3 4的过程       //注意 stack里存的是index 所以是currentHeight和height[stack.peek()]比
		while(!stack.isEmpty()&&currentHeight<=height[stack.peek()]){
			//因为stack内的int是递增的所以 最后height是弹出的height里最短的那个已经最后弹出的是height[1]=3
			int h=height[stack.pop()];
			//eg: pop3,4完了之后 index里面只有0这一个元素了 ,然后此时peek到1比2小 所以此时width是3-0-1=2;
			int w=stack.isEmpty()?i:i-stack.peek()-1;
	        max=Math.max(max,h*w);//所以pash2的时候 面积是2x3 
		}
	       stack.push(i); //注意  stack 里面装的是i！！！是index
	      
	}
	
return max;	
	}
	

}
