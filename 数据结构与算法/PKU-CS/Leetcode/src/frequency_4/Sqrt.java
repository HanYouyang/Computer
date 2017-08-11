package frequency_4;
//求x的平方根
//两分法。原因就是：要求x的平方根，在假定x为正整数的情况下，那么它的结果一定在0到x之间，而二分查找法一定不会漏掉。
public class Sqrt {
	   public int sqrt(int x) {
	     if(x<0){return -1;}
	     if(x==0){return 0;}
		long low=0;
		long high=x;
		long mid;
		while(low<=high){
			mid=(low+high)/2;
			if(mid*mid==x){return (int)mid;
			}else if(mid*mid<x) {low=mid+1;
			}else{ high =mid-1;}
			}
		//因为 low high mid都是整数 所以当最后low high 相差很小的时候还乘不上的话
		//就逼近的返回他们的平均值
		  mid=(low+high)/2;
		  return (int)mid;
		   
		   
	    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
