package frequency_1;
//Write a function to find the longest common prefix string amongst an array of strings. 
//找一个string数组里面最长的公共前缀。
public class LongestCommonPrefix {
	// 1. Method 1, start from the first one, compare prefix with next string, until end;
    // 把第一个String 当作前缀 然后每次都和后面的string比 然后找出共同prefix作为新的prefix
	//然后更新的prefix,再和下一个比
	public String longestCommonPrefix(String[] strs) {
     if(strs==null||strs.length==0){
    	 return "";
     }
	String prefix=strs[0];
	for(int i=1;i<strs.length;i++){ //遍历字符串 
		int j=0;
		//当当前的for循环第i个string的j位 和prfix的第j位一样的时候 j++  看看prefix能坚持match到底几位
		while(j<strs[i].length()&&j<prefix.length()&&strs[i].charAt(j)==prefix.charAt(j)){
			j++;
		}
	if(j==0){
		return "";
		} 
	
		prefix =prefix.substring(0,j);
	}
	return prefix;	
		
	}
	
    }

