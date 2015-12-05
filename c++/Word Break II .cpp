/*

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

超时!

*/





class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<string> res;
		unsigned n = s.size();
		if(n == 0)
			return res;
		vector<vector<bool>> f(n+1, vector<bool>(n+1, false));
		vector<bool> g(n+1, false);
		g[0] = true;

		for (int i = 0; i != n+1; ++i)
		{
			string cur_str = s.substr(0, i);
			for(int j = 0; j <= i; ++j){
				if(i == 0){
					f[i][j] = true;
				}else{
					f[i][j] = g[j] && (dict.find(cur_str.substr(j)) != dict.end());
					if(f[i][j])
						g[i] = true;
				}
			}
		}
		vector<string> path;
		dfs(f, n, 0, res, path, s);
		return res;
	}

	void dfs(vector<vector<bool>> &f, unsigned n, unsigned index, vector<string> &res, vector<string> path, string &s){
		if(index == n){
			res.push_back(vector_to_str(path));
			return;
		}
		for(int i = index + 1; i <= n; ++i){
			if (f[i][index])
			{
				path.push_back(s.substr(index, i-index));
				dfs(f, n, i, res, path, s);
				path.pop_back();
			}
		}
	}


	string vector_to_str(vector<string> &input){
		string res = "";
		int n = input.size();
		for(int i = 0; i != n; ++i){
			res.append(input[i]);
			if(i != n-1)
				res.append(" ");
		}
		return res;
	}

};