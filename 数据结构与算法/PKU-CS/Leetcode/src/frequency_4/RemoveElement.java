package frequency_4;
//Given an array and a value, remove all instances of that value in place and return the new length.
//
//The order of elements can be changed. It doesn't matter what you leave beyond the new length. 
//删除数组内给定值的元素 然后返回删除后的长度
//聪明的做法： 两个指针都从0开始，从左向右找++，如果不等于elem 就i j都++  A[i]=A[J]
//如果等于elem就只j++ i不动.下一次再到不同的时候依旧 	A[i]=A[j];

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.LinkedList;

public class RemoveElement {

	
	 public int removeElement(int[] A, int elem) {
	   int i=0;
	   int j=0;
	while(j<A.length){
		if (A[j]!=elem) {
			A[i]=A[j];
		    i++;}
		j++;}
	return i;}
	 
	 
	public static void main(String[] args) {
		int[] A={1};
		int l=(new RemoveElement()).removeElement(A,1);
		System.out.print(l);

	}

}


//这写法不好 太累赘
//if(A.length==0){return 0;}    
//LinkedList<Integer> temp=new LinkedList<Integer>();
//    for(int i=0;i<A.length;i++){
//   	 temp.add(A[i]);
//    }
//    while(temp.contains(elem)){
//   	 temp.remove((Integer) elem);
//    }
//   Integer[] a=(Integer[]) temp.toArray(new Integer[temp.size()]); 
//   A=new int[a.length];
//   for (int i=0;i<a.length;i++) {
//   	A[i]=a[i];
//		
//	}
////System.err.print(Arrays.toString(a));
//   return a.length;