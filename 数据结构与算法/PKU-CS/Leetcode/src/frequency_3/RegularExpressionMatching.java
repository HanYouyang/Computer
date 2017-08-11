package frequency_3;
//Implement regular expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//
//The matching should cover the entire input string (not partial).
//
//The function prototype should be:       
//bool isMatch(const char *s, const char *p)
//
//Some examples:
//isMatch("aa","a") → false
//isMatch("aa","aa") → true
//isMatch("aaa","aa") → false
//isMatch("aa", "a*") → true
//isMatch("aa", ".*") → true
//isMatch("ab", ".*") → true
//isMatch("aab", "c*a*b") → true

// 题意一定要理解清楚,x*是一个在一起的bundle，a* 的意思 是 “a*” 整个 可以代表0~n个 a
// 比方说 //isMatch("aab", "c*a*b") →  c*可以代表 0个c a*代表 2个a 所以 aab 就完全匹配上了
//后面那个string只要包含前面那个就可以
//要p (pattern)完整包含 s 不能分两段包含
public class RegularExpressionMatching {

	 public boolean isMatch(String s, String p) {
	    return isM(s, p,0,0);
		 }
	                                       //i j 表示 目前检查到s的i位和p的j位
	 private boolean isM(String s,String p,int i,int j){
		 if(j>=p.length()){  //j>p.length() p已经走完
			 return i>=s.length(); //如果s还没走完 那肯定false
			 }
		 if(j==p.length()-1){ //当p检查到最后一个char时候
			       //s也要是最后一个char且能匹配上p
			 return (i==s.length()-1)&&(s.charAt(i)==p.charAt(j)||p.charAt(j)=='.');
		 }
		 //如果pattern下一个字符j+1不是*
		 if (j+1<p.length()&&p.charAt(j+1)!='*') {
			if(i==s.length()){  //如果是已经走完,则说明不匹配。
				return false;
			}
		if(s.charAt(i)==p.charAt(j)||p.charAt(j)=='.'){  //这一格匹配上了
			return isM(s, p, i+1, j+1);  //继续下一个字符判断
		}else{ //当前s和 不匹配 
			return false;
		}
	 }
	//上面的if(&p.charAt(j+1)!='*') 已经把p 里面j+1是*的时候给滤掉了  
    // 此时 pattern的下一个字符j+1是*
  while(i<s.length()&&j<p.length()&&(s.charAt(i)==p.charAt(j)||p.charAt(j)=='.')){
	  //因为 此时j匹配上了 j+1是* 所以 直接i位和 j+2 位后面的比 
	  //然后 while直接i+1位和 j+2 位后面的比 i+2   i+3.... 有 一个match上就return true
	  //为什么不是直接上i+1位而是i位呢？
	  //比方说 aabc 去match a*aabc 那么当 aa和a* match上的时候  如果直接让abc去match aabc 是不能完全匹配的 所以要留每一种可能性
	  //所以要探测每一种可能性 从i开始 而不是i+1
	  if(isM(s, p, i, j+2)){
		return true;
	  }
	  i++;
  }
  // 如果下一个字符(j+1)是* 且 当前字符不匹配，就不进while块 则pattern跳过两个（就好比 c*a*b 跳过c*），继续比较 后面  
  // 还有一种情况到这里是上面的最后一次尝试（i==s.length()）  
  return isM(s, p, i, j+2);
			
  }
	 }
		 
 
	    	
	
	
//	public static void main(String[] args) {
//		  System.out.println(isMatch("aa", "a*"));        // true  
//	        System.out.println(isMatch("aa", "a"));     // false  
//	        System.out.println(isMatch("aa", "aa"));    // true  
//	        System.out.println(isMatch("aaa", "aa"));   // false  
//	        System.out.println(isMatch("aa", "a*"));    //true  
//	        System.out.println(isMatch("aa", ".*"));    // true  
//	        System.out.println(isMatch("ab", ".*"));    // true  
//	        System.out.println(isMatch("aab", "c*a*b"));        // true  
//	          
//	        System.out.println(isMatch("", "bab"));         // false  
//	        System.out.println(isMatch("ab", ".*c"));       // false  
//	        System.out.println(isMatch("aaa", "a.a"));      // true  
//	        System.out.println(isMatch("a", "."));          // true  
//	        System.out.println(isMatch("a", "ab*"));        // true  
//	        System.out.println(isMatch("bb", ".bab"));      // false  
//	        System.out.println(isMatch("bb", "*"));         // false           

	



//
//
//public boolean isMatch(String s, String p) {
//    if(p==null){return false;}  
//    //递归的结束条件  当p已经都substring完了 s有没有完
//	 if(p.length()==0){
//   	   return s.length()==0;
//      }
//	 //如果pattern已经走到最后一个字符，或者p第二个字母不是*(因为*可以匹配0字符)，
//	 //如果想匹配，则s的i也必须在最后一个，且相等  
//	 if(p.length()==1||p.charAt(1)!='*'){
//		  if(s.length()<1||(p.charAt(0)!='.'&&p.charAt(0)!=s.charAt(0))){
//			  return false;
//		  } 
//		  //因为已经确定下一位不是'*'了 所以substring后的p第一位也不会是*
//		  return isMatch(s.substring(1), p.substring(1));
//	 }else{
//		 int i=-1;
//		 while(i<s.length()&&(i<0||p.charAt(0)=='.'||p.charAt(0)==s.charAt(i))){
//			 if(isMatch(s.substring(i+1), p.substring(2))){
//				 return true;}
//				 i++;
//			 }
//		 return false;
//		 }
//	 }
//
