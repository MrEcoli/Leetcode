
class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		unordered_map<char, int> position;

		int last = 0;

		int max_length = 0;

		for (int i = 0; i != s.size(); ++i){
			auto iter = position.find(s[i]);
			if (iter == position.end() || iter->second < last){
				max_length = max(i - last + 1, max_length);
				position[s[i]] = i;
			}
			else{
				last = iter->second + 1;
				iter->second = i;
			}
		}

		return max_length;
	}
};