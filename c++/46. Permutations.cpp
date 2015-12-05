class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int>> res;

		permute(res, num, 0, num.size());

		return res;
	}

	void permute(vector<vector<int>> &res, vector<int> &num, int pos, int n){
		if (pos == n){
			res.push_back(num);
			return;
		}

		for (int i = pos; i != n; ++i){
			swap(num[pos], num[i]);
			permute(res, num, pos + 1, n);
			swap(num[pos], num[i]);
		}
	}
};
