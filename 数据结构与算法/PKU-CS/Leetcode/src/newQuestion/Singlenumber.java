package newQuestion;

//Given an array of integers, every element appears twice except for one. Find that single one.
//位运算 用异或  ^

// 0000^1010= 1010    0^其他值=其他值
// 1010^1010=0000     值^值=0

public class Singlenumber {
	public int singleNumber(int[] A) {
//result=用0^数组里面的所有数 成双成对的都成0了 
//最后结果result=0^那个唯一的数=唯一的数
		int result = 0 ^ A[0];
		for (int i = 1; i < A.length; i++) {
			result = result ^ A[i];
		}
		return result;
	}
}
