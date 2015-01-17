






class Solution {
public:
	int minDistance(string word1, string word2) {
		int n1 = word1.size(), n2 = word2.size();
		vector<vector<int>> f(n1 + 1, vector<int>(n2 + 1, 0));

		for (int i = 0; i != n1 + 1; ++i){
			f[i][0] = i;
		}
		for (int i = 0; i != n2 + 1; ++i){
			f[0][i] = i;
		}

		for (int i = 1; i != n1 + 1; ++i){
			for (int j = 1; j != n2 + 1; ++j){
				if (word1[i-1] == word2[j-1]){
					f[i][j] = f[i - 1][j - 1];
				}
				else{
					int mn = min(f[i - 1][j], f[i][j - 1]);
					f[i][j] = 1 + min(f[i - 1][j - 1], mn);
				}

			}
		}
		
		return f[n1][n2];
	}
};
