package frequency_1;

import java.util.Stack;
import java.util.regex.Matcher;

//Given a string containing just the characters '(' and ')', 
//find the length of the longest valid (well-formed) parentheses substring.
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
public class LongestValidParentheses {
//	我用的stack,扫描string 如果当前char i 是(  就把I (下标)压入stack 然后 如果一直是(就一直压。
//	如果是）了 就 matchedLeft=stack.pop() 然后 matchedLen=i-matchedLeft+1;  
//	（这里i就是本次匹配上的右括号下标 matchleft就是本次匹配上的左括号下标）
//	然后检查如果栈空了就更新 accumulatedLen=accumulatedLen+matchedLen;    matchedLen=accumulatedLen;
//	如果没空就 matchedLen=i-stack.peek();（插当前右括号最多和左边那个左括号的下标匹配上） 
//	然后 更新maxLen=Math.max(maxLen, matchedLen)  到for循环结束 return maxLen
	 public int longestValidParentheses(String s) {
	        if(s==null||s.length()<=1){
	        	return 0;
	        }
	 Stack<Integer> stack=new Stack<Integer>();//stack里存下标
	 int maxLen =0;
	 int accumulatedLen=0;     //比方说  ")()())"
	 for(int i=0;i<s.length();i++){
		 if(s.charAt(i)=='('){ 
			 stack.push(i);  //第二char stack里push1
		 }else{
			 if(stack.isEmpty()){
				 accumulatedLen=0; //第一char accumulatedLen=0 因为)
			 }else{
				 int matchedLeft=stack.pop();  //第3char matched pop 1
				 int matchedLen=i-matchedLeft+1; //matchedLen =2-1+1=2  这里i就是本次匹配上的右括号下标 matchleft就是本次匹配上的左括号下标
		 if(stack.isEmpty()){ //此时stack为空了 
			 accumulatedLen=accumulatedLen+matchedLen; //acL=2
			 matchedLen=accumulatedLen; //matched Len=2
		 }else{
		matchedLen=i-stack.peek();
			 }
			 maxLen=Math.max(maxLen, matchedLen); //动态维护 maxLen 之前的最大长度和本次match到的最大长度比
			 }
	 }
	 } 
	 return maxLen;
	 }
	 
	 
	 
public static void main(String[] args){
	System.out.print( new LongestValidParentheses().longestValidParentheses("))((())()())"));
 
}
}