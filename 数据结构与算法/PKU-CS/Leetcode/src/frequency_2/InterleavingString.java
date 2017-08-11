package frequency_2;
//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
//For example,
//Given:
//s1 = "aabcc",
//s2 = "dbbca",
//
//When s3 = "aadbbcbcac", return true.
//When s3 = "aadbbbaccc", return false. 

 //          e      d   f  
//    true false false false 
//  a true false false false 
//  b true true true false 
//  c false false true true 



//看 s3是否能由s1 s2交错但是不错乱顺序的组成
//九章算法 预处理 2 sequence DP模板 boolean[i][j] 长是第一个string到第i个char时候是否 第2个string到j个char时候是否interleaving 。
//最后返回 boolean[s1.length()][s2.length()];
public class InterleavingString {
public boolean isInterleave(String s1, String s2, String s3) {
  //检查
	  if (s1 == null || s2 == null || s3 == null) {
          return false;
      }
      if (s1.length() + s2.length() != s3.length()) {
          return false;
      }
//初始化矩阵
      boolean[][] interleave = new boolean[s1.length() + 1][s2.length() + 1];
      interleave[0][0] = true;
     
      //初始化 矩阵左边 相当于basecase
     for(int i=1;i<=s1.length();i++){
    	 interleave[i][0]=s1.subSequence(0, i).equals(s3.subSequence(0, i));
    	 
     }
      //初始化矩阵上边 相当于basecase

for(int i=1;i<s2.length();i++){
	interleave[0][i]=s2.substring(0,i).equals(s3.subSequence(0, i));
}
     //dp部分
    for(int i=1;i<=s1.length();i++){
    	for(int j=1;j<=s2.length();j++){
    		interleave[i][j]=false;
    		
    // 所以 boolean[i][j] 是s3的第char[i+j-1] 位是否是第一个string到第i个char时候和 第2个string到j个char时候组合的interleaving 		
    		//如果当前字符相等 
    		if(s1.charAt(i-1)==s3.charAt(i+j-1)){
    			                      //就判断前面字符相不相等 如果有一个相等 再加上本位也相等 表示就可以一个相等
    			interleave[i][j]=interleave[i][j]||interleave[i-1][j];
    		    }
    	if(s2.charAt(j-1)==s3.charAt(i+j-1)){
    		interleave[i][j]=interleave[i][j]||interleave[i][j-1];
    	}
    		
    		}
    }
    for (int i = 0; i <interleave.length; i++) {
		 System.out.println("");
		 for (int j = 0; j < interleave[0].length; j++) {
		 System.out.print(interleave[i][j]+" ");
		 }
		}
	return interleave[s1.length()][s2.length()];
}

public static void main(String[] args) {
	new InterleavingString().isInterleave("abc", "edf", "abedcf");}
}
