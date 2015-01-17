class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		if (matrix.empty()){
			return vector<int>();
		}
		int m = matrix.size(), n = matrix[0].size();

		vector<int> ret(n*m);
		int pos = 0;

		for (int level = 0; level < (m + 1) / 2 && level < (n + 1) / 2; ++level){
			int x1 = level, y1 = level, x2 = m - 1 - level, y2 = n - 1 - level;
			int wide = n - 2 * level, hgt = m - 2 * level;
			if (x1 == x2 && y1 == y2){
				ret[pos] = matrix[x1][y1];
				break;
			}
			if (x1 == x2){
				for (int i = 0; i != wide; ++i){
					ret[pos++] = matrix[x1][y1 + i];
				}
				break;
			}
			if (y1 == y2){
				for (int i = 0; i != hgt; ++i){
					ret[pos++] = matrix[x1 + i][y1];
				}
				break;
			}
			for (int i = 0; i < wide - 1; ++i){
				ret[pos++] = matrix[x1][y1 + i];
			}
			for (int i = 0; i < hgt - 1; ++i){
				ret[pos++] = matrix[x1 + i][y2];
			}
			for (int i = 0; i < wide - 1; ++i){
				ret[pos++] = matrix[x2][y2 - i];
			}
			for (int i = 0; i < hgt - 1; ++i){
				ret[pos++] = matrix[x2 - i][y1];
			}
		}

		return ret;
	}
};