package frequency_5;
import java.util.HashSet;
import java.util.LinkedList;

//    Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
//
//    Only one letter can be changed at a time
//    Each intermediate word must exist in the dictionary
//    For example,
//
//    Given:
//    start = “hit”
//    end = “cog”
//    dict = ["hot","dot","dog","lot","log","cog"]
//    As one shortest transformation is “hit” -> “hot” -> “dot” -> “dog” -> “cog”,
//    return its length 5.
//
//    Note:
//    Return 0 if there is no such transformation sequence.
//    All words have the same length.
//    All words contain only lowercase alphabetic characters.
//因为要找最短长度，所以相同的词最多出现一次 否则不是最短长度了


public class WordLadder {

	 public int ladderLength(String start, String end, HashSet<String> dict) {
	  if(dict.size()==0){
		  return 0;
	  }
		 int result=0;
		 //wordQ储存 从start开始 当中的变体 然后 最后到end
		 LinkedList<String> wordQueue=new LinkedList<String>();
		 //
		 LinkedList<Integer> distanceQueue=new LinkedList<Integer>();
		
		 wordQueue.add(start);
		
		 distanceQueue.add(1);
		 
		 while(!wordQueue.isEmpty()){
			 String currWord=wordQueue.poll();
			 Integer currDistance=distanceQueue.poll();
			 if(currWord.equals(end)){
	                return currDistance;
	            }
			 
			 for(int i=0;i<currWord.length();i++){
				 char[] currCharArr=currWord.toCharArray();
			//当前词每个字符 单独变位一下 从a遍历到z 如果找到有词库一样的
			//	 就把这个词库里的词放到Queue里
			//这样queue里面就有当前词变位一个字母后所有在字典里的词
		  //然后每个词再去找变位一个字母有后所有在字典里的词
				 //最后找到end时候返回 currDistace  找不到返回0
				 for(char temp='a';temp<='z';temp++){
					 currCharArr[i]=temp;
					 String newWord=new String(currCharArr);
					 if(dict.contains(newWord)){
						 wordQueue.add(newWord);
						 //把这个currDistance+1 放在for循环里保证了
						 //改动一个字母只加以 假设start变了字母后得到3个词典里的新词
						 //那么就有3个0+1 更能真实的反应距离。
						 distanceQueue.add(currDistance+1);
						 dict.remove(newWord);
					 }
				 }
			 }
		 	 
		 }
		return 0;
		 
	    }
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
