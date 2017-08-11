package frequency_5;
//You are climbing a stair case. It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 

//这题和 n分有135分组成有点相似 ，但是分币那题是组合，这题是排列 有先后顺序。
//显然是要递归来做
//DP dynamic Programming的思想 先确定小问题 在递推 
//如果只有1个step, 那只有一种解法 1步, 如果有2步的话 , 二种解法 2步一次 和1步两次
//当有3个step的时候 如果 第一次走1步 接下去就是f(2) 如果 第一次走2步 接下去就是f(1)
// 当还剩n个阶梯的时候, 本次无非就2种可能  走1部 走2部  然后走一步就是f(n-1) 走两步就是f(n-2)
//f(n)=f(n-1)+f(n-2)  和费波那切数列很像
public class ClimbStairs {

	
	//用iterator 做会避免递归产生的重复子结构
	
public int climbStairs(int n) {
 if(n<=0){return 0;}
 if(n==1){return 1;}
 int n1=1;
 int n2=2;
 int n3=n2; //=2 at the initial point
 for(int i=3;i<=n;i++){  //这里n1 n2 n3 都是步数。
	 n3=n1+n2;  // 本质还是f(n)=f(n-1)+f(n-2)         f(n)=f(n-1)+走一步  +  f(n-2)+走两步  走一步 走两步 都是一种走法
	 n1=n2;     //每当i++时候
	 n2=n3;     //n1=上一次的n2 n2等于上一次的n3
	            //这样等于线性加一次 复杂度0（n）
 }
	return n3;
	
}
	
	
	
	
	
	
	
	//  这么写的是对的 但是 会超时， 为什么呢？ 
	//比如你现在F(3) = F(2) + F(1)，在计算F(4) = F(3) + F(2)的时候计算了2次F(2)，这个叫重复子结构
// 在recursion里面 会出现很多重复子结构 会超时。
//	public int climbStairs(int n) {
//		int ways=0;
//		if (n <= 0) {
//			return 0;
//		} else {
//			if (n == 1) {
//				return 1;
//			}
//			if (n == 2) {
//				return 2;
//			}
//			if (n >= 3) {
//				ways= climbStairs(n - 1) + climbStairs(n - 2);
//			}
//
//		}
//		return ways;
//	}

	public static void main(String[] args) {
		System.out.println((new ClimbStairs()).climbStairs(5));

	}

}
