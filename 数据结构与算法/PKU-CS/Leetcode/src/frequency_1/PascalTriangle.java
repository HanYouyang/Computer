package frequency_1;

import java.util.ArrayList;
//Given numRows, generate the first numRows of Pascal's triangle.
//
//For example, given numRows = 5,
//Return
//
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//]
//杨辉三角形第n层（顶层称第0层，第1行，第n层即第n+1行，此处n为包含0在内的自然数）
//正好对应于二项式\left(a+b\right)^{n}展开的系数。
//例如第二层1 2 1是幂指数为2的二项式(a+b)^2展开形式a^2+2ab+b^2的系数。

//dp思想,base case是 每个行第一列都是1 最后一列都是1
//但是 如果不是编程就 平时想事情角度来考虑问题的话，当中的那些值
//就是 左上加右上， 那么就这么加就好了 到res.get(i-1).get(j)左上+res.get(i-1).get(j+1)右上
//* [
//* [1],
//* [1,1],
//* [1,2,1],
//* [1,3,3,1],
//* [1,4,6,4,1]
//* ]
//*    matrix

public class PascalTriangle {

public ArrayList<ArrayList<Integer>> generate(int numRows) {
     ArrayList<ArrayList<Integer>> result=new ArrayList<ArrayList<Integer>>();
     for(int i=0;i<numRows;i++){
    	 ArrayList<Integer> currentLevel=new ArrayList<Integer>();
    	 currentLevel.add(1);
    	 if(i>0){//第一层时候i=0 只用+1就行 不用进if块  
    		 //根据上一层的宽度来循环 本来上层是比本层少1的 但是再-1 因为每层的两边都已经定下来是1了
    		 for(int j=0;j<result.get(i-1).size()-1;j++){
    			 currentLevel.add(result.get(i-1).get(j)+result.get(i-1).get(j+1));
    		 }
    		 currentLevel.add(1);
    	 }
     result.add(currentLevel);
     }
     return result;
    }

}
