class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int> &num){

		if (num.size() == 0){
			return vector<vector<int>>();
		}

		sort(num.begin(), num.end());

		vector<vector<int>> res;
		permuteUnique(res, num, 0, num.size());

		return res;
	}

	void permuteUnique(vector<vector<int>> &res, vector<int> &num, int pos, int n){
		if (pos == n){
			res.push_back(num);
			return;
		}
		unordered_set<int> visited;
	
		permuteUnique(res, num, pos + 1, n);
		visited.insert(num[pos]);
		for (int i = pos + 1; i != n; ++i){
			if (visited.find(num[i]) == visited.end()){
				visited.insert(num[i]);
				swap(num[pos], num[i]);
				permuteUnique(res, num, pos + 1, n);
				swap(num[pos], num[i]);
			}
		}
	}
};
