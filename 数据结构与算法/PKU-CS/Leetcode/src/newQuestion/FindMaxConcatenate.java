package newQuestion;

import java.util.Arrays;
import java.util.Comparator;

//Given an integer array, sort the integer array such that the
//concatenated integer of the result array is max.  
//e.g. [4, 94, 9, 14, 1] will be sorted to [9,94,4,14,1] 
//		where the result integer is 9944141
public class FindMaxConcatenate {

	public static void FindMaxConcatenate(String[] todo){
	Arrays.sort(todo,new myCompetator());
		}
	
	public static void main(String[] args) {
		String[] todo={"9","94","4","14","1"};
		String[] todo2={"272","27"};
		FindMaxConcatenate(todo);
		FindMaxConcatenate(todo2);
		System.out.println(Arrays.toString(todo));
		System.out.println(Arrays.toString(todo2));
	}
}

class myCompetator implements Comparator<String>{
public int compare(String o1, String o2) {
		if(Integer.parseInt(o1+o2)>Integer.parseInt(o2+o1)){
			return -1;
		}else if(Integer.parseInt(o1+o2)<Integer.parseInt(o2+o1)){
			return 1;
		}else{
			return 0;
		}
	}
	
} 