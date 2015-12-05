class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<bool> f(s.length() + 1, false);
		vector<vector<bool> > prev(s.length() + 1, vector<bool>(s.length()));
		f[0] = true;
		for (size_t i = 1; i <= s.length(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
					f[i] = true;
					prev[i][j] = true;
				}
			}
		}
		vector<string> result;
		vector<string> path;
		gen_path(s, prev, s.length(), path, result);
		return result;
	}

private:
	void gen_path(const string &s, const vector<vector<bool> > &prev, int cur, vector<string> &path, vector<string> &result) {
		if (cur == 0) {
			string tmp;
			for (auto iter = path.crbegin(); iter != path.crend(); ++iter)
				tmp += *iter + " ";
				tmp.erase(tmp.end() - 1);
				result.push_back(tmp);
		}
		for (size_t i = 0; i < s.size(); ++i) {
			if (prev[cur][i]) {
				path.push_back(s.substr(i, cur - i));
				gen_path(s, prev, i, path, result);
				path.pop_back();
			}
		}
	}
};



//大的数据集超时

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