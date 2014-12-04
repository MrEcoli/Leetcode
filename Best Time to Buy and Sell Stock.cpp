/*

Best Time to Buy and Sell Stock Total Accepted: 28040 Total Submissions: 89855 My Submissions Question Solution 
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

*/

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		unsigned n = prices.size();
		if(n == 1|| n == 0)
			return 0;

		// a[i]表示i之前的最小的数;
		int max_profit = INT_MIN;
		vector<int> a(n,prices[0]);
		for(int i = 1; i != n; ++i){
			a[i] = prices[i-1] < a[i-1] ? prices[i-1] : a[i-1];
		}

		for(int i = 1; i != n; ++i){
			int profit= prices[i]- a[i];
			max_profit = max_profit > profit ? max_profit : profit;
		}
		return max_profit > 0 ? max_profit : 0;
	}
};
