/*

Pascal's Triangle
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/


class Solution {
public:
	vector<vector<int> > generate(int numRows) {
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
		return res;
	}
};
