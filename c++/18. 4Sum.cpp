class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		
		vector<vector<int>> res;
		if (num.size()<4){
			return res;
		}
		sort(num.begin(), num.end());
		unordered_map<int, vector<pair<int, int>>> cache;

		for (int i = 0; i + 1 < num.size(); ++i){
			for (int j = i + 1; j < num.size(); ++j){
				cache[num[i] + num[j]].push_back(pair<int, int>(i, j));
			}
		}

		for (int i = 0; i < num.size(); ++i){
			for (int j = i + 1; j < num.size(); ++j){
				int cur = target - (num[i] + num[j]);
				if (cache.find(cur) == cache.end()){
					continue;
				}
				auto vec = cache[cur];

				for (auto position : vec){
					if (position.second >= i){
						continue;
					}
					res.push_back({ num[position.first], num[position.second], num[i], num[j] });
				}

			}
		}

		sort(res.begin(), res.end());

		res.erase(unique(res.begin(), res.end()), res.end());

		return res;

	}
};