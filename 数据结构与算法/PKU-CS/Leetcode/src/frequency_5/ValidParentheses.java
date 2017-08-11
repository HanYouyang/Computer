package frequency_5;
import java.util.Stack;

                  //括弧
public class ValidParentheses {
//	Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//	The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//和CC上的不太一样
	
//这种验证Parentheses  问题的关键是什么 是左边括号和右边括号的合法匹配
//比方说 {[()[{(())}]]}这个是可以的 因为他都互相匹配上了，你可以用一个stack来实现validation 因为stack先进先出,是符合valid
	//的括号们的逻辑的。

	 public boolean isValid(String s) {
		 char first=s.charAt(0);
	     if(s==null||s.equals("")||(s.length()%2)!=0||first=='}'||first==')'||first==']'){
	    	 return false;
	     }	
	     		 Stack<Character> stack=new Stack<Character>();
	     for(int i=0;i<s.length();i++){
	    	 Character current=s.charAt(i);
	    	 if(current=='{'||current=='['||current=='('){
	    		 stack.add(current);
	    	 }
	    	 if(current=='}'||current==']'||current==')'){
	    		 if(stack.size()==0){return false;}
	    		 Character lastLeft=stack.pop();
	    		                  //怎么能equals呢 难道左括号能等于又括号么 
	    		 //这是错的if(!lastLeft.equals(current)){return false;}
	    		 if(current=='}'){
	    			 if(lastLeft!='{'){return false;}
	    		 }
	    		 if(current==']'){
	    			 if(lastLeft!='['){return false;}
	    		 }
	    		 if(current==')'){
	    			 if(lastLeft!='('){return false;}
	    		 }
	    	 }
	    	 
	     }
	     //这时候for循环走完 如果true应该都22匹配 stack用光
	     if(stack.size()!=0){return false;}
		return true;
	     

	 }	
	
	public static void main(String[] args) {
		String strin="((";
		System.out.print((new ValidParentheses()).isValid(strin));
				
	}

}
