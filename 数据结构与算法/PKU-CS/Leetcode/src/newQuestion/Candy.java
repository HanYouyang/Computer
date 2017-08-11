package newQuestion;

import java.util.Arrays;
//There are N children standing in a line. Each child is assigned a rating value.
//
//You are giving candies to these children subjected to the following requirements:
//
//   Each child must have at least one candy.
//   Children with a higher rating get more candies than their neighbors.
//
//What is the minimum candies you must give? 
//那么比方说  345 5的小孩拿3个糖 4的小孩拿2个糖  1的小孩拿1个糖 
//有一点要注意，同样rating挨着的两个小孩的糖可以不一样的
//比如说rating是35553 糖是12121  rating 是34555 糖是 12311

public class Candy {
	//
//先把答案数组先全部填充成1.然后就是两头扫瞄，第一次从左到右，第二次从右到左，
//这样递增和递减的关系就刚好相反。每一个递增都加一，递减就不变。 
// 比方说 rating是 3455542 左到右第一次扫描后 1231111
//第二次扫描时候 因为 ratings[i-1]>ratings[i]&&count[i-1]<=count[i]
//所以         1231221
	 public int candy(int[] ratings) {
	   if(ratings==null||ratings.length==0){
		   return 0;
	   }    
	   int[] count =new int[ratings.length];
	   Arrays.fill(count, 1);
	   int sum =0;
	   for(int i=1;i<ratings.length;i++){
		   //正着扫一遍 只要比i-1多 count[i]-count[i-1]+1; 
		   if(ratings[i]>ratings[i-1]){
			   count[i]=count[i-1]+1;
		   }
	   }
	   //再反着扫一遍 同时计算sum
	   for(int i = ratings.length-1;i>=1;i--){
		   sum=sum+count[i];
		    //i-1 大  i小  并且     count里面i=1小于等于count [i] count是结果
		   if(ratings[i-1]>ratings[i]&&count[i-1]<=count[i]){
			   count[i-1]=count[i]+1;
		   }
	   }
	    sum=sum+count[0];
	   return sum;
	     }
}
