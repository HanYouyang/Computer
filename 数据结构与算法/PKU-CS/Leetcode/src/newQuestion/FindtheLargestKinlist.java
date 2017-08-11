package newQuestion;

import java.util.ArrayList;
import java.util.Map;
import java.util.PriorityQueue;

public class FindtheLargestKinlist {

	public static int findKLargest(int k,ArrayList<Integer> list){
		if(k<1||list==null||list.size()<1){
			return -1;
		}
		PriorityQueue<Integer> heap=new PriorityQueue<Integer>(k);
		int i=0;
		for (i= 0; i < k; i++) {
			heap.add(list.get(i));
		}
		
		while(i<list.size()){
			if(list.get(i)<=heap.peek()){
				}else{
			heap.poll();
			heap.add(list.get(i));
			}
		i++;
		
	}
		return heap.peek();}
	
	public static void main(String[] args) {

		ArrayList<Integer> list= new ArrayList<Integer>();
		list.add(2);
		list.add(26);
		list.add(17);
		list.add(7);
		list.add(3);
		list.add(2);
		list.add(11);
		list.add(2);
		list.add(1);
		list.add(1);
		list.add(9);
		list.add(8);
		list.add(7);
		System.out.print(findKLargest(1, list));
		
		
}
}
