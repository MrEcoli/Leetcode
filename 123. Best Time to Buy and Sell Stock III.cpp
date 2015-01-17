/*

Best Time to Buy and Sell Stock III 
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Show Tags


*/


class Solution {
public:
	int maxProfit(vector<int> &prices) {
		unsigned n = prices.size();
		if(n == 0|| n == 1)
			return 0;
		int max_profit = 0;
		// a[i]表示0~i区间内的最大profit, b[i]表示i~n-1区间的最大收益
		vector<int> a(n, 0), b(n, 0);
		int cur_low = prices[0], cur_high = prices[0], max_p = 0;
		for(int i = 1; i != n; ++i){
			if(prices[i] < cur_low){
				cur_low = prices[i];
				cur_high = prices[i];
				a[i] = a[i-1];
			}else if(prices[i] > cur_high){
				cur_high = prices[i];
				a[i] = (cur_high - cur_low)> a[i-1] ? (cur_high - cur_low) : a[i-1];
			}else{
				a[i] = a[i-1];
			}
		}
		cur_low = cur_high = prices[n-1];
		for(int j = n-2;  j >=0; --j){
			if(prices[j] > cur_high){
				cur_high = prices[j];
				cur_low = prices[j];
				b[j] = b[j+1];
			}else if(prices[j] < cur_low){
				cur_low = prices[j];
				b[j] = (cur_high - cur_low) > b[j+1] ?(cur_high - cur_low) : b[j+1];
			}else{
				b[j] = b[j+1];
			}
		}
		max_profit = a[0];
		int sum;
		for(int i = 0; i != n; ++i){
			if(i == n-1)
				sum = a[i];
			else
				sum = a[i] + b[i+1];
			max_profit = sum>max_profit ?sum : max_profit;
		}
		return max_profit;
	}

};