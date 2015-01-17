class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		unordered_map<string, vector<string>> group;
		for (int i = 0; i != strs.size(); ++i){
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			group[tmp].push_back(strs[i]);
		}

		vector<string> ret;

		for (auto iter = group.begin(); iter != group.end(); ++iter){
			if (iter->second.size() > 1){
				ret.insert(ret.end(), iter->second.begin(), iter->second.end());
			}
		}
		return ret;

	}
		
};