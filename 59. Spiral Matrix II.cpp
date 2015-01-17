class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		int val = 1;
		vector<vector<int>> res(n, vector<int>(n, 0));

		for (int i = 0; i < n / 2; ++i){
			int x1 = i, y1 = i, x2 = n - 1 - i, y2 = n - 1 - i;
			int length = n - 2 * i - 1;
			for (int i = 0; i < length; ++i){
				res[x1][y1 + i] = val++;
			}
			for (int i = 0; i < length; ++i){
				res[x1 + i][y2] = val++;
			}
			for (int i = 0; i < length; ++i){
				res[x2][y2 - i] = val++;
			}
			for (int i = 0; i < length; ++i){
				res[x2 - i][y1] = val++;
			}
		}
		if (n&1){
			res[(n - 1) / 2][(n - 1) / 2] = val;
		}
		return res;
	}
};