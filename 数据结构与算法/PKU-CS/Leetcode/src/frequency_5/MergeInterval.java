package frequency_5;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

//Given a collection of intervals, merge all overlapping intervals.
//
//For example,
//Given [1,3],[2,6],[8,10],[15,18],
//return [1,6],[8,10],[15,18].   
//其实只有 第一和第二个数组融合了

//题目给你的interval都是start小 end大

//merge 间隔
public class MergeInterval {

	public ArrayList<Interval> merge(ArrayList<Interval> intervals) {
		 ArrayList<Interval> result=new ArrayList<Interval>();
	        if(intervals==null||intervals.size()<=1){
	            return intervals;
	        }
	        
	        Collections.sort(intervals,new IntervalComparator());
	        //排序好 后
	        //弄一个 prev=0位 然后 和从1遍历的curr比 
	        //如果curr.start>=prev.end 说明有 interval
	        //那时候只要在比较prev.end和curr.end 那个end 大就更新prev.edm
	        //如果 curr.start<prev.end  说明没有interval
	        //直接   result.add(prev); prev=curr;
	        //循环结束后再加一次即可
	        
	       Interval prev=intervals.get(0);
	        for(int i=1;i<intervals.size();i++){
	            
	            Interval curr=intervals.get(i);
	           if(curr.start<=prev.end){
	               if(prev.end<curr.end){
	               prev.end=curr.end;
	               } 
	           }else{
	               result.add(prev);
	               prev=curr;
	           }
	       }
	        result.add(prev);
	          return result;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

// Definition for an interval.
class Interval {
	int start;
	int end;

	Interval() {
		start = 0;
		end = 0;
	}

	Interval(int s, int e) {
		start = s;
		end = e;
	}

}

// leetcode 不认类的comparator
class IntervalComparator implements Comparator<Interval> {

	public int compare(Interval o1, Interval o2) {
		if (o1.start < o2.start) {
			return -1;
		}
		if (o1.start > o2.start) {
			return 1;
		}
		return 0;
	}

}
