class Solution {
public:
	int minPathSum(vector<vector<int> > &grid){
		int hgt = grid.size();
		int wide = grid[0].size();

		for (int i = 0; i != hgt; ++i){
			for (int j = 0; j != wide; ++j){
				if (!i && !j){
					continue;
				}
				grid[i][j] += min(i == 0 ? INT_MAX : grid[i - 1][j], j == 0 ? INT_MAX : grid[i][j - 1]);
			}
		}

		return grid[hgt - 1][wide - 1];
	}
};