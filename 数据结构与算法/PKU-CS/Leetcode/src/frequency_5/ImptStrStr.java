package frequency_5;
import java.util.Arrays;

//Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack. 
//在干草堆haystack里找一个针
//什么意思呢 就是 在haystack这个string里看是否包含needle这个string
//比方说 abcde  里找 bc  如果找到就返回 bcde 没有就是null
//这题和后缀树是不一样的 因为不一定是后缀 可能是当中一段。
//字符串部分匹配的问题
public class ImptStrStr {

	 public String strStr(String haystack, String needle) {
//	        if(needle.equals("")||needle==null||haystack.equals(null)||haystack==null||needle.length()>haystack.length()){
//	        	return null;}  为什么这里不要 因为 ""里面要找得到 ""
	        char[] result=new char[haystack.length()];
	        char[] n=needle.toCharArray();
	        int h_len = haystack.length();
			int n_len = needle.length();  
			   //只要遍历haystack-needle的长度即可(比方说 haystack是长度14 needle 长度5,则要遍历14-5+1=10次 因为遍历完
			 //hay[9]还没有找到的话，此时距离haystack[13]只有4个元素了 而needle长度为5 所以怎么也匹配不上了 )
			for (int i = 0; i < h_len - n_len + 1; i++) {
				int j;
				for (j = 0; j < n_len; j++) {
					//这个if请注意 因为是从haystack的i位和needle的0位开始比
					//所以 j=0..j++ 然后 把haystack.charAt(i + j)和needle.charAt(j)比 //这样两边都能正常往后
					//直到要么不一样 就 跳出转战下一个i 
					if (haystack.charAt(i + j)!=needle.charAt(j)) {
						break;
					}
				}//要么就j=n_len说明比完了都对 就从i位后截haystack
				if (j == n_len) {  //请注意 当每一次j循环都匹配上的时候 是在一次i循环里发生的
					return haystack.substring(i);
				}
			}
			return null;

	    }
	
	
	public static void main(String[] args) {
         System.out.print(((new ImptStrStr()).strStr("abcdefg", "abcdefg")));
	}

}
