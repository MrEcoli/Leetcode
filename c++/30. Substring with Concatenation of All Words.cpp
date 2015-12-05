

class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		int wordlength = L.front().size();
		int targetlength = L.size()*wordlength;

		vector<int> ret;

		if (S.size() < targetlength){
			return ret;
		}

		unordered_map<string, int> WordCount;
		for (string s: L){
			WordCount[s]++;
		}

		for (int i = 0; i < S.size(); ++i){
			unordered_map<string, int> CurMap(WordCount);
			for (int j = i; j < S.size() && j < i + targetlength; j += wordlength){
				string cur_str = S.substr(j, wordlength);
				auto pos = CurMap.find(cur_str);
				if (pos == CurMap.end() || pos->second == 0){
					break;
				}
				else if (--pos->second == 0) {
					CurMap.erase(pos);
				}
			}
			if (CurMap.size() == 0){
				ret.push_back(i);
			}
		}
		return ret;
	}
};
