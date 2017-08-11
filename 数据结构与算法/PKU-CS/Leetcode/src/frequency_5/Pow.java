package frequency_5;
//	2的3次方 pow(2,3)
//注意n可以为负 eg:10^-2 是1/100

//直接上O(lgn)做法  recursive 吧乘积/2分散开来 
public class Pow {

	public double pow(double x, int n) {
		if(n<0){
	//这么写是可以的 只要最后倒数一次即可 毕竟2^-10 =1/2^10		
			return 1.0/pow2(x,-n);
		}else{
			return pow2(x,n);
		}
		
	}
	
	public  double  pow2(double x,int n) {
		if(n==0){
			return 1;
		}
		
	//二分法思想处理该问题	
	//利用指数运算规则 比如 2^3*2^5=2^8
    //同理 2^8=2^4*2^4;就1分2了 然后再2分4 这样就是不用1个1个乘8次 lgn复杂度即可
	double result=pow2(x, n/2);
	//因为n是int 所以除2会去尾巴 比方2^9--9/2=4 所以要在乘一次x--2*2^4*2^4=2^9
		if(n%2==1){return x*result*result;
		}else{return result*result;}//else 就是偶数 就直接 /2即可 最后再x2
	}
	public static void main(String[] args) {
		System.out.println((new Pow()).pow(2, -5));

	}

}

//第二遍做法 
class Solution {
    public double pow(double x, int n) {
       if(n<0){
           return 1.0/pow2(x,-n);
       }else{
           return pow2(x,n);
       }
    }
    
    private double pow2(double x,int n){
        if(n==0){
            return 1;
        }
       double result;
        if(n%2==1){
        result=x* pow2(x*x,n/2);
        }else{
            result=pow2(x*x,n/2);
        }
    return result;}
}
 