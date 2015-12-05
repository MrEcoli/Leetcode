
/*


Triangle 
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/



 
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		unsigned n = triangle.size();
		if(n == 0)
			return 0;
		for(unsigned i = 1; i != n ; ++i){
			unsigned m = i+1;
			for(int j = 0; j != m; ++j){
				if(j == 0)
					triangle[i][j] += triangle[i-1][0];
				else if(j == m-1)
					triangle[i][j] += triangle[i-1][i-1];
				else{
					int min_val = triangle[i-1][j] < triangle[i-1][j-1]?triangle[i-1][j] : triangle[i-1][j-1];
					triangle[i][j] += min_val;	
				}
			}
		}
		int min_path = INT_MAX;
		for(int i = 0; i != n; ++i){
			if(triangle[n-1][i] < min_path)
				min_path = triangle[n-1][i];
		}
		return min_path;
	}
};

