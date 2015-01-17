
class Solution {
public:
	vector<string> phone;
	vector<string> letterCombinations(string digits) {
		phone = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> res;
		dfs(res, digits, 0, "");

		return res;
	}

	void dfs(vector<string> &res, string &digits, int pos, string cur_val){
		if (pos == digits.size()){
			res.push_back(cur_val);
			return;
		}

		string candicate = phone[digits[pos] - '0'];
		int n = candicate.size();

		for (int i = 0; i != n; ++i){
			string tmp = cur_val + candicate.substr(i, 1);
			dfs(res, digits, pos + 1, tmp);
		}
	}
};