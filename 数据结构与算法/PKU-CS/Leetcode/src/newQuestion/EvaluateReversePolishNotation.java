

package newQuestion;

import java.util.Stack;

//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
//Some examples:
//
// ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
// ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
//题意就是让你碰到数字就压到stack里 然后
//碰到符号 就弹出stack最上面的2个数字 然后运算 然后再把结果压回去
//一直到数组用完为止  符号只用计算不用压入栈

//ps 你可以和面试官讨论 要不要考虑 碰到符号了 但是stack.size()<2 怎么办
//pps这题不会给你这种test case
public class EvaluateReversePolishNotation {
public int evalRPN(String[] tokens) {
        if(tokens==null||tokens.length==0){
        	return 0;
        }
        Stack<Integer> stack =new Stack<Integer>();
      
        for(int i=0;i<tokens.length;i++){
        	if(tokens[i].equals("+")){
        		int a=stack.pop();
        		int b=stack.pop();
        		stack.push(a+b);
        	}else if(tokens[i].equals("-")){
        		//注意是前面的数-后面的数 栈第一次pop出来的后面的数
        		int a=stack.pop();
        		int b=stack.pop();
        		stack.push(b-a);
        	}else if(tokens[i].equals("*")){
        	  stack.push(stack.pop()*stack.pop());
        	}else if(tokens[i].equals("/")){
        		int a=stack.pop();
        		int b=stack.pop();
        		stack.push(b/a);
        	}else{
        		stack.push(Integer.parseInt(tokens[i]));
        	}
        }
        //进行最后一次计算后 stack应该只有最终结果一个int
        return stack.pop();
    }
}
