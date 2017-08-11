package newQuestion;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class WordBreakII {
	 public static ArrayList<String> wordBreak(String s, Set<String> dict) {
	        ArrayList<String> result=new ArrayList<String>();
	        if(s==null||s.length()==0||dict==null||dict.size()==0){
	            return result;
	        }
	        //   boolean flag=false;
	        //   for(String word:dict){
	        //       if(s.endsWith(word)){
	        //           flag=true;
	        //           break;
	        //       }
	        //   }
	        //  if(!flag){
	        //      return result;
	        //  } 
	        int position=0;
	        StringBuilder sb=new StringBuilder();
	        dfsHelper(s,dict,position,sb, result);
	         return result;    
	     }
	     
	     private static void dfsHelper( String s, Set<String> dict,int position,StringBuilder sb,ArrayList<String> result){
	         if(position==s.length()){
	             result.add(sb.toString().trim());
	         }
	         
	         for(int i=position;i<s.length()+1;i++){
	             if(dict.contains(s.substring(position,i))){
	               StringBuilder sbNew=new StringBuilder(sb.toString());
	                sbNew.append(s.substring(position,i)).append(" ");
	                  dfsHelper(s,dict,i,sbNew, result);
	             }
	             
	         }
	    
	         
	     }
	     public static void main(String[] args) {
			HashSet a=new HashSet();
			a.add("a");
//			a.add("cats");
//			a.add("cat");
//			a.add("and");
//			a.add("sand");
//			a.add("dog");
			
			ArrayList bArrayList=wordBreak("a",a);
			System.out.print(bArrayList.toString());
			
		}
}
