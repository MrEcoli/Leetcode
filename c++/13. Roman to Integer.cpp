class Solution {
public:
	int romanToInt(string s) {
		char roman[] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
		int arr[] = { 1000, 500, 100, 50, 10, 5, 1 };

		unordered_map<char, int> map;

		for (int i = 0; i != sizeof(roman) / sizeof(char); ++i){
			map[roman[i]] = i;
		}

		int res = 0;

		for (int i = 0; i != s.size()-1; ++i){
			int pos = map[s[i]];
			int nxt = map[s[i + 1]];

			if (nxt < pos){
				res -= arr[pos];
			}
			else{
				res += arr[pos];
			}
		}

		res += arr[map[s.back()]];
		return res;
	}
};