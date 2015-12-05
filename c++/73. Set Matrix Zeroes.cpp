class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int x, y;
		int n = matrix.size(), m = matrix[0].size();
		bool find = false;

		for (int i = 0; i != n && !find; ++i){
			for (int j = 0; j != m && !find; ++j){
				if (!matrix[i][j]){
					find = true;
					x = i;
					y = j;
					break;
				}
			}
		}


		if (!find)
			return;

		for (int i = x; i != n; ++i){
			for (int j = 0; j != m; ++j)
			if (!matrix[i][j]){
				matrix[i][y] = 0;
				matrix[x][j] = 0;
			}
		}

		for (int i = 0; i != m; ++i){
			if (!matrix[x][i] && i!=y){
				for (int j = 0; j != n; ++j){
					matrix[j][i] = 0;
				}
			}
		}
		
		for (int i = 0; i != n; ++i){
			if (!matrix[i][y] && i != x){
				for (int j = 0; j != m; ++j){
					matrix[i][j] = 0;
				}
			}
		}

		for (int i = 0; i != m; ++i)
			matrix[x][i] = 0;
		for (int j = 0; j != n; ++j)
			matrix[j][y] = 0;

	}
};