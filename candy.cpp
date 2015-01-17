/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?


*/




  class Solution {
  public:
	  int candy(vector<int> &ratings) {
		  unsigned n = ratings.size();
		  vector<int> right(n, 0), left(n, 0);
		  for(int i = 0; i != n; ++i){
			if(i == 0){
				right[i] = 0;
				left[n-1-i] = 0;
			}else{
				if(ratings[i] > ratings[i-1]){
					right[i] = right[i-1] + 1;
				}else
					right[i] = 0;
				unsigned  j = n-1-i;
				if(ratings[j] > ratings[j+1]){
					left[j] = left[j+1] + 1;
				}else
					left[j] = 0;
			}
		  }
		  unsigned sum = n;
		  for(int i = 0; i != n; ++i){
			  right[i] = right[i] > left[i] ? right[i]:left[i];
			  sum += right[i];
		  }
		  return sum;
	  }
  };