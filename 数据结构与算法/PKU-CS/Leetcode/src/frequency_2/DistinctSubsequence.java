package frequency_2;

import java.lang.reflect.Array;
//Given a string S and a string T, count the number of distinct subsequences of T in S.
//
//A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
//Here is an example:
//S = "rabbbit", T = "rabbit"    S source

//
//Return 3. 
//这题的意思是 rabbit 可以有rabbbit的里面的有元素,在不改变顺序的情况下取里面的元素 能组成rabbit 就是可以
//比方说 rabbit可以由rabbbit的 第一第二个b 第二第三个b 第一第三个b组成 
//这样 有3种组成方法 所以是 返回3


import frequency_3.EditDistance;


public class DistinctSubsequence {
//2 sequence dp，九章模板 和edit distance很像
//一个矩阵num 宽为T.length+1 高为S.length+1    然后 num[i][j] 是  S缩写成T有几种方法
//	       空  r a b b i t 
// 空 	1 0 0 0 0 0 0    怎么理解 这个 matrix ,首先 是rabbit是要由 rabbbit的char里面组成 那么用2sequence矩阵保证顺序不会乱
// r	1 1 0 0 0 0 0   然后[0][0]是空组成空 那么1种方法，然后第一列上不管是空+rab.还是空+rabbbit组成空 都是只用第一个空 所以第一列都是1 
// a	1 1 1 0 0 0 0   然后 rab组成rab也是只有1种方法 [3][3]=1 但是如果要 从S rabb 组成T rab就有2种办法了 ra+b1  or ra+b2 所以[4][3]是2
// b	1 1 1 1 0 0 0   nums[4][3]=nums[4][3]+nums[3][2];=1+1=2  但是[4][4]又是1了 因为 rabb和rabb只有一种组成办法
// b	1 1 1 2 1 0 0   所以你现在应该看懂那2个for循环了 
// b	1 1 1 3 3 0 0 
// i	1 1 1 3 3 3 0 
// t	1 1 1 3 3 3 3 

	public int numDistinct(String S, String T) {
     if(S==null||T==null){
    	 return 0;
    	 }
     //初始状态 
     int[][] nums= new int[S.length()+1][T.length()+1];
    //     
     for(int i=0;i<=S.length();i++){
    	 nums[i][0]=1;
     }
		
     
     
     for(int i=1;i<=S.length();i++){
    	 for(int j=1;j<=T.length();j++){  
    		 		 nums[i][j]=nums[i-1][j]; //nums[i][j]是由nums[i - 1][j]下移动一位得来的
    		 		 //eg [2][1]=[1][1]=1 “空r”组成“空r”是一种方法(不删) “空ra”组成“ 空ra”也是一种(删a) 所以这句成立
    	  		 if(S.charAt(i-1)==T.charAt(j-1)){  //但是因为num矩阵里是从1开始的,[0][0]是空 所以 当i=4 j=3时候 S.charAt(i-1)==T.charAt(j-1)
    			 nums[i][j]=nums[i][j]+nums[i-1][j-1];//实际上是S.charAt(3)==T.charAt(2) 所以是rabbbit的第2个b等于 rabbit的第一个b 
    			 //所以的确有rab1组成rab的这种可能（从斜上角nums[i-1][j-1]num[3][2] 组成了num[4][3] 这种可能）
    			 //也有从rab2组成rab可能 （从上方nums[i-1]num[3][3] 组成了num[4][3] 这种可能） 
    			 //所以此时 nums[i][j]=nums[i][j]+nums[i-1][j-1];
    			 
    		 }
    	 }
   
     }
     //
	 for (int i = 0; i <nums.length; i++) {
	 System.out.println("");
	 for (int j = 0; j <nums[0].length; j++) {
	 System.out.print(nums[i][j]+" ");
	 }
	}
		
	return nums[S.length()][T.length()];	
	
		
    }
	
	public static void main(String[] args) {                     //source    target
		System.err.println( new DistinctSubsequence().numDistinct("rabbbit", "rabbit"));
		
	}
}
