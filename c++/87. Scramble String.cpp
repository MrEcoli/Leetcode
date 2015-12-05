








//深搜，会超时。

class Solution {
	typedef string::iterator iter;
public:
	bool isScramble(string s1, string s2) {
		if (s1.size() != s2.size()){
			return false;
		}

		return isScramble(s1.begin(), s1.end(), s2.begin(), s2.end());

	}

	bool isScramble(iter s1_first, iter s1_last, iter s2_first, iter s2_last){
		int sz = s1_last - s1_first;

		if (sz == 1 ){
			return *s1_first == *s2_first;
		}

		for (int i = 1; i < sz; ++i){
			if ((isScramble(s1_first, s1_first+i, s2_first, s2_first +i) && isScramble(s1_first+i, s1_last, s2_first + i, s2_last)) || (isScramble(s1_first, s1_first+i, s2_last -i, s2_last) && isScramble(s1_first+i, s1_last, s2_first, s2_last - i))){
				return true;
			}
		}
		return false;
		
	}

};




//3维动态规划，AC

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.size() != s2.size()){
			return false;
		}
		
		const int n = s1.size();

		vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(n, vector<int>(n, 0)));

		for (int i = 0; i != n; ++i){
			for (int j = 0; j != n; ++j){
				if (s1[i] == s2[j]){
					f[1][i][j] = 1;
				}
			}
		}

		for (int m = 1; m <= n; ++m){
			for (int i = 0; i + m <= n; ++i){
				for (int j = 0; j + m <= n; ++j){
					for (int k = 1; k < m; ++k){
						if ((f[k][i][j] && f[m-k][i+k][j+k])|| (f[k][i][j+m-k] && f[m-k][i+k][j])){
							f[m][i][j] = 1;
							break;
						}
					}
				}
			}
		}
		return f[n][0][0];
	}

};