package frequency_4;

import java.util.ArrayList;

//和CC8-5完全一样  就是cc要求打印 这题要求输出ArrayList
//首先 先不谈代码 这道题目的基本逻辑是什么？
	// 当然是“（” 和 “）” 的数量相等，如果“（”多，只能打印“）”，反之亦然
//左：只要还有还没用完参数规定的数量 就可以插入
	// 右：有左才能有右，假设已经有了n个左，那么右的数量不能超过n

public class GenerateParentheses {

	 public ArrayList<String> generateParenthesis(int n) {
		 char[] str = new char[n * 2];
		 ArrayList<String> result=new ArrayList<String>();
		 return printpar(n, n, str, 0,result); 
	    }
	
	                                              //还剩多少个l r没用             //count是已经用了多少个括号
		private static ArrayList<String> printpar(int l, int r, char[] str, int count,ArrayList<String> result) {
			
			if(l<0||r<0){return null;}
			
			if(l==0&&r==0){result.add(new String(str));
			}else{//还有剩下的l没用 可以用
				if(l>0){
					str[count]='(';
					printpar(l-1, r, str, count+1,result);
				//剩下的r比l多 可以用l
				}if(r>l){
					str[count]=')';
					printpar(l, r-1, str, count+1,result);
				}
			}
		return result;	
		}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
