package frequency_2;

import javax.swing.text.StyledEditorKit.ForegroundAction;
//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//For example:
//Given array A = [2,3,1,1,4]
//
//The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.) 

//用最少的跳跃步数走到低 最少几步？
//九章算法DP模板
//一维数组预处理 steps[0]=0; 走到i部最少需要 跳 steps[i]次
//初始 	steps[0]=0;
//然后2个for寻外 外部 是遍历steps i~N
//内循环 是从0～j 然后   （0--j--n--A.length）
//如果steps[j]!=integer.max(表示A的J位置是走的到得) 然后 如果j+A[j]>=i 
///表示 A[j] 跳一次就走的到A[i] 所以 steps[i]=steps[j]+1;
////因为j是从小到大的遍历 所以后面往后肯定是越来越大了 所以break
//遍历到外循环结束steps[A.length-1]即可。

public class JumpGame2 {
	public int jump(int[] A) {
	int[] steps= new int [A.length];
  //base case  走到第0格式后 
	steps[0]=0;

for(int i=1;i<A.length;i++){
	steps[i]=Integer.MAX_VALUE;
	//记得内循环是从0开始
	for(int j=0;j<i;j++){
		//如果steps [i]=Integer.Max 说明  没有办法走到A[i]
		//i 和j都是下标   0----j----i-----A.length
		// A[j]代表 在j位   最多跳几步,如果 j+A[j]>=i 表示 j位再跳一下(这下A[j]) 能到i
				if(steps[j]!=Integer.MAX_VALUE&&j+A[j]>=i){
			//所以 steps[j]+在跳1次  就至少到i位置了 所以	steps[i]=steps[j]+1;
			steps[i]=steps[j]+1;
			break; //因为j是从小到大的遍历 所以后面往后肯定是越来越大了 所以break
		}
	}
}
return steps[A.length-1];
}
	}
