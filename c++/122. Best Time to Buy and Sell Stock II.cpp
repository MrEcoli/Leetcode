 

/*

Best Time to Buy and Sell Stock II 
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


Greedy Algorithm
*/



 class Solution {
public:
	int maxProfit(vector<int> &prices) {
		unsigned n = prices.size();
		if(n == 0|| n == 1){
			return 0;
		}
		int cur_low = prices[0], cur_high = prices[0];
		int sum_profit = 0;
		bool find_low = false;
		for(int i = 1; i != n; ++i){
			if(!find_low){
				if(prices[i] <= cur_low){
					cur_low = prices[i];
				}else{
					find_low = !find_low;
					cur_high = prices[i];
					if(i == n-1){
						sum_profit += (cur_high - cur_low);
					}
				}
			}else{
				if(prices[i] >= cur_high){
					cur_high = prices[i];
					if(i == n-1){
						sum_profit += (cur_high - cur_low);
					}
				}else{
					find_low = !find_low;
					sum_profit += (cur_high - cur_low);
					cur_low = prices[i];
				}
			}
		}
		return sum_profit;
	}
};