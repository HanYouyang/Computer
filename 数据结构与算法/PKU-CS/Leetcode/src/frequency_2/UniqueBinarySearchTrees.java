package frequency_2;

import javax.xml.stream.events.StartDocument;
//Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//For example,
//Given n = 3, there are a total of 5 unique BST's.
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3

//1~n  要全部储存在bst里 有几种肯能的树？
//用dfs的思想  当root为1时候 root为2时候 root为3时候循环 一直到n 这就是for
//然后当root为1时候 左边不能放 右边放2~n   root为2时候  左边放1 右边放3～n
//总之 当 root为 i时候 左边放1～i-1  右边放1+1～n　所以这里就是dfs
//循环就是1～你

public class UniqueBinarySearchTrees {
	 public int numTrees(int n) { 
		 return numTrees(1,n);
		 }
	 int numTrees(int start,int end){
		 if(start>=end){
			 return 1;  //只有一种可能  终结条件 
		 }
		 int totalNum=0;
		 for(int i=start;i<=end;i++){
			 //为什么是乘法呢？ 假设左子树有n种可能 右子树有N中可能 而root是i只有1种可能
			 //那么 总可能就是 左×右×1
			 totalNum=totalNum+numTrees(start,i-1)*numTrees(i+1,end);
			 
			 
		 }
		return totalNum;
		 
	 }
}
