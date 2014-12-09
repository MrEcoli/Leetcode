
/*

Pascal's Triangle II Total Accepted: 21429 Total Submissions: 71146 My Submissions Question Solution 
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?


Implement with two vector

*/


class Solution {
public:
	vector<int> getRow(int numRows) {
		numRows++;
		vector<vector<int>> res(numRows);
		for(int i = 0; i != numRows; ++i){
			res[i] = vector<int>(i+1);
			for(auto j = 0; j <= i; ++j){
				if(j==0 || j == i)
					res[i][j] = 1;
				else
					res[i][j] = res[i-1][j] + res[i-1][j-1];

			}
		}
		return res[numRows-1];
	}
};