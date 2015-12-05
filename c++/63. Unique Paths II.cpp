class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int hgt = obstacleGrid.size();
		int wide = obstacleGrid[0].size();
		if (obstacleGrid[0][0] ||obstacleGrid[hgt-1][wide-1]){
			return 0;
		}

		vector<int> dp_ary(wide, 0);
		dp_ary[0] = 1;

		for (int i = 0; i != hgt; ++i){
			for (int j = 0; j != wide; ++j){
				dp_ary[j] = obstacleGrid[i][j] ? 0 : (j == 0 ? 0 : dp_ary[j - 1]) + dp_ary[j];
			}
		}
		return dp_ary[wide - 1];
	}
};