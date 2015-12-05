
/*

Distinct Subsequences Total Accepted: 18779 Total Submissions: 75114 My Submissions Question Solution 
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.


*/


class Solution {
public:
	int numDistinct(string S, string T) {
		swap(S, T);
		unsigned n = S.size(), m = T.size();

		if(n == 0)
			return 1;
		if(m == 0)
			return 0;
		vector<vector<int>> f(n+1, vector<int>(m + 1, 0));
		for(int i = 0; i != n; ++i){
			for(int j = 0; j != m; ++j){
				if(S[i] == T[j]){
					if(i == 0)
						f[i+1][j+1] = f[i+1][j] + 1;
					else
						f[i+1][j+1] = f[i+1][j] + f[i][j];

				}
				else
					f[i+1][j+1] = f[i+1][j];
			}
		}

		return f[n][m];
	}
};
