
/*

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

*/


class Solution {
public:
	int minCut(string s) {
		unsigned n = s.size();
		if(n == 0 || n == 1)
			return 0;

		vector<vector<bool>> f(n, vector<bool>(n, false));
		vector<int> cut_num(n+1, 0);	//n个字符需要最多需要多少次切割;
		for(unsigned i = 0; i <=n; ++i){
			cut_num[i] = i-1;
		}
		
		for(unsigned i = 0; i < n; ++i){
			for(int j = i; j >= 0; --j){
				if(s[i] == s[j] && (i-j<2 || f[i-1][j+1])){
					f[i][j] = true;
					cut_num[i+1] = min(cut_num[i+1], cut_num[j] +1);
				}
			}

		}
		return cut_num[n];
	}

};