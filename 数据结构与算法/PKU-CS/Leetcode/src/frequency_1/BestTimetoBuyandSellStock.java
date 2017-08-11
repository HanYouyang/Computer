package frequency_1;

//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//只买卖1次  或者0次 求最大利润
//找到最大增长即可。(不一定要连续的)
//从前往后，用当前价格减去此前最低价格，就是在当前点卖出股票能获得的最高利润。
//扫描的过程中更新最大利润和最低价格就行了。
public class BestTimetoBuyandSellStock {
	public int maxProfit(int[] prices) {
		if (prices == null || prices.length == 0) {
			return 0;
		}
		int minPrice = Integer.MAX_VALUE;
		int maxProfits = Integer.MIN_VALUE;

		for (int i = 0; i < prices.length; i++) {
			if (prices[i] < minPrice) {
				minPrice = prices[i];
			}
		int currentProfit=prices[i]-minPrice;
		if(currentProfit>maxProfits){
			maxProfits=currentProfit;
		}
			
		}
	return maxProfits;
	}
}
