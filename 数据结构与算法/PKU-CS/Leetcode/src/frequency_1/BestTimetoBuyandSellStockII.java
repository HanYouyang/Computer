package frequency_1;
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete as many transactions 
//as you like (ie, buy one and sell one share of the stock multiple times).
//However, you may not engage in multiple 
//transactions at the same time (ie, you must sell the stock before you buy again).

//可以买卖0～无数次 要最大化利润 但是一定要先卖后买
// 贪心法（只选取当前选择的最优解-局部最优解 ,在这题里面 就是 ），本题和前面的Best Time to Buy and Sell Stock 不同在于，本题可以多次买卖股票，  
// 从而累积赚取所有的价格差。因此用贪心法，基本思想是先买进，然后在价格升到局部最高点  
// （即下一天的价钱就下降了）时候，抛出股票，然后把下一天较低的价钱作为买入，接着计算。  
// 要注意最后要处理最后一次的利润  

public class BestTimetoBuyandSellStockII {

	 public int maxProfit(int[] prices) {
	     if(prices==null||prices.length==0){
	    	 return 0;
	     }   
		int totalProfit=0;
		int startIndex=0; //第一次买进的位置是0位
		for(int i=1;i<prices.length;i++){
			if(prices[i]<prices[i-1]){ //后面1天的价格小于前面一天的价格 要跌了。
			totalProfit=totalProfit+prices[i-1]-prices[startIndex];	
			startIndex=i;//  然后再i这天又买进
			
			}
		}
		//当for循环结束后(最后还会i++一次 但是因为不符合for循环了所以进不了for块) 因为 处理最后一次利润
		if(prices[prices.length-1]>prices[startIndex]){
			totalProfit=totalProfit+prices[prices.length-1]-prices[startIndex];}
					return totalProfit;			
		
	    }

}
