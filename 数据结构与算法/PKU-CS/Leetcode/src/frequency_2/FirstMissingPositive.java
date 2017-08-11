package frequency_2;

//Given an unsorted integer array, find the first missing positive integer.
//
//For example,
//Given [1,2,0] return 3,
//and [3,4,-1,1] return 2.
//
//Your algorithm should run in O(n) time and uses constant space. 
//找数组里面正数部分第一个缺失的正数。  0不用管，(你可以问面试官0要不要)
//http://www.cnblogs.com/AnnieKim/archive/2013/04/21/3034631.html

public class FirstMissingPositive {
	// 比方说 -5，-2，0，3，4 那么第一个 first MISSING positive 就是1
	// 那么扫描2遍数组， 第一遍 负数无视 然后扫到是正数的且小于A.length,假设值是i
	// 就把这个正数放到num[i-1]位置上去 eg 1就放到num[0] 位
	// (eg:为什么不放1位？如果A={0} 那么第二遍i只能=0开始遍历 然后A[0]==0 return元素长度+1 就变2了)
	// 换好后 再去从1扫描所租 第一个下标不等于值得就是first missing possible
	// 如果都等match上 比方说12345 那么fmp就是 A.length+1 6
	public int firstMissingPositive(int[] A) {
		if (A == null || A.length == 0) {
			return 1;
		}
		for (int i = 0; i < A.length; i++) { // A[i]==(i+1)说明已经在对的位置上 不用换
			while (A[i] > 0 && A[i] <= A.length && A[i] != (i + 1)) {
				//为什么用while,因为你换到i位的数字也要换到正确位置。否则下一步i++了 这里i位就不管了吗？
				int temp=A[A[i]-1];  //A[i] 应该存到A[i]-1;
				if(temp==A[i]){//eg:A[1]是4 A[3] 也是4 那么换来换就就会死循环
					 break;
				}  
				A[A[i]-1]=A[i];
				A[i]=temp;		 
			}
		}

		for (int i = 0; i < A.length; i++) {
			if (A[i] != i + 1) {
				return i + 1;
			}
		}
		return A.length + 1;
	}

	public static void main(String[] args) {
		int[] A = { 0 };
		int b = new FirstMissingPositive().firstMissingPositive(A);
		System.out.print(b);
	}
}
