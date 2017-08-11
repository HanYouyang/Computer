package frequency_4;

import java.util.ArrayList;

import javax.management.relation.Relation;

//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
//For example,
////If n = 4 and k = 2, a solution is: 
//[
// [2,4],
// [3,4],
// [2,3],
// [1,2],
// [1,3],
// [1,4],
//]
//就是说 从1到N 随机的排列 总元素数为K   combinations of k numbers
//上面那个例子就是从1到4 里面 挑2个的所有排列。

//这题和premutation/cc的8.4很类似  是求排列 但是不是全排列。 
public class Combinations {
	 public ArrayList<ArrayList<Integer>> combine(int n, int k) {
	    
		ArrayList<ArrayList<Integer>> result=new ArrayList<ArrayList<Integer>>();
		ArrayList<Integer> temp=new ArrayList<Integer>();
		subsetsRecord(result, temp ,n,k,0);
		return result;		 
	}
	      //这里是void 就是处理result 给result填满该有的排列
	 public void subsetsRecord(ArrayList<ArrayList<Integer>> result,ArrayList<Integer> temp,int n, int k ,int level	){
		 //temp.size==k说明这个temp里的元素都起齐了 可以加入
		 if(temp.size()==k){
			  //新建一个arraylist 包含temp的内容 加入result
			 //如果不这样 那么只有一个temp对象 那么对其的改动会在arraylist里也显现 因为不管是从arraylist还是从temp都是指向同一个对象
			 result.add(new ArrayList<Integer>(temp));
		return;	
		 }
		 
		 //level 一开始是0
		 //这段for是反复对着temp 修改, 上面那段只是把到达规定长度的arraylist复制一个到k里然后方法结束 
		 //注意这个i 因为只有一个i 所以这个i在不懂的递归所调出来的新方法里传出来的值是不同的
		 	 for(int i=level;i<n;i++){
				 temp.add(i+1);
				 subsetsRecord(result, temp, n, k, i+1);
				 System.err.print(temp);
			     temp.remove(temp.size()-1);//减去最后一个 
			 //这三句循环套递归要怎么理解 
			     // 首先要注意的是,在递归系统里，方法结束后会返回上一层
			     //而在这个subsetsResut这个方法里 有2种情况会结束方法,1.temp.size=k 2.for循环时候i=n for循环结束 方法跑完结束.
			     //就比方说 n = 4 and k = 2,的例子吧，因为k等于2 所以temp要递归3层 
			     //一开始外层循环里temp里是1 然后递归后是2 然后把1，2 add进result,方法返回上一层 这时候 remove调temp.size()-1 (就是最后一位)把2删掉就还剩下1
			     //但是这时候i已经增加了 i+3就是3了然后在递归2层再add 3的就是 1.3 再进答案。。同理 1,4 然后1,4后remove成1 但是此时 i<n已经不成立了 方法结束 
			     //再递归返回上一层 然后remove最后一位 就把1也删掉了 此时最上面那那层的for循环1已经好了 然后开始循环2 然后依次类推
			    	 	 
			     //[1, 2][1, 3][1, 4][1][2, 3][2, 4][2][3, 4][3][4]
		 	 }
	 }
	 
	 
	 public static void main(String[] args) {
		new Combinations().combine(4, 2);
	}
	 
}
