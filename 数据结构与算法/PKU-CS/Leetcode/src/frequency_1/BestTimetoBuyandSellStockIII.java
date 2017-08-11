package frequency_1;
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete at most two transactions.
//
//Note:
//You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//可买0～2次
//建2个数组 forward[i]是[0,i]区间的最大利润(和第一题一样更新min price 然后看 prices[i]-min price 赚多少)
//backword[i]是[i,n]区间最大利润(从n--下来 更新max price 最高卖价 然后看 max price- prices[i]赚多少)
//for(int i=0;i<prices.length;i++){ //max=Math.max(max,forward[i]+backward[i]);}
// //这样不管i在那里 都是 0~i 交易一次 i~n 交易一次 不会重复。
public class BestTimetoBuyandSellStockIII {
public int maxProfit(int[] prices) {
    if(prices.length==0||prices==null){
    	return 0;
    }    
    int max=0;
    //dp数组保存左边和右边的最大值
    int[] forward=new int[prices.length]; //计算 forward[i]是[0,i]区间的最大利润
    int[] backward=new int[prices.length];//计算 backward[i] 是[i]到n的区间的最大利润
    findLocalMaxP(prices,forward,backward);
    for(int i=0;i<prices.length;i++){  //这样不管i在那里 都是 0~i 交易一次 i~n 交易一次 不会重复。
      max=Math.max(max,forward[i]+backward[i]);}
      return max;
}


private void findLocalMaxP(int[] prices,int[] forward,int[] backward){
	 forward[0]=0;
	int min =prices[0];  //最小买入价
	//左边找记录 最大利润
	for(int i=1;i<forward.length;i++){
		                        //前一次利润大还是现在利润大
		
	forward[i] = Math.max(forward[i-1], prices[i]-min);   
		// i的最大利润为（i-1的利润）和（当前卖出价和之前买入价之差）的较大那个}
		min=Math.min(min, prices[i]); //更新最小买入价
	}
	backward[backward.length-1]=0;
	int max=prices[backward.length-1]; //最高卖出价
	for(int i=backward.length-2;i>=0;i--){
	                     	//前一次利润大还是现在利润大
	backward[i]=Math.max(backward[i+1],max-prices[i] );
	max=Math.max(max,prices[i]);
	}
	}

}
