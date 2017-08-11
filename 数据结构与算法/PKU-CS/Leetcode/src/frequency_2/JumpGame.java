package frequency_2;

//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.
//
//For example:
//A = [2,3,1,1,4], return true.
//
//A = [3,2,1,0,4], return false. 
//1.dp做法 完全类似 word break1 O（N2） 2. 类似 maximum sub array 扫描数组并记录
//此时能最远到哪一格是i + A[i]，如果已经比当前格子小了maxLen < i 那么肯定是不行了 return false
public class JumpGame {

	// 做法2
	public boolean canJump(int[] A) {
		int len = A.length;
		int maxLen = 0;
		for (int i = 0; i < len; i++) {
			if (maxLen < i) {
				return false;
			}
			maxLen = Math.max((i + A[i]), maxLen);
		}
		return true;
	}


//DP 做法
//	1.dp做法 完全类似 word break1   
//	2个for循环 每次内循环检查如果A[j]能不能跳到 i位 能的话就can[i]=true 然后看最后一位能不能true
	    public boolean canJump2(int[] A) {
	        boolean[] can = new boolean[A.length];
	        can[0] = true;
	        
	        for (int i = 1; i < A.length; i++) {
	            for (int j = 0; j < i; j++) {
	                if (can[j] && j + A[j] >= i) {
	                    can[i] = true;
	                    break;
	                }
	            }
	        }
	        
	        return can[A.length - 1];
	    }
	

}
